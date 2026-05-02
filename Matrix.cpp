#include "Matrix.h"

void Matrix::ensureAllocated() const {
    if (rows < 0 || cols < 0) {
        throw std::logic_error("Matrix: invalid internal size");
    }
    if ((rows == 0 || cols == 0) && data != nullptr) {
        throw std::logic_error("Matrix: invalid internal state (data must be nullptr for 0 size)");
    }
    if (rows > 0 && cols > 0 && data == nullptr) {
        throw std::logic_error("Matrix: memory not allocated");
    }
}

void Matrix::checkRowIndex(int i) const {
    if (i < 0 || i >= rows) {
        throw std::out_of_range("Matrix: row index out of range");
    }
}

void Matrix::checkColIndex(int j) const {
    if (j < 0 || j >= cols) {
        throw std::out_of_range("Matrix: col index out of range");
    }
}

void Matrix::allocate(int r, int c) {
    if (r < 0 || c < 0) {
        throw std::invalid_argument("Matrix: rows/cols must be non-negative");
    }

    rows = r;
    cols = c;
    maxRows = r;
    maxCols = c;

    if (rows == 0 || cols == 0) {
        data = nullptr;
        return;
    }

    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = nullptr;
    }
    try {
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols]{};
        }
    } catch (...) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
        rows = cols = maxRows = maxCols = 0;
        throw;
    }
}

void Matrix::deallocate() noexcept {
    if (!data) {
        rows = cols = maxRows = maxCols = 0;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
    rows = cols = maxRows = maxCols = 0;
}

Matrix::Matrix() : data(nullptr), rows(0), cols(0), maxRows(0), maxCols(0) {}

Matrix::Matrix(int r, int c) : data(nullptr), rows(0), cols(0), maxRows(0), maxCols(0) {
    allocate(r, c);
}

Matrix::Matrix(const Matrix& other)
    : data(nullptr), rows(0), cols(0), maxRows(0), maxCols(0) {
    allocate(other.rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data ? other.data[i][j] : 0.0;
        }
    }
    maxRows = other.maxRows;
    maxCols = other.maxCols;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    Matrix tmp(other);
    // swap вручну, щоб не тягнути <utility>
    double** tData = data; data = tmp.data; tmp.data = tData;
    int tRows = rows; rows = tmp.rows; tmp.rows = tRows;
    int tCols = cols; cols = tmp.cols; tmp.cols = tCols;
    int tMaxR = maxRows; maxRows = tmp.maxRows; tmp.maxRows = tMaxR;
    int tMaxC = maxCols; maxCols = tmp.maxCols; tmp.maxCols = tMaxC;
    return *this;
}

Matrix& Matrix::operator=(double value) {
    ensureAllocated();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = value;
        }
    }
    return *this;
}

double& Matrix::RowProxy::operator[](int j) {
    m_.ensureAllocated();
    m_.checkRowIndex(r_);
    m_.checkColIndex(j);
    return m_.data[r_][j];
}

const double& Matrix::ConstRowProxy::operator[](int j) const {
    m_.ensureAllocated();
    m_.checkRowIndex(r_);
    m_.checkColIndex(j);
    return m_.data[r_][j];
}

Matrix::RowProxy Matrix::operator[](int i) {
    ensureAllocated();
    checkRowIndex(i);
    return RowProxy(*this, i);
}

Matrix::ConstRowProxy Matrix::operator[](int i) const {
    ensureAllocated();
    checkRowIndex(i);
    return ConstRowProxy(*this, i);
}

Matrix Matrix::operator+(const Matrix& other) const {
    ensureAllocated();
    other.ensureAllocated();

    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix: operator+ requires same dimensions");
    }

    Matrix res(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return res;
}

Matrix::~Matrix() {
    deallocate();
}

void Matrix::Input(std::istream& in) {
    int r, c;
    in >> r >> c;
    deallocate();
    allocate(r, c);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            in >> data[i][j];
        }
    }
}

void Matrix::Print(std::ostream& out) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            out << std::setw(10) << data[i][j];
        }
        out << '\n';
    }
}

