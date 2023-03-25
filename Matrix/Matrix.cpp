#include <iostream>
//#include "Matrix.h"

template <typename A>
class AbstractMatrix
{
public:
    virtual int getRows() = 0;
    virtual int getCols() = 0;
    virtual void operator+=(const AbstractMatrix<A>& other) = 0;
    virtual void operator-=(const AbstractMatrix<A>& other) = 0;
    virtual AbstractMatrix<A>& operator=(const AbstractMatrix<A>& other) = 0;
    virtual void operator*=(A other) = 0;
};

template <typename T>
class Matrix : public AbstractMatrix<T>
{
public:
    Matrix();
    Matrix(const Matrix<T>& other);
    Matrix(T** arr, int cols, int rows);
    Matrix(T element, int rows, int cols);
    ~Matrix<T>();
    

    virtual int getRows() override { return rows_; }
    virtual int getCols() override { return cols_; }

    virtual void operator+=(const AbstractMatrix<T>& other) override;
    virtual void operator-=(const AbstractMatrix<T>& other) override;
    virtual AbstractMatrix<T>& operator=(const AbstractMatrix<T>& other) override;
    virtual void operator*=(T other) override;

    void Print()
    {
        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                std::cout << matrix_[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
private:


    int cols_;
    int rows_;
    T** matrix_;
};


//constructor
template <typename T>
Matrix<T>::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new T* [rows_];
    for (size_t i = 0; i < rows_; i++)
    {
        matrix_[i] = new T[cols_];
        for (size_t j = 0; j < cols_; j++)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(T** arr, int rows, int cols) : rows_(rows), cols_(cols)
{
    matrix_ = new T * [rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i] = new T[cols_];
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = arr[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(T element, int rows, int cols): rows_(rows), cols_(cols)
{
    matrix_ = new T * [rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i] = new T[cols_];
    }


    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = element;
        }
    }
}

//destructor
template <typename T>
Matrix<T>::~Matrix()
{
    for (size_t i = 0; i < rows_; i++)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

template <typename T>
void Matrix<T>::operator+=(const AbstractMatrix<T>& other)
{
    const Matrix<T>& otherMatrix = static_cast<const Matrix<T>&>(other);

    for (size_t i = 0; i < rows_; i++)
    {
        for (size_t j = 0; j < cols_; j++)
        {
            matrix_[i][j] += otherMatrix.matrix_[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::operator-=(const AbstractMatrix<T>& other)
{
    const Matrix<T>& otherMatrix = static_cast<const Matrix<T>&>(other);

    for (size_t i = 0; i < rows_; i++)
    {
        for (size_t j = 0; j < cols_; j++)
        {
            matrix_[i][j] -= otherMatrix.matrix_[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::operator*=(T other)
{
    for (size_t i = 0; i < rows_; i++)
    {
        for (size_t j = 0; j < cols_; j++)
        {
            matrix_[i][j] *= other;
        }
    }
}

template <typename T>
AbstractMatrix<T>& Matrix<T>::operator=(const AbstractMatrix<T>& other)
{
    if (matrix_ != nullptr)
    {
        for (int i = 0; i < rows_; i++)
        {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }

    const Matrix<T> oth = static_cast<const Matrix<T>&>(other);
    
    rows_ = oth.rows_;
    cols_ = oth.cols_;

    matrix_ = new T* [rows_];
    for (int i = 0; i < rows_; i++)
    {
        matrix_[i] = new T[cols_];
    }

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            matrix_[i][j] = oth.matrix_[i][j];
        }
    }

    return *this;
}

int main()
{
    int N = 3;

    int** arr = new int* [N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = rand()%10;
        }
    }

    Matrix<int> A(arr,N,N);
    Matrix<int> B(arr, N, N);
    Matrix<int> C(2, N, N);
    
    A.Print();
    B.Print();
    C.Print();

    C *= 5;
    C.Print();
    A.Print();
    B.Print();

    Matrix<int> G = A;
    G.Print();

    G = C;

}

