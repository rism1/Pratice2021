
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
	cin >> N >> target;
	//reversed answer
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


