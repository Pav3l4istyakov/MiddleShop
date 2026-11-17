#include "Storage.hpp"


size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;
size_t maxStorageSize;
size_t currentStorageSize;
void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated )
	{
		const size_t static staticSize = 10;


		size_t idArrStatic[staticSize]{ 1,2,4,5,6,7,8,9,10 };
		std::wstring nameArrStatic[staticSize]
		{
		  L"Michael Jackson - Triller", L"Mettalica - Master Of Puppets", L"Rammstein - Mutter", L"The Prodigy - The Fat Of The Land", L"Кино-Чёрный албом",


		};
		size_t countArrStatic[staticSize]{ 100, 90, 80 , 70, 60 };
		double priceArrStatic[staticSize]{ 10000 , 9000, 8000, 7000,6000 };

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArr, idArrStatic, sizeSt);
		FillArray(nameArr, nameArrStatic, sizeSt);
		FillArray(countArr, countArrStatic, sizeSt);
		FillArray(priceArr, priceArrStatic, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}

		isStorageCreated = true;
	}
	else if (mode == 1)
	{

	}
	else
	{
		std::wcout << L"Склад уже создан\n\n";
	}
	



}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\t\tТовары\"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Назавние товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\tТовары\"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Назавние товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";

		std::wcout << L"Заполненность склада" << currentStorageSize << L"из"
			<< maxStorageSize << L"\n\n";
	}
}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\ для выхода";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L" Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{

			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt-1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите ко-во товара для пополнения:";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);

				}
			}
		}
	}
}
