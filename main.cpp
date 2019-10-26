#define CATCH_CONFIG_MAIN
#include <iostream>
#include <complex>
#include "Catch.hpp"
#include "Vector.h"
#include "Matrix.h"
#include "Base.h"
using namespace mat_vec;

TEST_CASE("vector_access"){
Vector A(4, 13);
A[2] = 19;
REQUIRE(A[2] == 19);

double b = 14.1;
b = A[3];
REQUIRE(b == 13);
}

TEST_CASE("Умножение всех элементов вектора на число слева (k * v)"){
Vector A(5, 4);
Vector B = A * 5;
REQUIRE(B[1] == 20);
}

TEST_CASE("Возвращает размер вектора"){
Vector A(5, 5);
double_t K = A.size();
REQUIRE(K == 5);
}

TEST_CASE("Доступ к n-му элементу вектора"){
Vector A(5, 4);
A[4] = 16;
REQUIRE(A[4] == 16);
}

TEST_CASE("Поэлементное сложение векторов"){
Vector A(3, 3);
Vector B(1, 2);
Vector C = A + B;
REQUIRE(C[0] == 5);

Vector Lo(1, 2);
Vector PO(5, 3);
PO += Lo;
REQUIRE(PO[0] == 5);
}

TEST_CASE("Поэлементное вычитание векторов"){
Vector A(3, 3);
Vector B(1, 2);
Vector C = B - A;
REQUIRE(C[0] == -1);

Vector Lo(1, 2);
Vector PO(5, 3);
PO -= Lo;
REQUIRE(PO[0] == 1);
}

TEST_CASE("Поэлементное умножение векторов"){
Vector A(1, 2);
Vector L(2, 5);
Vector C = L^A;
REQUIRE(C[0] == 10);

Vector O(5, 2);
Vector I(2, 5);
O ^= I;
REQUIRE(O[0] == 10);
}

TEST_CASE("Умножение всех элементов вектора на скаляр справа (v * k)"){
Vector B(2, 5);
Vector C(2, 3);
Vector Po = B * 9;
REQUIRE(Po[1] == 45);

C *= 9;
REQUIRE(C[1] == 27);
}

TEST_CASE("Деление всех элементов вектора на скаляр"){
Vector A(2, 20);
Vector B = A / 4;
REQUIRE(B[0] == 5);

Vector C(2, 15);
C /= 3;
REQUIRE(C[1] == 5);
}

TEST_CASE("Умножение вектора на матрицу *"){
Matrix C(5, 5, 15);
Matrix D(5, 4, 15);
Vector B(5, 2);
Vector T = B * C;
REQUIRE(T[1] == 30);
}

TEST_CASE("Умножение вектора на матрицу *="){
Matrix C(5, 5, 15);
Matrix D(5, 4, 15);
Vector B(5, 2);
B *= C;
REQUIRE(B[1] == 30);
}

TEST_CASE("Поэлементное сравнение =="){
Vector A(2, 20);
Vector B(2, 20);
double F = 1;
if (A == B)
F = 0;
REQUIRE(F == 0);

Vector C(2, 20);
Vector D(2, 16);
int K = 0;
if (C == D)
K = 1;
REQUIRE(K == 0);
}

TEST_CASE("Поэлементное сравнение !="){
Vector A(2, 20);
Vector B(2, 20);
double R = 1;
if (A != B)
R = 0;
REQUIRE(R == 1);

Vector C(2, 20);
Vector D(2, 16);
int K = 0;
if (C != D)
K = 1;
REQUIRE(K == 1);
}

TEST_CASE("Конструирует матрицу с размерами size x size, заполненную value"){
Matrix A(5, 6.0);
double K = A.get(1, 4);
REQUIRE(K == 6);
}

TEST_CASE("Возвращает матрицу с размерами rows x cols, заполненную value"){
Matrix A(5, 4, 6);
double K = A.get(1, 4);
REQUIRE(K == 6);
}

TEST_CASE("Транспонирование матрицы"){
Matrix C(5, 5, 15);
Matrix D(5, 4, 15);
Vector B(5, 2);
Matrix V = Matrix::eye(5);
Vector T = C * B;
C = C.transposed();
double K = C.get(2, 1);
REQUIRE(K == 15);
}

TEST_CASE("Возвращает пару {rows, cols} -- количество строк и столбцов матрицы"){
Matrix D(5, 4, 15);
double P = D.shape().second;
REQUIRE(P == 4);
}

TEST_CASE("Поэлементное сложение +"){
Matrix A(5, 5, 5);
Matrix B(5, 5, 2);
Matrix C = A + B;
double K = C.get(2, 1);
REQUIRE(K == 7);
}

TEST_CASE("Поэлементное сложение +=") {
Matrix A(5, 5, 1);
Matrix B(5, 5, 2);
B += A;
double K = B.get(1, 1);
REQUIRE(K == 3);
}

TEST_CASE("Поэлементное вычитание -"){
Matrix A(5, 5, 5);
Matrix B(5, 5, 2);
Matrix C = A - B;
double K = C.get(2, 1);
REQUIRE(K == 3);
}

TEST_CASE("Поэлементное вычитание -="){
Matrix A(5, 5, 1);
Matrix B(5, 5, 2);
B -= A;
double K = B.get(1, 1);
REQUIRE(K == 1);
}

TEST_CASE("Матричное умножение *"){
Matrix A(5, 5, 5);
Matrix B(5, 5, 2);
Matrix C = A*B;
double K = C.get(2, 1);
REQUIRE(K == 10);
}

TEST_CASE("Матричное умножение *="){
Matrix A(2, 2, 5);
Matrix B(2, 2, 2);
B *= A;
double K = A.get(2, 1);
REQUIRE(K == 5);
}

TEST_CASE("Умножение всех элементов матрицы на константу *"){
Matrix A(5, 5, 5);
Matrix B(1, 1, 2);
Matrix C = A*5;
double K = C.get(2, 1);
REQUIRE(K == 25);
}

TEST_CASE("Умножение всех элементов матрицы на константу *="){
Matrix A(5, 5, 5);
Matrix B(1, 1, 2);
A *= 5;
double K = A.get(2, 1);
REQUIRE(K == 25);
}

TEST_CASE("Деление всех элементов матрицы на константу /"){
Matrix A(5, 5, 15);
Matrix B(1, 1, 2);
Matrix C = A/5;
double K = C.get(2, 1);
REQUIRE(K == 3);
}

TEST_CASE("Деление всех элементов матрицы на константу /="){
Matrix A(5, 5, 15);
Matrix B(1, 1, 2);
A /= 5;
double K = A.get(2, 1);
REQUIRE(K == 3);
}

TEST_CASE("Умножение матрицы на вектор"){
Matrix C(5, 5, 15);
Vector B(5, 2);
Vector T = C * B;
REQUIRE(T[1] == 30);
}
TEST_CASE("Поэлементное сравнение матриц =="){
Matrix A(5, 5, 15);
Matrix B(5, 5, 15);
double F = 1;
if (A == B)
F = 0;
REQUIRE(F == 0);

Matrix C(5, 5, 15);
Matrix D(1, 1, 2);
int K = 1;
if (C == D)
K = 0;
REQUIRE(K == 1);
}

TEST_CASE("Поэлементное сравнение матриц !="){
Matrix A(5, 5, 15);
Matrix B(5, 5, 15);
double F = 1;
if (A != B)
F = 0;
REQUIRE(F == 1);

Matrix C(5, 5, 15);
Matrix D(1, 1, 2);
int K = 1;
if (C != D)
K = 0;
REQUIRE(K == 0);
}