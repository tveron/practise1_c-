#include "Vector.h"
#include "Matrix.h"
#include "Base.h"
#include <cstddef>
#include <math.h>

using namespace std;
namespace mat_vec{
    Vector::Vector ():
            _size(0),
            _data(nullptr) {}

    // Конструирует вектор размера size со значениями value
    Vector::Vector(std::size_t size, double value) :
            _size(size),
            _data(new double[_size]) {
        for (int i = 0; i < _size; i++) {
            _data[i] = value;
        }
    }

    // Умножение всех элементов вектора на число слева (k * v)
    Vector operator*(double k, const Vector &v) {
        Vector r = Vector(v._size);
        for(int i = 0; i < v._size; i++){
            r._data[i] = k * v._data[i];
        }
        return r;
    }

    // Конструктор копирования
    Vector::Vector(const Vector &src) {
        Vector _vecCopy(*this);
        for (int i = 0; i < _size; i++) {
            _vecCopy._data[i] = src._data[i];
        }
    }
    // Оператор присваивания
    Vector & Vector::operator=(const Vector &rhs){
        Vector resultT(rhs._size, 0);
        for (int i = 0; i < _size; i++) {
            resultT._data[i] = rhs._data[i];
        }
        return resultT;
    }


    // Деструктор
    Vector::~Vector() {
        delete[] _data;
    }

    // Возвращает размер вектора
    std::size_t Vector::size() const{
        return _size;
    }

    // Доступ к n-му элементу вектора
    double Vector::operator[](std::size_t n) const{
        return _data[n];
    }
    double & Vector::operator[](std::size_t n){
        return _data[n];
    }

    // L2 норма вектора
    double Vector::norm() const{}

    // Возвращает новый вектор, полученный нормализацией текущего (this)
    Vector Vector::normalized() const{}

    // Нормализует текущий вектор
    void Vector::normalize(){}

    // Поэлементное сложение векторов
    Vector Vector::operator+(const Vector &rhs) const{
        Vector result(rhs._size, 0);
        for (int i = 0; i < rhs._size; i++) {
            result._data[i] = _data[i] + rhs._data[i];
        }
        return result;
    }


    Vector & Vector::operator+=(const Vector &rhs){
        for (int i = 0; i < rhs._size; i++) {
            _data[i] += rhs._data[i];
        }
        return *this;
    }

    // Поэлементное вычитание векторов
    Vector Vector::operator-(const Vector &rhs) const{
        Vector result(rhs._size, 0);
        for (int i = 0; i < rhs._size; i++) {
            result._data[i] = _data[i] - rhs._data[i];
        }
        return result;
    }

    Vector & Vector::operator-=(const Vector &rhs){
        for (int i = 0; i < rhs._size; i++) {
            _data[i] -= rhs._data[i];
        }
        return *this;
    }

    // Поэлементное умножение векторов
    Vector Vector::operator^(const Vector &rhs) const{
        Vector result(rhs._size, 0);
        for (int i = 0; i < rhs._size; i++) {
            result._data[i] = _data[i] * rhs._data[i];
        }
        return result;
    }

    Vector & Vector::operator^=(const Vector &rhs){
        for (int i = 0; i < rhs._size; i++) {
            _data[i] *= rhs._data[i];
        }
        return *this;
    }

    // Умножение всех элементов вектора на скаляр справа (v * k)
    Vector Vector::operator*(double k) const{
        Vector result(_size);
        for (int i = 0; i < _size; i++) {
            result._data[i] = this->_data[i] * k;
        }
        return result;
    }

    Vector & Vector::operator*=(double k){
        for (int i = 0; i < _size; i++) {
            _data[i] *= k;
        }
        return *this;
    }

    // Деление всех элементов вектора на скаляр
    Vector Vector::operator/(double k) const{
        Vector result(_size, 0);
        for (int i = 0; i < _size; i++) {
            result._data[i] = _data[i] / k;
        }
        return result;
    }
    Vector & Vector::operator/=(double k){
        for (int i = 0; i < _size; i++) {
            _data[i] /= k;
        }
        return *this;
    }

    // Умножение вектора на матрицу
    Vector Vector::operator*(const Matrix &mat) const {
        Vector result(_size);
        for (int i = 0; i < result._size; ++i) {
            result._data[i] = _data[i] * mat._data[i];
        }
        return result;
    }


    Vector & Vector::operator*=(const Matrix &mat){
        for (int i = 0; i < _size; ++i) {
            _data[i] *= mat._data[i];
        }
        return *this;
    }

    // Скалярное произведение
    double Vector::operator*(const Vector &rhs) const{}

    // Поэлементное сравнение
    bool Vector::operator==(const Vector &rhs) const{
        for (int i = 0; i < rhs._size; i++) {
            if (_data[i] != rhs._data[i])
                return false;
        }
        return true;
    }

    bool Vector::operator!=(const Vector &rhs) const{
        for (int i = 0; i < rhs._size; i++) {
            if (_data[i] != rhs._data[i])
                return true;
        }
        return false;
    }

}