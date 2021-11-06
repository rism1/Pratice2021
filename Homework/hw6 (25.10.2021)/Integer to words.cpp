#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

typedef long long int ll;

/*

Задание 4.

Составьте программу, читающую целое положительное число, не превышающее миллиард, и выводящее это же число на естественном языке.

Входные данные: 1024.

Выход: одна тысяча двадцать четыре.

*/

// !!! Программа масштабируема и для чисел, превышающих миллиард

int main()
{
	//setlocale(LC_ALL, "Russian");

	system("chcp 1251");


	cout << "Введите число: \n";
	ll N;
	cin >> N;
	vector<string> words = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять",
		"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать",
		"двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто",
		"сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот" , "семьсот", "восемьсот", "девятьсот"
	};
	
	// Программу можно масштабировать, добавляя в adds[] системы наименования чисел в таком порядке падежей и числа: Именительный в ед. ч, Родительный в ед. ч, Родительный во мн. ч 
	vector<string> adds = { "", "тысяча", "тысячи", "тысяч",
								"миллион", "миллиона", "миллионов",
								"миллиард", "миллиарда", "миллиардов"};
	vector<int> digits;


	while (N != 0)
	{
		digits.push_back(N % 10);
		N /= 10;
	}

	bool from_ten_to_nineteen = false;
	int sum_of_3_digits = 0;
	for (int pos = digits.size(); pos > 0; pos--)
	{
		

		// Сотни (в words от 28 до 36)
		if (pos % 3 == 0)
		{
			sum_of_3_digits += 100 * digits[pos - 1];

			if (digits[pos - 1] == 0)
			{

			}
			else
			{
				cout << words[digits[pos - 1] + 27] << " ";
			}
		}


		// Десятки (в words от 10 до 27)
		if (pos % 3 == 2)
		{
			sum_of_3_digits += 10 * digits[pos - 1];

			if (digits[pos - 1] == 0)
			{
				from_ten_to_nineteen = false;
			}
			else if (digits[pos - 1] == 1)
			{
				from_ten_to_nineteen = true;
				int val10 = digits[pos - 1] * 10 + digits[pos - 2];
				cout << words[val10] << " ";
			}
			else
			{
				cout << words[digits[pos - 1] + 18] << " ";
			}


		}

		// Единицы (в words от 1 до 9)
		if (pos % 3 == 1)
		{
			sum_of_3_digits += digits[pos - 1];

			if (digits[pos - 1] == 0)
			{

			}
			else if (from_ten_to_nineteen)
			{
				//from_ten_to_nineteen = false;
			}
			else
			{

				// для "тысяча" есть два исключения: "одна" и "две", т.к. "тысяча" женского рода (больше исключений нет, т.к. в системе наименовании больших чисел все остальные слова мужского рода (миллиард, триллион, квадриллион, квинтиллион, секстиллион и т.д) => можем масштабировать программу)
				if (pos == 4 && (digits[pos - 1] == 1 || digits[pos - 1] == 2))
				{
					//cout << (digits[pos - 1] == 1) ? "одна" : "две"; тернарный оператор опять шалит
					if (digits[pos - 1] == 1)
					{
						cout << "одна ";
					}
					else
					{
						cout << "две ";
					}

				}
				else
				{
					cout << words[digits[pos - 1]] << " ";
				}
			}
		}

		// Наименование тройки разрядов
		if (pos != 1 && pos % 3 == 1)
		{
			if (sum_of_3_digits == 0)
			{

			}
			else 	if (digits[pos - 1] == 1 && !from_ten_to_nineteen) {
				cout << adds[pos - 3] << " ";
			}
			else if ((digits[pos - 1] >= 2 && digits[pos - 1] <= 4) && !from_ten_to_nineteen) {
				cout << adds[pos - 2] << " ";
			}
			else
			{

				cout << adds[pos - 1] << " ";
			}
			from_ten_to_nineteen = false;
			sum_of_3_digits = 0;
		}

		//if (pos == 4)
		//{
		//	if (sum_of_3_digits == 0)
		//	{
		//		
		//	} else 	if (digits[pos - 1] == 1 && !from_ten_to_nineteen)	{
		//		cout << "тысяча ";
		//	}
		//	else if ((digits[pos - 1] >= 2 && digits[pos - 1] <= 4) && !from_ten_to_nineteen) {
		//		cout << "тысячи ";
		//	}
		//	else // цифры от 5 до 9 и числа от десяти до девятнадцати
		//	{

		//		cout << "тысяч ";
		//	}
		//	from_ten_to_nineteen = false;
		//	sum_of_3_digits = 0;
		//}

		//if (pos == 7)
		//{
		//	if (sum_of_3_digits == 0)
		//	{
		//		
		//	} else	if (digits[pos - 1] == 1 && !from_ten_to_nineteen)
		//	{
		//		cout << "миллион ";
		//	}
		//	else if ((digits[pos - 1] >= 2 && digits[pos - 1] <= 4) && !from_ten_to_nineteen) {
		//		cout << "миллиона ";
		//	}
		//	else // цифры от 5 до 9 и числа от десяти до девятнадцати
		//	{

		//		cout << "миллионов ";
		//	}
		//	from_ten_to_nineteen = false;
		//	sum_of_3_digits = 0;
		//}
	}
}


