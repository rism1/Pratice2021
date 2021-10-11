
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>
using namespace std;
typedef  long long int ll;


int main()
{
	ll R;
	cin >> R;
	//for (ll R = 1; R <= 10; ++R)
	{
		{
			ll tick_start = clock();
			unsigned long long int count = 0;

			long long countAxis = 0;
			for (ll x = 1; x <= R; x++)
			{
				if (x * x <= R * R)
				{
					countAxis++;
				}
			}
			count += countAxis * 4;

			long long countQuarter = 0;
			for (ll y = R; y > 0; --y)
			{
				for (ll x = 1 ; x <= R; ++x)
				{
					if (x*x + y*y <= R*R)
					{
						countQuarter++;
					}
					else
					{
						break;
					}
				}

			}
			count += countQuarter * 4 + 1;
			ll tick_end = clock();

			cout << R << " " << count << " " << ((float)tick_end - tick_start) / CLOCKS_PER_SEC << "s" << "\n";
		}
	}
	
	
				
				
}
