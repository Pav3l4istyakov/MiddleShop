#include "Storage.hpp"


size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;
size_t maxStorageSize = 20000;
size_t currentStorageSize = 0;
double maxPrice = 100000;
void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10; 

		size_t idArrStatic[staticSize]{ 1, 2, 3, 4, 5,6,7,8,9,10 }; 
		std::wstring nameArrStatic[staticSize]
		{
			L"Michael Jackson - Thriller",
			L"Metallica - Master Of Puppets",
			L"Rammstein - Mutter",
			L"The Prodigy - The Fat Of The Land",
			L"Кино - Чёрный альбом",
			L"Queen - A Night At The Opera",
			L"Pink Floyd - The Dark Side Of The Moon",
			L"Nirvana - Nevermind",
			L"AC/DC - Back In Black",
			L"Disturbed - The Sickness"
		};
		size_t countArrStatic[staticSize]{ 100, 100, 100, 70, 60, 80, 90, 75, 85, 70 };
		double priceArrStatic[staticSize]{ 10000, 9000, 8000, 7000, 6000, 5500, 4000, 3500, 2500, 1800 };


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
		std::wcout << L"\n\n\t\tТовары \"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\tПополнение товаров \"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\t\tСписание товара \"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\t\tИзменение цены \"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 4)
	{
		system("cls");
		std::wcout << L"\n\n\t\tИзменение названия товара\"VinilStore\"\n\n";
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
}


void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;
	while (true)
	{
		ShowStorage(3);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цен\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id >(int)sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новую цену:";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"Некорректная цена! Максимум " << maxPrice << L"\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> " << price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Успешное изменение цены\n\n";
								priceArr[id] = price; 
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены: " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

void ChangeStorage()
{
	std::wstring choose;
	while (true)
	{
		system("cls");

		std::wcout << L"\n\n\t\t\t Редактирование склада \n\n";
		std::wcout << L"1 - Добавить новый товар\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удаление товара\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2")
		{
			ChangeProductName();
			
		}
		else if (choose == L"3")
		{

		}
		else if (choose == L"4")
		{
			void ChangeStorageLimits()
		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход с редактирования склада";
			break;

		}
		else
		{
			Err();
		}
	}
}

void AddNewProduct()
{
	std::wstring chooseName;
	while (true)
	{
		system("cls");
		std::wcout << L"Введите название нового товара или \"exit\" для выхода: ";
		Getline(chooseName);
		if (chooseName == L"exit" || chooseName == L"Exit")
		{
			std::wcout << L"Отмена создания нового товара\n\n";
			Sleep(1500);
			return;
		}
		if (chooseName.size() < 3 || chooseName.size() > 40)
		{
			std::wcout << L"Ошибка длины названия товара\nДопустимое значение от 3 до 40 символов\n\n";
			Sleep(1500);
			continue; 
		}
		if (!IsNotSameName(chooseName, nameArr, sizeSt))
		{
			continue;
		}
		break;
	}

	std::wstring chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;

	while (true)
	{
		system("cls");
		std::wcout << L"Введите кол-во нового товара или \"exit\" для выхода: ";
		Getline(chooseCount);
		if (chooseCount == L"exit" || chooseCount == L"Exit")
		{
			std::wcout << L"Отмена создания нового товара\n\n";
			Sleep(1600);
			return;
		}
		if (!IsNumber(chooseCount))
		{
			continue;
		}
		count = std::stoull(chooseCount);
		if (count > maxStorageSize - currentStorageSize)
		{
			std::wcout << L"Ошибка! На складе осталось " << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
			Sleep(2000);
			continue;
		}
		break;
	}



	while (true)
	{
		system("cls");
		std::wcout << L"Введите цену нового товара или \"exit\" для выхода: ";
		Getline(choosePrice);
		if (choosePrice == L"exit" || choosePrice == L"Exit")
		{
			std::wcout << L"Отмена создания нового товара\n\n";
			Sleep(1600);
			return;
		}
		if (!IsNumber(choosePrice))
		{
			continue;
		}
		price = std::stod(choosePrice);
		break;
	}

	while (true)
	{
		system("cls");
		std::wcout << L"Новый товар: " << chooseName << L"\n";
		std::wcout << L"Кол-во: " << count << L"\n";
		std::wcout << L"Цена: " << price << L"\n";
		std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
		Getline(choose);

		if (choose == L"1")
		{
			std::wcout << L"Товар добавлен\n\n";
			Sleep(1400);
			return;
		}
		else if (choose == L"2")
		{
			std::wcout << L"Отмена создания товара\n\n";
			Sleep(1400);
			return;
		}
		else
		{
			Err();
		}
	}
}

