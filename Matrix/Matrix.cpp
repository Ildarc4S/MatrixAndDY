#include <iostream>

template <typename T> 
class Matrix
{
public:
    Matrix(T** arr, int cols, int rows){}

    void Print()
    {
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
private:


    int _cols;
    int _rows;
    T** _matrix;
};

template <typename T>
Matrix<T>::Matrix(T** arr, int cols, int rows) :_rows(rows), _cols(cols)
{
    _matrix = new T * [_rows];
    for (int i = 0; i < _rows; i++)
    {
        _matrix[i] = new T[_cols];
    }

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _matrix[i][j] = arr[i][j];
        }
    }
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
    A.Print();

}
