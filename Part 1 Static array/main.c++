#include "Structures.h"
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#define NOMINMAX
#include <windows.h>

using namespace std;

void printMenu(Table& table, maxStrLen& maxLen);
void printTable(Table& table, maxStrLen& maxLen);
CarInfo createInfo(CarInfo newInfo, maxStrLen& maxLen);
void insertInfo(CarInfo info, Table& table);
size_t deleteInfo(Table& table);
void createSortedTable(Table& table, maxStrLen& maxLen);


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Главные переменные
	Table table{};
	CarInfo tempInfo{};

	//Вспомогательные переменные
	size_t tempsize_t;

	//Переменные для вывода
	maxStrLen maxLen;

	//Переменные для пользовательского ввода.
	int userChoice = -1;

	while (userChoice != 0) { // Главный меню-цикл.
		system("cls");
		printMenu(table, maxLen);
		cin >> userChoice;
		cin.ignore();
		switch (userChoice) {
		case 1:
			cout << "Выбрано занесение информации о техосмотре в таблицу\n";
			insertInfo(createInfo(tempInfo, maxLen), table);
			cout << "Запись занесена в таблицу.\n";
			system("pause");
			break;
		case 2:
			cout << "Выбрано удаление по номеру автомобиля\n";
			tempsize_t = deleteInfo(table);
			if (tempsize_t != 0) {
				cout << "Удалено " << tempsize_t << " строк\n";
			}
			else {
				cout << "Записей для удаления не было найдено\n";
			}
			cout;
			system("pause");
			break;
		case 3:
			cout << "Выбрано формирование таблицы по модели и цвету\n";
			createSortedTable(table, maxLen);
			system("pause");
			break;
		case 0:
			cout << "До свидания!\n";
			userChoice = 0;
			system("pause");
			break;
		default:
			cout << "Я не понимаю вас, повторите ввод\n";
			cin.clear();
			system("pause");
			break;
		}
	}
	return 0;
}

void printMenu(Table& table, maxStrLen& maxLen) {
	cout << "Практическая работа #4 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 4 - Структуры. Одномерный массив.\n"
		"================Меню================\n"
		"Таблица: ";
	printTable(table, maxLen);
	cout << endl;
	cout << "Введите [1], чтобы внести информацию о тех.осмотре.\n"
		"Введите [2], чтобы удалить сведения об автомобиле с заданным номером.\n"
		"Введите [3], чтобы сформировать список автомобилей по заданным модели и цвету.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}


void printTable(Table& table, maxStrLen& maxLen) {
	if (table.tableSize != 0) {
		string tableHeader1 = "Рег.номер";
		string tableHeader2 = "Модель";
		string tableHeader3 = "Цвет";
		string tableHeader4 = "Имя";
		string tableHeader5 = "Адрес";
		string tableHeader6 = "Дата";

		maxLen.model = max(maxLen.model, tableHeader2.length());
		maxLen.color = max(maxLen.color, tableHeader3.length());
		maxLen.name = max(maxLen.name + 1, tableHeader4.length());
		maxLen.adress = max(maxLen.adress, tableHeader5.length());

		size_t tableHeaderLen = tableHeader1.length() + tableHeader2.length() +
			tableHeader3.length() + tableHeader4.length() +
			tableHeader5.length() + tableHeader6.length() + 5;
		size_t horSepLen = tableHeaderLen + maxLen.adress + maxLen.name +
			maxLen.color + maxLen.model + maxLen.year;
		string VertSep = "|";

		cout << endl;
		cout << setw(horSepLen) << setfill('-') << "-" << endl;
		cout << setfill(' ');
		cout << VertSep << " " << left << tableHeader1 << "   ";
		cout << VertSep << " " << setw(maxLen.model) << left << tableHeader2 << " ";
		cout << VertSep << " " << setw(maxLen.color) << left << tableHeader3 << " ";
		cout << VertSep << " " << setw(maxLen.name) << left << tableHeader4 << " ";
		cout << VertSep << " " << setw(maxLen.adress) << left << tableHeader5 << " ";
		cout << VertSep << " " << setw(maxLen.year + 6) << tableHeader6 << " " << VertSep << endl;
		cout << setw(horSepLen) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		for (size_t i = 0; i < table.tableSize; i++){

			cout << VertSep << setw(13) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.model + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.color + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.name + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.adress + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.year + 8) << setfill(' ') << " " << VertSep;
			cout << endl;

			cout << VertSep << " " << setw(3) << right << table.infoList[i].carNumber.regionCode << " ";

			cout << table.infoList[i].carNumber.digits << " "
				 << table.infoList[i].carNumber.letters << " ";

			cout << VertSep << " " << setw(maxLen.model) << left << table.infoList[i].model << " ";

			cout << VertSep << " " << setw(maxLen.color) << left << table.infoList[i].color << " ";

			cout << VertSep << " " << setw(maxLen.name) << table.infoList[i].personInfo.surname
				+ " " + table.infoList[i].personInfo.name << " ";

			cout << VertSep << " " << setw(maxLen.adress) << table.infoList[i].personInfo.adress << " ";

			cout << VertSep << " " << table.infoList[i].date.day / 10 << table.infoList[i].date.day % 10 << "."
				 << table.infoList[i].date.month / 10 << table.infoList[i].date.month % 10 << "."
				 << setw(maxLen.year) << left << table.infoList[i].date.year << " " << VertSep << endl;

			cout << VertSep << setw(13) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.model + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.color + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.name + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.adress + 2) << setfill(' ') << " ";
			cout << VertSep << setw(maxLen.year + 8) << setfill(' ') << " " << VertSep;
			cout << endl;

			cout << setw(horSepLen) << setfill('-') << "-" << endl;
			cout << setfill(' ');
		}
	}
	else {
		cout << "Таблица пуста\n";
	}
}