void ChangeProductName()
{
	std::string chooseId, chooseName,choose;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{
		    id = std::stoi(chooseId) - 1;
			if (id < 0 || id >(int)sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения: " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
							if (choose == L"1")

							{
								std::wcout << "Расширение склада";
								for (size_t i = 0; i < 5; i++)
								{
									Sleep(500);
									std::wcout << L".";
								}
								Sleep(500);
								ArrPushABack(idArr, sizeSt);
								ArrPushABack(nameArr, sizeSt);
								ArrPushABack(countArr, sizeSt);
								ArrPushABack(priceArr, sizeSt);
								sizeSt++;
								idArr[sizeSt - 1] = chooseName;
								countArr[sizeSt - 1] = count;
								priceArr[sizeSt - 1] = price;
								currentStorageSize += count;
								std::wcout << L"\n\nТовар успешно добавлен\n";
								Sleep(1600);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << !"Отмена\n";

							}
						}
					}
				}
			}
		}
	}
}

void DeleteProduct()
{
	std::wstring chooseId;
	int id = 0;
	std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
	Getline(choose);
	if (chooseId == L"exit" || chooseId == L"Exit")
	{
		std::wcout << L"Завершение операции пополнения товара\n\n";
		Sleep(1600);
		return;
	}
	else if (IsNumber(chooseId))
	{
		id = std::stoi(chooseId) - 1;
		if (id < 0 || id >(int)sizeSt - 1)
		{
			Err();
		}
		else
		{
			std::wcout << L"Введите кол-во товара для пополнения: ";
			Getline(chooseCount);
			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);
				if (count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
					Sleep(2000);
				}
				else
				{
					std::wcout << L"Подтвердите удаления товара:" << nameArr[id]
						<< L"\nПароль Супер Администратора:";
					Getline(pass);
					if (pass = passArr[0])
					{
						std::wcout << L"Удаление товара";
						for (size_t i = 0; i < 5; i++)
						{
							Sleep(5000);
							std::wcout << L".";
						}
						Sleep(500);
						ArrDeleteByIndex(idArr, sizeSt, id);
						ArrDeleteByIndex(nameArr, sizeSt, id);
						ArrDeleteByIndex(countArr, sizeSt, id);
						currentStorageSize -= countArr[id];
						ArrDeleteByIndex(priceArr, sizeSt, id);
						sizeSt--;
						for (size_t i = 0; i < sizeSt; i++)
						{
							idArr[i] = i + 1;
						 
						}
						//;)
						std::wcout << "\n\nТовар успешно удалён\n";
						Sleep(1600)

					}
					else
					{
						Err();
					}
				}
			}
		}
	}
}

void ChangeStorageLimits()
{
	std::wcout << L"\n\nВ процессе разработки\n\n";
	Sleep(1500);
}




void AddProduct()
{
	std::wstring chooseId, chooseCount, choose, chooseName;
	int id = 0;
	size_t count = 0;
	double price =0;


	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id >(int)sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное кол-во! На складе осталось " << maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> " << countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения: " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
							if (choose == L"1")

							{
								std::wcout << "Расширение склада";
								for (size_t i = 0; i < 5; i++)
								{
									Sleep(500);
									std::wcout << L".";
								}
								Sleep(500);
								ArrPushABack(idArr, sizeSt);
								ArrPushABack(nameArr, sizeSt);
								ArrPushABack(countArr, sizeSt);
								ArrPushABack(priceArr, sizeSt);
								sizeSt++;
								idArr[sizeSt - 1] = chooseName;
								countArr[sizeSt - 1] = count;
								priceArr[sizeSt - 1] = price;
								currentStorageSize += count;
								std::wcout << L"\n\nТовар успешно добавлен\n";
								Sleep(1600);
								break;




							}
							else if (choose == L"2")
							{
								std::wcout << !"Отмена\n";

							}
						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(2);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списания товара\n\n";
			Sleep(1600);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id >(int)sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count > countArr[id])
					{
						std::wcout << L"Некорректное кол-во! На складе осталось " << countArr[id] << L" ед. товара\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> " << countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);

							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания: " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}


