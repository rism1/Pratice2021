/*

Домашнее задание:
Написать программу, которая вычисляет число pi с заданной пользователем точностью. Для вычисления значения числа pi воспользоваться формулой: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)


Определить какое количество дробей необходимо было добавить к сумме, чтобы обеспечить заданную точность. Запомнить кол-во, например в переменной N.

 

Рассмотрим произвольный квадрат с центром в начале координат и вписанный в него круг. Будем рассматривать только первую координатную четверть. В ней будет находиться четверть круга и четверть квадрата. Обозначим радиус круга R, тогда четверть квадрата тоже будет квадратом со стороной R. Будем случайным образом выбирать точки в этом квадрате и считать количество точек, попавших в четверть круга. Из теории вероятности известно, что отношение попаданий в четверть круга к попаданиям "в молоко" равно отношению площадей – pi/4.

Реализовать указанный алгоритм вычислений. Количество выбираемых точек N (вычислено ранее).

 

Сравнить вычисленные двумя способами значения числа pi. Можно сделать вывод какой способ сходится быстрее?

*/
#include <iostream>
#include <cmath>
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
	cout << "FIRST ALGORITHM:\n";
	double _rpi = 3.14159265359;
	vector<ll> vec;
	double _pi = 1;
	double sum = 0;
	auto t1 = std::chrono::high_resolution_clock::now();

	ll stage = 1;
	ll divider = 1;
	for (ll i = 0; i <= 200000; i++)
	{
		if (i % 2 != 0)
		{
			sum += -(1.0 / (double)divider);
		}
		else
		{
			sum += 1.0 / (double)divider;
		}
		divider += 2;
		_pi = 4.0 * sum;


		if ((to_string(_rpi).substr(0, 2 + stage)) == (to_string(_pi).substr(0, 2 + stage)))
		{
			stage++;
			vec.push_back(i+1);
			auto t2 = std::chrono::high_resolution_clock::now();
			cout << "precision: " << stage - 1 << "\tfractions: " << i + 1 << " (" << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms)\n";
		}
		
	}

	cout << "\nSECOND ALGORITHM:\n";

	srand(time(NULL));

	ull r = 10000;
	auto t3 = std::chrono::high_resolution_clock::now();
	for (ull i = 0; i < vec.size(); i++)
	{
		ll inCircle = 0;
		ll outCircle = 0;
		for (ull j = 0; j < vec[i]; j++)
		{
			ull x = rand() % (r + 1);
			ull y = rand() % (r + 1);
			if (x * x + y * y <= r * r)
			{
				inCircle++;
			}
			else
			{
				outCircle++;
			}
		}
		auto t4 = std::chrono::high_resolution_clock::now();

		cout << (double)inCircle / ((double)outCircle + (double)inCircle) * 4.0 << "\t";
		cout << "precision: " << i + 1 << "\tfractions: " << vec[i] << " (" << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count() << "ms)\n";

	}

}


