//локальная (пока-что) база паролей к сервисам
#include "Base.h"

int main()
{
	string name;
	cout << "What domain u want to registrate?\n";
	cin >> name;

	Base user;
	user.registration(user, name);
	cout << "Would you like to log in? ";
	char confirm;
	cin.get(confirm);

	//запрос на аутентификацию
	switch (toupper(confirm))
	{
		case 'Y': {
			cout << "Ok!" << endl;
			user.autentication(user);
			break;
		};
		case 'N': {
			cout << "Farewell!" << endl;
			break;
		}
	}
	return 0;
}
