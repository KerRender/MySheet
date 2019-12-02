#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

const int pass_length = 8;

class Base
{
private:
	string login;
	string password;
	std::ofstream inFile;
	std::ifstream outFile;

	void TimeDelay()
	{
		clock_t delay = 0.8 * CLOCKS_PER_SEC;
		for (int i = 0; i < 3; i++)
		{
			clock_t start = clock();                  //Задержка выполнения
			cout << '.';
			while (clock() - start < delay)
				;
		}
	}
	void LogReg(Base& u)
	{
		cout << "Enter your login: ";
		cin >> login;
		inFile << login;
	}
	void PassReg(Base& u)
	{
		do
		{
			cout << "Enter your password (" << pass_length << " character max): ";
			cin >> password;															//Проверка пароля на соответствие диапазона
			inFile << password;
		} while (password.length() > pass_length);
	}
public:
	void registration(Base&, std::string);
	int autentication(const Base&);
};
#endif BASE_H_