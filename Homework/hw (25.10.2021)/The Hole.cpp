#include <iostream>
#include <vector>


using namespace std;

typedef long long int ll;


/*

Задание 5. Дырка в массиве.

Массив длины N в случайном порядке заполнен целыми числами из диапазона от 0 до N. Каждое число встречается в массиве не более одного раза. Найти отсутствующее число (дырку). Сложность алгоритма O(N). Использование дополнительной памяти, пропорциональной длине массива, не допускается.

А что если две дырки будет, получится линейным алгоритмом?
Ответ:
Данным алгоритмом не получится в принципе найти больше одной дырки из-за его специфики (а тем более со сложностью O(N))
Для двух и больше дырок я бы использовал какую-нибудь сортировку со сложностью O(n*log(n)) для массива
Далее последовательно сравнивая элементы, я бы замечал те, которые отличаются не на один (а на два)
Тем самым мы бы находили дырку (как значение, так и позицию)

P.S. Я находил непосредственно значение "дырки", а не её позицию (в задании не уточнено, что значит "найти дырку") 
*/

int main()
{
	cout << "Enter N:\n";
	ll N;
	cin >> N;

	srand(time(NULL));
	vector<ll> vec;
	ll sum = 0;

	// Making array for the problem
	for (ll i = 0; i < N; i++ )
	{
		ll temp = rand() % (N + 1); // 0 to N

		bool exists = false;
		for (ll j = 0; j < vec.size(); j++)
		{
			if (vec[j] == temp)
			{
				exists = true;
				break;
			}
		}
		if (exists)
		{
			--i;
		}
		else
		{
			sum += temp;
			vec.push_back(temp);
			cout << temp << " ";
		}
	}
	cout << "\n"; 

	// Algorithm itself
	// We can find the sum of all elements of the array and compare it with the sum of arithmetic progression using this formula: (N+1)*N/2

	// N = vec.size();
	ll vec_sum = 0;
	for (ll i = 0; i < N; i++)
	{
		vec_sum += vec[i];
	}
	cout << "Missing element: " << ((N + 1) * N / 2) - vec_sum;
}


