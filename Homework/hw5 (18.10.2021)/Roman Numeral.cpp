
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
    ll N;
    cin >> N;

    ll arr[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    string map[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" }; 
    ll largest_base = 12;
    while (N > 0)
    {
        ll divider = N / arr[largest_base];
        N = N % arr[largest_base];
        while (divider--)
        {
            cout << map[largest_base];
        }
        largest_base--;
    }
}


