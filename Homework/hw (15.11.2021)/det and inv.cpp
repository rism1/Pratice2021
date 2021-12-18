#include <iostream>
#include <vector>

/*
1. Написать функцию, которая вычисляет определитель квадратной матрицы произвольной размерности. double det(double** M, int size);
2. Написать функцию, которая вычисляет обратную квадратной матрицы произвольной размерности. double** inv(double** M, int size);
*/


using namespace std;

template <typename T>
T** createMatrix(int rows, int columns) {
    if (rows < 1) throw "Number of rows must be positive";
    if (columns < 1) throw "Number of columns must be positive";

    T** M = new T * [rows];
    for (int i = 0; i < rows; ++i)
        M[i] = new T[columns];
    return M;
}

double det(double** matrix, int demension) {

    for (int col = 0; col < demension; col++) {
        bool non_zero_row_found = false;
        for (int row = col; row < demension; ++row) {
            if (matrix[row][col]) {
                if (row != col)
                {
                    swap(matrix[row], matrix[col]);
                    
                }
                non_zero_row_found = true;
                break;
            }
        }

        if (!non_zero_row_found) {
            return 0;
        }

        for (int row = col + 1; row < demension; row++) {
            while (true) {
                int del = matrix[row][col] / matrix[col][col];
                for (int j = col; j < demension; j++) {
                    matrix[row][j] -= del * matrix[col][j];
                }
                if (matrix[row][col] == 0)
                {
                    break;
                }
                else
                {
                    swap(matrix[row], matrix[col]);
                }
            }
        }
    }

    int long res = 1;

    for (int i = 0; i < demension; ++i) {
        res *= matrix[i][i];
    }
    return abs(res);
}

void cofactor(double** mat, double** mat_temp, int i_row, int i_col, int demension)
{
	int i = 0, j = 0;

	for (int row = 0; row < demension; row++)
	{
		for (int col = 0; col < demension; col++)
		{
			if (row != i_row && col != i_col)
			{
				mat_temp[i][j++] = mat[row][col];
				if (j == demension - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

void adjoint(double** mat, double** mat_adjoint, int demension)
{
	if (demension == 1)
	{
        mat_adjoint[0][0] = 1;
		return;
	}

	int sign = 1;
    double** mat_temp = createMatrix<double>(demension, demension);

	for (int i = 0; i < demension; i++)
	{
		for (int j = 0; j < demension; j++)
		{
			cofactor(mat, mat_temp, i, j, demension);

			sign = ((i + j) % 2 == 0) ? 1 : -1;

            mat_adjoint[j][i] = (sign) * (det(mat_temp, demension - 1));
		}
	}
}

bool inv(double** mat, double** mat_inverse, int demension)
{
	double det_value = det(mat, demension);
	if (det_value == 0)
	{
		cout << "Matrix is invertible";
		return false;
	}

	double** mat_adjoint = createMatrix<double>(demension, demension);
	adjoint(mat, mat_adjoint, demension);

	for (int i = 0; i < demension; i++)
		for (int j = 0; j < demension; j++)
			mat_inverse[i][j] = mat_adjoint[i][j] / det_value;

	return true;
}



int main()
{
    int n = 3;
    
    double** mat = createMatrix<double>(n, n);
    
    mat[0][0] = 6;
    mat[0][1] = 12;
    mat[0][2] = 2.5;

    mat[1][0] = 10;
    mat[1][1] = 12;
    mat[1][2] = 3;
    
    mat[2][0] = 12;
    mat[2][1] = 12;
    mat[2][2] = 34;

    double** mat_inverse = createMatrix<double>(n, n);

    double det_value = det(mat, n);
    inv(mat, mat_inverse, n);


    cout << "Determinant: " << det_value << "\n\n";
    cout << "Inverse:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat_inverse[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}