
#include <iostream>
#include <iomanip> 

#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <chrono>
#include <time.h>


using namespace std;
typedef  long long int ll;
typedef  unsigned long long int ull;


int main()
{
	ll N, target;
	cout << "Enter value to convert and target numeral system (target value must be between 0 and 37): \n";
	cin >> N >> target;
	//reversed answer
	if (target <= 0 || target > 10 + 26) // target = 11: start using letters, target = 26: max amount of letters that can be used
	{
		cout << "Target numeral system is invalid!\n";
		return 0;
	}
	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	while (N > 0)
	{
		ll remainder = N % target;
		if (remainder <= 9)
		{
			cout << remainder;
		}
		else
		{
			char digit = 'A' + remainder - 10;
			cout << digit;
		}
		N /= target;
	}
}


