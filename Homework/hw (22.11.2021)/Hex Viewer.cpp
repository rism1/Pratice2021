#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

/*

Задание (HexView). Написать программу, которая записывает информацию из входного файла в следующем виде (см. рис):



Сдвиг от начала  файла для строки символов.

Двоеточие, пробел.

8 кодов символов строки из входного файла, записанные как 16-ое число и пробел.

Вертикальная черта.

Следующие 8 кодов символов строки из входного файла, записанные как 16-ое число и пробел.

16 символов из входного файла (символы с кодами меньше 32 (управляющие символы) выводить как пробелы или точки).

В итоге должен получиться текстовый файл, например, как на картинке.

*/

/*
//////////////////////////

The problem occurs with Cyrillic where the code is negative int.
How to get positive value within the byte so it can be displayed with two symbols in hex?

//////////////////////////
*/

int main()
{
	string str;
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "There was a problem reading a file!";
		return 0;
	}
	
	while (!file.eof())
	{
		string temp;
		file >> temp;
		str += temp;
		str += " ";
	}
	str.pop_back();
	string temp = "";

	ostringstream os;
	int i = 0;
	for (i = 0; i < str.size(); i++)
	{
		
		if (i % 16 == 0)
		{
			if (i != 0) os << " " << temp << "\n";
			os << setfill('0') << setw(10) << hex << i << ": ";
			temp.erase();
		}
		os << uppercase << setw(2) << hex << (int)(str[i]) << " ";
		temp += str[i];
		
		if (i % 8 == 0 && i != 0 && i % 16 != 0)
		{
			os << "| ";
		}
	}
	while (i % 16 != 0)
	{
		os << "   ";
		if (i % 8 == 0 && i != 0 && i % 16 != 0)
		{
			os << "| ";
		}
		i++;
	}
	os << " " << temp;
	//cout << os.str();

	ofstream output("hex.txt");
	output << os.str();
	
}