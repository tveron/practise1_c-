#include "Matrix.h"
#include "Vector.h"
#include <cmath>
#include "Base.h"
#include <cstddef>

using namespace std;

namespace mat_vec{

    Matrix::Matrix():
            _size(0),
            _rows(0),
            _cols(0),
            _data(nullptr){}

    // Конструирует матрицу с размерами size x size, заполненную value
    Matrix::Matrix(size_t size, double value) :
            Matrix(size, size, value){}

    // Возвращает матрицу с размерами rows x cols, заполненную value
    Matrix::Matrix(size_t rows, size_t cols, double value) {

        _rows = rows;
        _cols = cols;
        _size = _rows * _cols;
        _data = new double [_size];
        for (int i = 0; i < _size; i++){
            _data[i] = value;
        }
    }

    // Возвращает единичную матрицу
    Matrix Matrix::eye(size_t size){
        Matrix r(size, size, 1.0);
        return r;
    }

    // Конструктор копирования;
    Matrix::Matrix(const Matrix &src) {
        _rows = src._rows;
        _cols = src._cols;
        _size = src._size;
        _data = src._data;
    }

    // Оператор присваивания
    Matrix &Matrix::operator=(const Matrix &rhs) {
        Matrix P = Matrix(rhs._size);
        for(int i = 0; i < _size; i++){
            P._data[i] = rhs._data[i];
        }
        return *this;
    }

    // Деструктор
    Matrix::~Matrix(){
        delete []_data;
    }

    // Изменяет ширину и высоту матрицы, не изменяя при этом
    // порядок следования элементов от левого верхнего к правому нижнему:
    //
    // [1 2 3] -> [1 2]
    // [4 5 6] -> [3 4]
    //            [5 6]
    void reshape(size_t rows, size_t cols){}

    // Возвращает пару {rows, cols} -- количество строк и столбцов матрицы
    std::pair<size_t, size_t> Matrix::shape() const{
        std::pair<size_t, size_t> PairCH(_rows, _cols);
        return PairCH;
    }

    // Возвращает элемент на позиции [row, col]
    double Matrix::get(size_t row, size_t col) const{
        return _data[row * col];
    }

    // Поэлементное сложение
    Matrix Matrix::operator+(const Matrix &rhs) const{
        Matrix result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] + rhs._data[i];
        }
        return result;
    }

    Matrix & Matrix::operator+=(const Matrix &rhs){
        // assert(this->_rows() == rhs.rows() && this->cols() == rhs.cols());
        int length = _rows * _cols;
        for (int i = 0; i < length; ++i) {
            _data[i] += rhs._data[i];
        }
        return *this;
    }

    // Поэлементное вычитание
    Matrix Matrix::operator-(const Matrix &rhs) const{
        Matrix result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] - rhs._data[i];
        }
        return result;
    }

    Matrix & Matrix::operator-=(const Matrix &rhs){
        for (int i = 0; i < _size; ++i) {
            _data[i] -= rhs._data[i];
        }
        return *this;
    }

    // Матричное умножение
    Matrix Matrix::operator*(const Matrix &rhs) const{
        Matrix result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] * rhs._data[i];
        }
        return result;
    }

    Matrix & Matrix::operator*=(const Matrix &rhs){
        int length = _rows *_cols;
        for (int i = 0; i < length; ++i) {
            _data[i] *= rhs._data[i];
        }
        return *this;
    }

    // Умножение всех элементов матрицы на константу
    Matrix Matrix::operator*(double k) const{
        Matrix result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] * k;
        }
        return result;
    }

    Matrix & Matrix::operator*=(double k){
        for (int i = 0; i < _size; ++i) {
            _data[i] *= k;
        }
        return *this;
    }

    // Деление всех элементов матрицы на константу
    Matrix Matrix::operator/(double k) const{
        Matrix result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] / k;
        }
        return result;
    }


    Matrix & Matrix::operator/=(double k){
        for (int i = 0; i < _size; ++i) {
            _data[i] /= k;
        }
        return *this;
    }

    // Возвращает новую матрицу, полученную транспонированием текущей
    Matrix Matrix::transposed() const{
        Matrix trans(_cols, _rows, 0);
        for(int i = 0; i < _cols; ++i) {
            for(int j = 0; j < _rows; ++j) {
                trans._data[i * _rows + j] = _data[j * _cols + i];
            }
        }
        return trans;
    }

    // Транспонирует текущую матрицу
    void transpose(){
    }

    // Определитель
    double Matrix::det() const{}

    // Обратная матрица
    Matrix Matrix::inv() const{}

    // Умножение матрицы на вектор
    Vector Matrix::operator*(const Vector &vec) const{
        Vector result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] * vec._data[i];
        }
        return result;
    }

    // Поэлементное сравнение
    bool Matrix::operator==(const Matrix &rhs) const {
        if (_rows != rhs._rows || _cols != rhs._cols) {
            return false;
        }
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++) {
                if (get(i, j) != rhs.get(i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool Matrix::operator!=(const Matrix &rhs) const{
        return !(*this == rhs);
    }
}