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

    Matrix();


    Matrix(int r, int c);


    Matrix(const Matrix& other);

   
    Matrix& operator=(const Matrix& other);

   
    Matrix& operator=(double value);

    RowProxy operator[](int i);
    ConstRowProxy operator[](int i) const;

   
    Matrix operator+(const Matrix& other) const;

   
    ~Matrix();
   void Input(std::istream& in = std::cin);

    
    void Print(std::ostream& out = std::cout) const;
};

#endif 
