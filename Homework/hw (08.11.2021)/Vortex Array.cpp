#include <iostream>

using namespace std;
/*
	Заполнить массив nxm (размеры вводит пользователь) числами от 1 до n*m по спирали (улитке).
*/

template <typename T>
T** createMatrix(int rows, int columns) {
    if (rows < 1) throw "Number of rows must be positive";
    if (columns < 1) throw "Number of columns must be positive";

    T** M = new T * [rows];
    for (int i = 0; i < rows; ++i)
        M[i] = new T[columns];
    return M;
}

int main()
{
    cout << "Enter N and M:\n";
    int n, m;
    cin >> n >> m;
    double** arr = createMatrix<double>(n, m);
    
    int value = 1;
    int x_pos = 0;
    int y_pos = 0;
    int left_border = 0;
    int right_border = m - 1;
    int top_border = 0;
    int bottom_border = n - 1;
    char direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up

    while (value <= n * m)
    {
        arr[x_pos][y_pos] = value;
        ++value;

        if (direction == 0)
        {
            if (y_pos < right_border)
            {
                ++y_pos;
            }
            else
            {
                ++x_pos;
                direction = 1;
                ++top_border;
                continue;
            }
        }
        
        if (direction == 1)
        {
            if (x_pos < bottom_border)
            {
                ++x_pos;
            }
            else
            {
                --y_pos;
                direction = 2;
                --right_border;
                continue;
            }
        }

        if (direction == 2)
        {
            if (y_pos > left_border)
            {
                --y_pos;
            }
            else
            {
                --x_pos;
                direction = 3;
                --bottom_border;
                continue;
            }
        }

        if (direction == 3)
        {
            if (x_pos > top_border)
            {
                --x_pos;
            }
            else
            {
                ++y_pos;
                direction = 0;
                ++left_border;
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t\t";
        }
        cout << "\n";
    }

}