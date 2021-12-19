#include <iostream>

using namespace std;

/*

Задание 2.

Какова вероятность того, что 13 число заданного месяца окажется пятницей? Определите количество пятниц, пришедшихся на 13-е числа в XX столетии.

*/

typedef long long int ll;

int main()
{
    int Year, Month, Day, a, y, m, d;

    ll month_count = (2000 - 1901 + 1) * 12;
    ll fri_count = 0;

    for (int Year = 1901; Year <= 2000; Year++)
    {
        for (int Month = 1; Month <= 12; Month++)
        {
            /*for (int Day = 1; Day <= 31; Day++)
            {
                if ((Month == 2) && (Day == 30))
                {
                    if (!(((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)))
                    {
                        break;
                    }
                }

                if ((Month == 2) && (Day == 29))
                {
                    break;
                }

                if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31)
                {
                    break;
                }

                a = (14 - Month) / 12;
                y = Year - a;
                m = Month + 12 * a - 2;
                d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

                if (d == 5)
                {
                    ++fri_count;
                }
                ++count;
            }*/

            a = (14 - Month) / 12;
            y = Year - a;
            m = Month + 12 * a - 2;
            d = (13 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
            if (d == 5)
            {
                ++fri_count;
            }
            
        }
    }
   /* cout << "Percentage of Fridays XX century: \t" << (float)fri_count / (float)count * 100.0f << "%\n";
    cout << "Number of Fridays in XX century: \t" << fri_count << "\n";
    cout << "Number of days in XX century: \t\t" << count;*/
    cout << "Percentage of Fridays the 13th per month in XX century: \t" << (float)fri_count / (float)month_count * 100.0f << "%\n";
    cout << "Number of Fridays the 13th in XX century: \t" << fri_count << "\n";
    cout << "Number of months in XX century: \t" << month_count << "\n";
}


