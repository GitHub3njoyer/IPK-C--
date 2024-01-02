#include <iostream>
#include <array>

template <typename T, int N, int M>
class Matrix
{
private:
    std::array<std::array<T, M>, N> mat;

public:
    Matrix()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    template <typename T2>
    Matrix (T2 container) {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                mat[i][j] = container[i][j];
            }
        }
    }

    void print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::cout << mat[i][j];
            }
            std::cout << std::endl;
        }
    }
    T &get(int n, int m)
    {
        return mat[n][m];
    }

    Matrix<T, M, N> transpose()
    {
        Matrix<T, M, N> matTranspose;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matTranspose.get(j, i) = mat[i][j];
            }
        }
        return matTranspose;
    }

    Matrix<T, N, M> add(Matrix<T, N, M> addMat)
    {
        Matrix<T, N, M> matSum;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matSum.get(i, j) = mat[i][j] + addMat.get(i, j);
            }
        }
        return matSum;
    }

    Matrix<T, N, M> sub(Matrix<T, N, M> subMat)
    {
        Matrix<T, N, M> matdiff;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matdiff.get(i, j) = mat[i][j] - subMat.get(i, j);
            }
        }
        return matdiff;
    }

    template <int spaltenVonZweiterMatrix>
    Matrix <T, N, spaltenVonZweiterMatrix> multiply(Matrix <T, M, spaltenVonZweiterMatrix> mulMat)
    {
        Matrix <T, N, spaltenVonZweiterMatrix> endMat;
        for (int k = 0; k < N; k++)
        {
            for (int j = 0; j < spaltenVonZweiterMatrix; j++)
            {
                for (int i = 0; i < M; i++)
                {
                    endMat.get(k, j) += (mat[k][i] * mulMat.get(i,j));
                }
            }
        }
        return endMat;
    }
    
};