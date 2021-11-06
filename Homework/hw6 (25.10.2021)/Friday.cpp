#include <iostream>

using namespace std;

/* 

Задание 1.

Определите очередной год, в который заданное число будет приходиться на пятницу.

*/
int main()
{
    int Year, Month, Day, a, y, m, d;
   

    cout << "Enter the number of day and month: \n";
    cin >> Day >> Month;

    d = -1;
    Year = 2021;

    while (d != 5)
    {
        Year++;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + 12 * a - 2;
        d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    cout << Year;
    
}


