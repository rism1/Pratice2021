
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long int ll;


int main() {
	int n, m;
	cout << "Enter n and m values for pyramid: \n";
	cin >> n >> m;
	if (n < 0 || m < 0)
	{
		cout << "Values must be greater than 0!\n";
		return 0;
	}
	// Top part
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int a = n - 1 - i; a > 0; a--)
			{
				cout << " ";
			}

			for (int b = 0; b < i; b++)
			{
				cout << "*";
			}
			cout << "*";
			for (int b = 0; b < i; b++)
			{
				cout << "*";
			}
			for (int a = n - 1 - i; a > 0; a--)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	//Middle part
	for (int j = 0; j < m; j++)
	{
		for (int c = 0; c < n - 1; c++)
		{
			cout << "*";
		}
		cout << "*";
		for (int c = 0; c < n - 1; c++)
		{
			cout << "*";
		}
	}
	cout << "\n";

	//Bottom part
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int a = 0; a < i + 1; a++)
			{
				cout << " ";
			}
			for (int b = 0; b < n - 2 - i; b++)
			{
				cout << "*";
			}
			cout << "*";
			for (int b = 0; b < n - 2 - i; b++)
			{
				cout << "*";
			}
			for (int a = 0; a < i + 1; a++)
			{
				cout << " ";
			}

		}
		cout << "\n";
	}

}
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//int main() {
//	int n;
//	cin >> n;
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j < n - i; j++)
//		{
//			cout << ' ';
//		}
//		for (int j = 0; j <= i * 2; j++) {
//			cout << "*";
//		}
//		for (int j = 1; j < n - i; j++)
//		{
//			cout << ' ';
//		}
//		cout << "\n";
//	}
//
//
//}

