#include <iostream>
//#include "Matrix.h"

class AbstractMatrix
{
public:
    virtual ~AbstractMatrix() {};
    virtual int getRows() = 0;
    virtual int getCols() = 0;
    virtual void operator+=(const AbstractMatrix& other) = 0;
    virtual AbstractMatrix& operator-(AbstractMatrix& other) = 0;
    virtual AbstractMatrix& operator*(AbstractMatrix& other) = 0;

};

template <typename T>
class Matrix : public AbstractMatrix
{
public:
    Matrix();
    Matrix(T** arr, int cols, int rows);
    //Matrix(int rows, int cols, T& element);

    virtual int getRows() override { return rows_; }
    virtual int getCols() override { return cols_; }

    virtual void operator+=(const AbstractMatrix& other) override
    {
        const Matrix<T>& otherMatrix = static_cast<const Matrix&>(other);

        for (size_t i = 0; i < rows_; i++)
        {
            for (size_t j = 0; j < cols_; j++)
            {
                matrix_[i][j] += otherMatrix.matrix_[i][j];
            }
        }
    }

    virtual AbstractMatrix& operator-(AbstractMatrix& other) override;
    virtual AbstractMatrix& operator*(AbstractMatrix& other) override;

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

template <typename T>
Matrix<T>::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

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

//template <typename T>
//Matrix<T>::Matrix(int rows, int cols, T& element)
//{
//    for (int i = 0; i < rows_; i++)
//    {
//        for (int j = 0; j < cols_; j++)
//        {
//            matrix_[i][j] = element;
//        }
//    }
//}


//template <typename T>
//void Matrix<T>::operator+=(const AbstractMatrix& other)

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
            arr[i][j] = rand() % 10;
        }
    }

    Matrix<int> A(arr, N, N);
    A.Print();

}
