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
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
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
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(30) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
	}
	else
	{

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
							maxStorageSize - currentStorageSize << L" рублей\n\n";
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

}
