#include "Authorization.hpp"

void Start()
{
	while (true) // главный цикл программы
	{
		if (Login())
		{
			system("pause");
		}
		else
		{
			system("cls");
			std::wcout << L"\n\n\n\t\t\t Всего доброго\n\n\n";
			Sleep(1000);
			break;
		}
	}
}

	bool Login()
	{
		std::wstring login, pass;
		while (true)
		{
			system("cls");
			std::wcout << L"\n\n\n\t\t\t Добро пожаловать!\n\n\n\t\t\t VinilStore\n\n\n";
			std::wcout << L"Введите логин или \"exit\" для выхода: ";
			Getline(login);
			if (login == L"exit" || login == L"Exit")
			{
				return false;
				
			}
			else
			{
				std::wcout << L"Введите пароль:";
				Getline(pass);
				for (size_t i = 0; i < userSize; i++)
				{
					if (login == loginArr[i] && pass == passArr[i])
					{
						std::wcout << L"\nДобро пожаловать<<" << loginArr[i] << L"\n";
						std::wcout << L"\nВаш уровень доступа<<" << loginArr[i] << L"\n";
						currentId = userIdArr[i];
						currentStatus = statusArr[i];
						return true;
					}
					std::wcout << L"Неверный логин или пароль. Повторите попытку.\n\n";
					Sleep(1500);
				}
			}
		}
	}


