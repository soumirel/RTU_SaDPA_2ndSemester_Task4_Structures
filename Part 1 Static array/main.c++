/*Учет техосмотра автомобилей.Структура записи об автомобиле : 
Номер(код региона, цифровой код, буквенный код), 
Модель, Цвет, Сведения о владельце(Фамилия, Имя, Адрес), 
дата последнего техосмотра.
1)	Заполнение записи по одному автомобилю с клавиатуры.
2)	Вставить запись по автомобилю в таблицу, так, чтобы сохранялась упорядоченность по возрастанию по дате техосмотра.
3)	Удалить сведения об автомобиле с заданным номером.
4)	Сформировать список автомобилей заданной модели и заданного цвета. */


#include "Structures.h"
#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>

using namespace std;
void printMenu(Table& table, maxStrLens& maxLens, bool& isCreated);
void printTable(Table& table, maxStrLens& maxLens, bool& isCreated);
CarInfo createInfo(CarInfo newInfo, maxStrLens& maxLens);
void insertInfo(CarInfo info, Table& table);
unsigned deleteInfo(Table& table);
void createSortedTable(Table& table, maxStrLens& maxLens, bool& isCreated);


int main() {
	setlocale(LC_ALL, "Russian");

	// Главные переменные
	Table table{};
	CarInfo tempInfo{};
	bool isTableCreated = false;

	//Вспомогательные переменные
	unsigned tempUnsigned;

	//Переменные для вывода
	maxStrLens maxLens;

	//Переменные для пользовательского ввода.
	int userChoice = -1;

	while (userChoice != 0) { // Главный меню-цикл.
		system("cls");
		printMenu(table, maxLens, isTableCreated);
		cin >> userChoice;
		cin.ignore();
		switch (userChoice) {
		case 1:
			cout << "Выбрано занесение информации о техосмотре в таблицу\n";
			insertInfo(createInfo(tempInfo, maxLens), table);
			cout << "Запись занесена в таблицу.\n";
			if (!isTableCreated) isTableCreated = true;
			system("pause");
			break;
		case 2:
			cout << "Выбрано удаление по номеру автомобиля\n";
			tempUnsigned = deleteInfo(table);
			if (tempUnsigned != 0) {
				cout << "Удалено " << tempUnsigned << " строк\n";
			}
			else {
				cout << "Записей для удаления не было найдено";
			}
			cout;
			system("pause");
			break;
		case 3:
			cout << "Выбрано формирование таблицы по модели и цвету\n";
			createSortedTable(table, maxLens, isTableCreated);
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

void printMenu(Table& table, maxStrLens& maxLens, bool& isCreated) {
	cout << "Практическая работа #4 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 4 - Структуры. Одномерный массив.\n"
		"================Меню================\n"
		"Таблица: ";
	printTable(table, maxLens, isCreated);
	cout << endl;
	cout << "Введите [1], чтобы внести информацию о тех.осмотре.\n"
		"Введите [2], чтобы удалить сведения об автомобиле с заданным номером.\n"
		"Введите [3], чтобы сформировать список автомобилей по заданным модели и цвету.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}


void printTable(Table& table, maxStrLens& maxLens, bool& isCreated) {
	unsigned headerLen = 40 + maxLens.adress + maxLens.name +
		maxLens.color + maxLens.model;
	if (isCreated) {

		cout << endl;

		for (unsigned i = 0; i < headerLen; i++) cout << "-";
		cout << endl;

		cout << "| рег. номер  ";

		cout << "| модель ";
		for (unsigned i = 0; i < maxLens.model - 6 && maxLens.model > 6; i++){
			cout << " ";
		}

		cout << "| цвет ";
		for (unsigned i = 0; i < maxLens.color - 4 && maxLens.color > 4; i++) {
			cout << " ";
		}

		cout << "| имя ";
		for (unsigned i = 0; i < maxLens.color - 2 && maxLens.color > 2; i++) {
			cout << " ";
		}

		cout << "| адрес ";
		for (unsigned i = 0; i < maxLens.color - 5 && maxLens.color > 5; i++) {
			cout << " ";
		}

		cout << "| дата      |" << endl;


		string sep = "| ";
		unsigned spaceCounter = 0;
		for (unsigned i = 0; i < table.tableSize; i++){

			cout << sep;
			if (table.infoList[i].carNumber.regionCode.length() == 2) {
				cout << " ";
			}
			cout << table.infoList[i].carNumber.regionCode << " "
				<< table.infoList[i].carNumber.digits << " "
				<< table.infoList[i].carNumber.letters << " ";

			cout << sep
			if (maxLens.model < 7) spaceCounter = table.infoList[i].model.length() - 7;
			else spaceCounter = maxLens.model - table.infoList[i].model.length();
			for (unsigned i = 0; i < spaceCounter; i++) {
				cout << " ";
			}

			cout << sep
				<< table.infoList[i].color;
			spaceCounter = maxLens.color - table.infoList[i].color.length();
			if (spaceCounter < 5) spaceCounter = 5;
			for (unsigned i = 0; i < spaceCounter; i++) {
				cout << " ";
			}

			cout << sep
				<< table.infoList[i].personInfo.surname << " "
				<< table.infoList[i].personInfo.name << " ";
			spaceCounter = maxLens.name - table.infoList[i].personInfo.surname.length() - table.infoList[i].personInfo.name.length();
			if (spaceCounter < 4) spaceCounter = 4;
			for (unsigned i = 0; i < spaceCounter; i++) {
				cout << " ";
			}

			cout << sep
				<< table.infoList[i].personInfo.adress << " ";
			spaceCounter = maxLens.adress - table.infoList[i].personInfo.adress.length();
			if (spaceCounter < 6) spaceCounter = 6;
			for (unsigned i = 0; i < spaceCounter; i++) {
				cout << " ";
			}

			cout << sep
				<< table.infoList[i].date.day << "."
				<< table.infoList[i].date.month << "."
				<< table.infoList[i].date.year << " |";
			cout << endl;
		}
	}
	else {
		cout << "Таблица пуста\n";
	}
}


CarInfo createInfo(CarInfo newInfo, maxStrLens& maxLens) {

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
	string tempStrDate;
	getline(cin, tempStrDate);
	newInfo.date.day = stoul(tempStrDate);
	cout << "Введите месяц осмотра: ";
	getline(cin, tempStrDate);
	 newInfo.date.month = stoul(tempStrDate);
	cout << "Введите год осмотра: ";
	getline(cin, tempStrDate);
	newInfo.date.year = stoul(tempStrDate);


	/*Обновление максимальных длинн полей с нефикс. длинной*/
	if (newInfo.model.length() > maxLens.model) {
		maxLens.model = newInfo.model.length();
	}
	if (newInfo.color.length() > maxLens.color) {
		maxLens.color = newInfo.color.length();
	}
	if (newInfo.personInfo.surname.length() +
		newInfo.personInfo.name.length() > maxLens.name) {
		maxLens.name = newInfo.personInfo.surname.length() +
			newInfo.personInfo.name.length();
	}
	if (newInfo.personInfo.adress.length() >
		maxLens.adress) {
		maxLens.adress = newInfo.personInfo.adress.length();
	}

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
			for (unsigned i = table.tableSize - 1; i < 0; i--) {
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
			unsigned i = 0;
			for (; table.infoList[i].date.year < info.date.year; i++)
				for (; table.infoList[i].date.month < info.date.month; i++)
					for (; table.infoList[i].date.day < info.date.day; i++)
						for (unsigned j = table.tableSize - 1; j >= i; j--) {
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


unsigned deleteInfo(Table& table) {
	string rC, d, l;
	cout << "Введите код региона: ";
	getline(cin, rC);
	cout << "Введите цифры номера: ";
	getline(cin, d);
	cout << "Введите буквы номера: ";
	getline(cin, l);
	unsigned deletedCounter = 0;
	for (unsigned i = 0; i < table.tableSize; i++){
		if (table.infoList[i].carNumber.regionCode == rC &&
			table.infoList[i].carNumber.digits == d &&
			table.infoList[i].carNumber.letters == l) {
			for (unsigned j = i; j < table.tableSize - 1; j--) {
				table.infoList[j] = table.infoList[j + 1];
			}
			table.tableSize--;
			deletedCounter++;
		}
	}
	return deletedCounter;
}


void createSortedTable(Table& table, maxStrLens& maxLens, bool& isCreated) {
	if (!isCreated) {
		cout << "Ошибка! Таблица пуста.\n";
	}
	else {
		string m, c;
		cout << "Введите модель автомобиля: ";
		getline(cin, m);
		cout << "Введите цвет автомобиля: ";
		getline(cin, c);

		unsigned indexesArr[1000];
		unsigned indexesCounter = 0;
		for (unsigned i = 0; i < table.tableSize; i++) {
			if (table.infoList[i].model == m &&
				table.infoList[i].color == c) {
				indexesArr[indexesCounter] = i;
				indexesCounter++;
			}
		}

		if (indexesCounter) {
			unsigned headerLen = 37 + maxLens.adress + maxLens.name +
				maxLens.color + maxLens.model;
			cout << endl;

			for (unsigned i = 0; i < headerLen; i++) cout << "-";
			cout << endl;

			cout << "| рег. номер  ";

			cout << "| модель ";
			for (unsigned i = 0; i < maxLens.model - 7 && maxLens.model > 7; i++) {
				cout << " ";
			}

			cout << "| цвет ";
			for (unsigned i = 0; i < maxLens.color - 5 && maxLens.color > 5; i++) {
				cout << " ";
			}

			cout << "| имя ";
			for (unsigned i = 0; i < maxLens.color - 4 && maxLens.color > 4; i++) {
				cout << " ";
			}

			cout << "| адрес ";
			for (unsigned i = 0; i < maxLens.color - 6 && maxLens.color > 6; i++) {
				cout << " ";
			}

			cout << "| дата      |";


			string sep = "| ";
			for (auto &i : indexesArr) {

				cout << sep
					<< table.infoList[i].carNumber.regionCode
					<< table.infoList[i].carNumber.digits
					<< table.infoList[i].carNumber.letters << " ";

				cout << sep
					<< table.infoList[i].model;
				for (unsigned i = 0;
					i < maxLens.model - table.infoList[i].model.length()
					&& maxLens.model > table.infoList[i].model.length(); i++) {
					cout << " ";
				}

				cout << sep
					<< table.infoList[i].color;
				for (unsigned i = 0;
					i < maxLens.color - table.infoList[i].color.length()
					&& maxLens.color > table.infoList[i].color.length(); i++) {
					cout << " ";
				}

				cout << sep
					<< table.infoList[i].personInfo.surname << " "
					<< table.infoList[i].personInfo.name << " ";
				for (unsigned i = 0;
					i < maxLens.name - table.infoList[i].personInfo.surname.length() - table.infoList[i].personInfo.name.length()
					&& maxLens.name > table.infoList[i].personInfo.name.length() + table.infoList[i].personInfo.name.length(); i++) {
					cout << " ";
				}

				cout << sep
					<< table.infoList[i].personInfo.adress << " ";
				for (unsigned i = 0;
					i < maxLens.adress - table.infoList[i].personInfo.adress.length()
					&& maxLens.adress > table.infoList[i].personInfo.adress.length(); i++) {
					cout << " ";
				}

				cout << sep
					<< table.infoList[i].date.day << "."
					<< table.infoList[i].date.month << "."
					<< table.infoList[i].date.year << " |";
			}
		}
		else {
			cout << "По запросу ничего не найдено :(\n";
		}
	}
}