#include "Base.h"

void Base::registration(Base& u, string name)    					//Ввод с клавиатуры логина и пароля
{


	inFile.open(name);

	if (!inFile.is_open())
	{
		cout << "Problem with opening file " << name << "!";
		cin.get();
		cin.get();
		exit(EXIT_FAILURE);
	}

	LogReg(u);
	PassReg(u);
	TimeDelay();

	cout << std::endl;
	cout << "Your account has been created, " << u.login << "!\n" << endl;
}

int Base::autentication(const Base& usr)								//проверка данных регистрации
{
	string login, password;
	cout << "Enter your login: ";
	cin >> login;
	cout << "Enter your password: ";
	cin >> password;

	if (login != login or password != password)
	{
		for (int i = 3; i > 0; i--)
		{
			cout << "Wrong user data! You have " << i << " tries left. Try again!\n";
			cout << "Login: ";
			cin >> login;
			cout << "Password: ";
			cin >> password;
			if (login == login and password == password)
			{
				cout << "Welcome back, " << login << "!";
				return 0;															//return 0??????
			}
		}
		cout << "Access denied!";
	}
	else if (login == login and password == password)
	{
		cout << "Welcome back, " << login << "!";
		return 1;
	}
}