CarInfo createInfo(CarInfo newInfo, maxStrLen& maxLen) {

	cout << "Введите код региона: ";
	getline(cin, newInfo.carNumber.regionCode);
	cout << "Введите цифры номера: ";
	getline(cin, newInfo.carNumber.digits);
	cout << "Введите буквы номера: ";
	getline(cin, newInfo.carNumber.letters);
	cout << "Введите модель автомобиля: ";
	getline(cin, newInfo.model);
	cout << "Введите цвет автомобиля: ";
	getline(cin, newInfo.color);
	cout << "Введите фамилию владельца: ";
	getline(cin, newInfo.personInfo.surname);
	cout << "Введите имя владельца: ";
	getline(cin, newInfo.personInfo.name);
	cout << "Введите адрес владельца: ";
	getline(cin, newInfo.personInfo.adress);
	cout << "Введите день осмотра: ";
	cin >> newInfo.date.day;
	cout << "Введите месяц осмотра: ";
	cin >> newInfo.date.month;
	cout << "Введите год осмотра: ";
	cin >> newInfo.date.year;

	/*Обновление максимальных длинн полей с нефикс. длинной*/
	maxLen.model = max(maxLen.model, newInfo.model.length());
	maxLen.color = max(maxLen.color, newInfo.color.length());
	maxLen.name = max(maxLen.name, newInfo.personInfo.surname.length() +
		newInfo.personInfo.name.length());
	maxLen.adress = max(maxLen.adress, newInfo.personInfo.adress.length());
	maxLen.year = max(maxLen.year, (size_t)log10(newInfo.date.year) + 1);

	return newInfo;
}


void insertInfo(CarInfo info, Table& table) {
	/*Если запись не первая - поиск позиции для вставки
	в хронологическом порядке*/
	if (table.tableSize != 0) {

		/*Принимаем то, что таблица отсортирована по датам,
		а таблица из одного элемента является отсортированной*/

		/*Если в таблице все записи младше новой*/
		if (table.infoList[0].date.year > info.date.year) {
			/*Сдвигаем всю таблицу вправо*/
			for (int i = table.tableSize - 1; i >= 0; i--) {
				table.infoList[i + 1] = table.infoList[i];
			}
			table.infoList[0] = info;
		}

		/*Если в таблице все записи старше новой*/
		else if (table.infoList[table.tableSize - 1].date.year < info.date.year) {
			table.infoList[table.tableSize] = info;
		}

		/*Если дошли до else - в таблице есть записи как с младшими датами,
		так и со страшими . производится поиск, куда вставить новую запись, а
		записи с младшей датой сдвигются вправо*/
		else {
			int i = 0;
			while (table.infoList[i].date.year < info.date.year && i < table.tableSize) {
				i++;
			}
			while (table.infoList[i].date.month < info.date.month && table.infoList[i].date.year == info.date.year &&
				i < table.tableSize) {
				i++;
			}
			while (table.infoList[i].date.day < info.date.day &&
				table.infoList[i].date.month == info.date.month && table.infoList[i].date.year == info.date.year &&
				i < table.tableSize) {
				i++;
			}
			for (int j = table.tableSize - 1; j >= i; j--) {
				table.infoList[j + 1] = table.infoList[j];
			}
			table.infoList[i] = info;
		}
	}
	/*Запись первая - вставляем в начало таблицы*/
	else {
		table.infoList[table.tableSize] = info;
	}
	table.tableSize++;
}


