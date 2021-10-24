
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
	ll n;
	cin >> n;
	ll count = 0;
	ll m_max = n;
	while (n != 1)
	{
		
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n *= 3;
			n++;
		}
		m_max = max(m_max, n);
		count++;
	}
	cout << m_max << " " << count;
}


