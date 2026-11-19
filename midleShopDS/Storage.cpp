#include "Storage.h"


size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool IsStorageCreated = false;

extern size_t maxStorageSize = 5000;
extern size_t currentStorageSize = 0;

double maxPrice = 10000;


void CreateStorage(int mode)
{
	if (mode == 0 && !IsStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Табак для кальяна", L"Табак для трубок", L"Кальяны",
			L"Жидкость",L"Сигары кубинские", L"Угли для кальяна", L"Сигары Corona",
			L"Сигары Torpedo",L"Сигареты", L"Испарители"
		};
		size_t countArrStatic[staticSize]{ 20, 30, 10, 50, 100, 5, 40, 80, 150, 77 };
		double priceArrStatic[staticSize]{ 250.5, 300, 1500, 333, 456, 389.9, 455,
			764.8, 255.5 };

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

		IsStorageCreated = true;
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
		std::wcout << L"\n\n\t\t\tПополнение склада \"Раскумар\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(30) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tПополнение склада \"Раскумар\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из " 
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tСписание склада \"Раскумар\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
			<< maxStorageSize << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tИзменение цены \"Раскумар\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара"
			<< L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(30) << nameArr[i]
				<< L"\t" << std::setprecision(2) << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else if (mode == 4)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tТовары \"Раскумар\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else
	{
		std::wcerr << L"_SHOW_STORAGE_MODE_NOT_FOUND_\n\n";
		Sleep(1500);
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
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
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
					if (count < 0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное кол-во! на складе осталось " <<
							maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
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
								std::wcout << L"Отмена пополнения " << nameArr[id] << L"\n";
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

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списание товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
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
					if (count < 0 || count > countArr[id])
					{
						std::wcout << L"Некорректное кол-во! на складе осталось " <<
							maxStorageSize - currentStorageSize << L" свободных мест\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] - count << L"\n\n";
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
								std::wcout << L"Отмена списания " << nameArr[id] << L"\n";
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
			std::wcout << L"Завершение операции изменения цены\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новую стоимость товара: ";
				Getline(choosePrice);

				if (IsNumber(choosePrice))
				{
					price = std::stod(choosePrice);
					if (price < 0 || price > maxPrice)
					{
						std::wcout << L"Некорректное цена! Максимально возможная цена: " <<
							maxPrice << L" рублей\n\n";
						Sleep(2000);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> "
								<< price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Успешное изменение цены\n\n";
								priceArr[id] = price;
								// :)
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изменения цены " << nameArr[id] << L"\n";
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
		std::wcout << L"\n\n\t\t\tРедактирование склада \" Раскумар\"\n\n";
		std::wcout << L"1 - добавление нового склада\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удаление товара\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n";
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
				
		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход из редактора склада\n\n";
			Sleep(1500);
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
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;
	while (true)
	{
		while (true)
		{
			system("cls");

			std::wcout << L"Введите названиеновго товара или \exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() < 3 || chooseName.size() > 40)
			{
				std::wcout << L"Слишком много символов в названии товара\n";
				std::wcout << L"Допустимое значение от 3 до 40 символов\n\n";
				std::wcout << L"Кол-во символов в названии вашего нового товара: \n" 
					<< chooseName.size() << L"\n\n";
				Sleep(1600);
				continue;
			}
			if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данный товар уже есть на складе\n\n";
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Заполненность склада: " << currentStorageSize << L" из "
				<< maxStorageSize << L"\n\n";
			std::wcout << L"Введите кол-во товара или \exit\" для выхода: ";
			Getline(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}

			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);
				if (count < 0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное кол-во! на складе осталось " <<
						maxStorageSize - currentStorageSize << L" свободных мест\n\n";
					Sleep(2000);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Введите стоимость товара или \exit\" для выхода: ";
			Getline(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit")
			{
				std::wcout << L"Отмена добавления ного товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(choosePrice))
			{
				price = std::stod(choosePrice);
				if (price < 0 || price > maxPrice)
				{
					std::wcout << L"Некорректное цена! Максимально возможная цена: " <<
						maxPrice << L" рублей\n\n";
					Sleep(2000);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Кол-во " << count << L"\n";
			std::wcout << L"Цена " << std::fixed << std::setprecision(2) << price << L"\n\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод:  ";
			Getline(choose);
			if (choose == L"1")
			{
				std::wcout << L"Загрузка новый данных в базу данных:";
				for (size_t i = 0; i < 3; i++)
				{
					Sleep(650);
					std::wcout << L".";
				}

				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);

				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				currentStorageSize += count;
				//:)
				std::wcout << L"\n\nНовый товар успешно добавлен\n\n";
				Sleep(1500);
				break;

			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n\n";
				Sleep(1400);
				break;
			}
			else
			{
				Err();
			}
		}
	}
}

void ChangeProductName()
{
	std::wstring chooseName;
	while (true)
	{
		system("cls");

		ShowStorage(4); // тут остановились

		std::wcout << L"Введите названиеновго товара или \exit\" для выхода: ";
		Getline(chooseName);
		if (chooseName == L"exit" || chooseName == L"Exit")
		{
			std::wcout << L"Отмена добавления нового товара\n\n";
			Sleep(1500);
			return;
		}
		if (chooseName.size() < 3 || chooseName.size() > 40)
		{
			std::wcout << L"Слишком много символов в названии товара\n";
			std::wcout << L"Допустимое значение от 3 до 40 символов\n\n";
			std::wcout << L"Кол-во символов в названии вашего нового товара: \n"
				<< chooseName.size() << L"\n\n";
			Sleep(1600);
			continue;
		}
		if (IsNotSame(chooseName, nameArr, sizeSt))
		{
			break;
		}
		else
		{
			std::wcout << L"Данный товар уже есть на складе\n\n";
		}
	}
}