size_t deleteInfo(Table& table) {
	string rC, d, l;
	cout << "Введите код региона: ";
	getline(cin, rC);
	cout << "Введите цифры номера: ";
	getline(cin, d);
	cout << "Введите буквы номера: ";
	getline(cin, l);
	size_t deletedCounter = 0;
	for (size_t i = 0; i < table.tableSize; i++){
		if (table.infoList[i].carNumber.regionCode == rC &&
			table.infoList[i].carNumber.digits == d &&
			table.infoList[i].carNumber.letters == l) {
			for (size_t j = i; j < table.tableSize - 1; j--) {
				table.infoList[j] = table.infoList[j + 1];
			}
			i--;
			table.tableSize--;
			deletedCounter++;
		}
	}
	return deletedCounter;
}


void createSortedTable(Table& table, maxStrLen& maxLen) {
	if (table.tableSize == 0) {
		cout << "Ошибка! Таблица пуста.\n";
	}
	else {
		string m, c;
		cout << "Введите модель автомобиля: ";
		getline(cin, m);
		cout << "Введите цвет автомобиля: ";
		getline(cin, c);

		size_t indexesArr[100];
		size_t indexesCounter = 0;
		for (size_t i = 0; i < table.tableSize; i++) {
			if (table.infoList[i].model == m &&
				table.infoList[i].color == c) {
				indexesArr[indexesCounter] = i;
				indexesCounter++;
			}
		}
		cout << "По введённым:\nМодель: " << m << "\nЦвет: " << c << endl;
		if (indexesCounter) {
			string tableHeader1 = "Рег.номер";
			string tableHeader2 = "Модель";
			string tableHeader3 = "Цвет";
			string tableHeader4 = "Имя";
			string tableHeader5 = "Адрес";
			string tableHeader6 = "Дата";

			maxLen.model = max(maxLen.model, tableHeader2.length());
			maxLen.color = max(maxLen.color, tableHeader3.length());
			maxLen.name = max(maxLen.name + 1, tableHeader4.length());
			maxLen.adress = max(maxLen.adress, tableHeader5.length());

			size_t tableHeaderLen = tableHeader1.length() + tableHeader2.length() +
				tableHeader3.length() + tableHeader4.length() +
				tableHeader5.length() + tableHeader6.length() + 5;
			size_t horSepLen = tableHeaderLen + maxLen.adress + maxLen.name +
				maxLen.color + maxLen.model + maxLen.year;
			string VertSep = "|";

			cout << "Найдено:\n";
			cout << setw(horSepLen) << setfill('-') << "-" << endl;
			cout << setfill(' ');
			cout << VertSep << " " << left << tableHeader1 << "   ";
			cout << VertSep << " " << setw(maxLen.model) << left << tableHeader2 << " ";
			cout << VertSep << " " << setw(maxLen.color) << left << tableHeader3 << " ";
			cout << VertSep << " " << setw(maxLen.name) << left << tableHeader4 << " ";
			cout << VertSep << " " << setw(maxLen.adress) << left << tableHeader5 << " ";
			cout << VertSep << " " << setw(maxLen.year + 6) << tableHeader6 << " " << VertSep << endl;
			cout << setw(horSepLen) << setfill('-') << "-" << endl;
			cout << setfill(' ');

			size_t j;
			for (size_t i = 0; i < indexesCounter; i++) {
				j = indexesArr[i];

				cout << VertSep << setw(13) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.model + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.color + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.name + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.adress + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.year + 8) << setfill(' ') << " " << VertSep;
				cout << endl;

				cout << VertSep << " " << setw(3) << right << table.infoList[j].carNumber.regionCode << " ";

				cout << table.infoList[j].carNumber.digits << " "
					<< table.infoList[j].carNumber.letters << " ";

				cout << VertSep << " " << setw(maxLen.model) << left << table.infoList[j].model << " ";

				cout << VertSep << " " << setw(maxLen.color) << left << table.infoList[j].color << " ";

				cout << VertSep << " " << setw(maxLen.name) << table.infoList[j].personInfo.surname
					+ " " + table.infoList[j].personInfo.name << " ";

				cout << VertSep << " " << setw(maxLen.adress) << table.infoList[j].personInfo.adress << " ";

				cout << VertSep << " " << table.infoList[j].date.day / 10 << table.infoList[j].date.day % 10 << "."
					<< table.infoList[j].date.month / 10 << table.infoList[j].date.month % 10 << "."
					<< setw(maxLen.year) << left << table.infoList[j].date.year << " " << VertSep << endl;

				cout << VertSep << setw(13) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.model + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.color + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.name + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.adress + 2) << setfill(' ') << " ";
				cout << VertSep << setw(maxLen.year + 8) << setfill(' ') << " " << VertSep;
				cout << endl;

				cout << setw(horSepLen) << setfill('-') << "-" << endl;
				cout << setfill(' ');
			}
		}
		else {
			cout << "Ничего не найдено :(\n";
		}
	}
}			