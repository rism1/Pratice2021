#include <iostream>

/*
Написать функцию void shiftArray(int A[], int n, in k), которая осуществляет циклический сдвиг элементов массива на k влево.
    Например, если был массив
    A[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    То после вызова функции shiftArray(A, 10, 3);
    Должен получиться массив {3, 4, 5, 6, 7, 8, 9, 0, 1,2};
    Дополнительную память не использовать. Алгоритм должен быть сложности O(n).
*/

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
        return gcd(b, a % b);
}

// The Juggling Algorithm //

void shiftArray(int arr[], int n, int k)
{
    k = k % n;
    int sets = gcd(k, n);
    for (int i = 0; i < sets; i++) {

        int temp = arr[i];
        int j = i;

        while (true) {
            int m = j + k;
            if (m >= n)
                m = m - n;

            if (m == i)
                break;

            arr[j] = arr[m];
            j = m;
        }
        arr[j] = temp;
    }
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; // k = 2; 3,4,5,6,7,8,9,10,1,2
	
    shiftArray(arr, 10, 2);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}

