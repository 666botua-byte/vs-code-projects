#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

class Matrix {
private:
    void allocate(int r, int c);
    void deallocate() noexcept;

    void ensureAllocated() const;
    void checkRowIndex(int i) const;
    void checkColIndex(int j) const;

    class RowProxy {
    public:
        RowProxy(Matrix& m, int r) : m_(m), r_(r) {}
        double& operator[](int j);
    private:
        Matrix& m_;
        int r_;
    };

    class ConstRowProxy {
    public:
        ConstRowProxy(const Matrix& m, int r) : m_(m), r_(r) {}
        const double& operator[](int j) const;
    private:
        const Matrix& m_;
        int r_;
    };

public:
    double** data;
    int rows;
    int cols;
    int maxRows;
    int maxCols;

    // Конструктор без параметрів
    Matrix();

    // Конструктор з параметрами
    Matrix(int r, int c);

    // Конструктор копіювання
    Matrix(const Matrix& other);

    // Оператор присвоєння (щоб копіювання було безпечним)
    Matrix& operator=(const Matrix& other);

    // Присвоєння всім елементам одного значення
    Matrix& operator=(double value);

    // Доступ до елементів у вигляді M[i][j] (з перевіркою меж)
    RowProxy operator[](int i);
    ConstRowProxy operator[](int i) const;

    // Додавання двох матриць однакового розміру
    Matrix operator+(const Matrix& other) const;

    // Деструктор
    ~Matrix();

    // Введення даних
    void Input(std::istream& in = std::cin);

    // Виведення даних
    void Print(std::ostream& out = std::cout) const;
};

#endif // MATRIX_H

