/*���� ���������� �����������.��������� ������ �� ���������� : 
�����(��� �������, �������� ���, ��������� ���), 
������, ����, �������� � ���������(�������, ���, �����), 
���� ���������� ����������.
1)	���������� ������ �� ������ ���������� � ����������.
2)	�������� ������ �� ���������� � �������, ���, ����� ����������� ��������������� �� ����������� �� ���� ����������.
3)	������� �������� �� ���������� � �������� �������.
4)	������������ ������ ����������� �������� ������ � ��������� �����. */


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

	// ������� ����������
	Table table{};
	CarInfo tempInfo{};
	bool isTableCreated = false;

	//��������������� ����������
	unsigned tempUnsigned;

	//���������� ��� ������
	maxStrLens maxLens;

	//���������� ��� ����������������� �����.
	int userChoice = -1;

	while (userChoice != 0) { // ������� ����-����.
		system("cls");
		printMenu(table, maxLens, isTableCreated);
		cin >> userChoice;
		cin.ignore();
		switch (userChoice) {
		case 1:
			cout << "������� ��������� ���������� � ���������� � �������\n";
			insertInfo(createInfo(tempInfo, maxLens), table);
			cout << "������ �������� � �������.\n";
			if (!isTableCreated) isTableCreated = true;
			system("pause");
			break;
		case 2:
			cout << "������� �������� �� ������ ����������\n";
			tempUnsigned = deleteInfo(table);
			if (tempUnsigned != 0) {
				cout << "������� " << tempUnsigned << " �����\n";
			}
			else {
				cout << "������� ��� �������� �� ���� �������";
			}
			cout;
			system("pause");
			break;
		case 3:
			cout << "������� ������������ ������� �� ������ � �����\n";
			createSortedTable(table, maxLens, isTableCreated);
		case 0:
			cout << "�� ��������!\n";
			userChoice = 0;
			system("pause");
			break;
		default:
			cout << "� �� ������� ���, ��������� ����\n";
			cin.clear();
			system("pause");
			break;
		}
	}
	return 0;
}

void printMenu(Table& table, maxStrLens& maxLens, bool& isCreated) {
	cout << "������������ ������ #4 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� 4 - ���������. ���������� ������.\n"
		"================����================\n"
		"�������: ";
	printTable(table, maxLens, isCreated);
	cout << endl;
	cout << "������� [1], ����� ������ ���������� � ���.�������.\n"
		"������� [2], ����� ������� �������� �� ���������� � �������� �������.\n"
		"������� [3], ����� ������������ ������ ����������� �� �������� ������ � �����.\n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "��� �����: ";
}


void printTable(Table& table, maxStrLens& maxLens, bool& isCreated) {
	unsigned headerLen = 40 + maxLens.adress + maxLens.name +
		maxLens.color + maxLens.model;
	if (isCreated) {

		cout << endl;

		for (unsigned i = 0; i < headerLen; i++) cout << "-";
		cout << endl;

		cout << "| ���. �����  ";

		cout << "| ������ ";
		for (unsigned i = 0; i < maxLens.model - 6 && maxLens.model > 6; i++){
			cout << " ";
		}

		cout << "| ���� ";
		for (unsigned i = 0; i < maxLens.color - 4 && maxLens.color > 4; i++) {
			cout << " ";
		}

		cout << "| ��� ";
		for (unsigned i = 0; i < maxLens.color - 2 && maxLens.color > 2; i++) {
			cout << " ";
		}

		cout << "| ����� ";
		for (unsigned i = 0; i < maxLens.color - 5 && maxLens.color > 5; i++) {
			cout << " ";
		}

		cout << "| ����      |" << endl;


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
		cout << "������� �����\n";
	}
}


CarInfo createInfo(CarInfo newInfo, maxStrLens& maxLens) {

	cout << "������� ��� �������: ";
	getline(cin, newInfo.carNumber.regionCode);
	cout << "������� ����� ������: ";
	getline(cin, newInfo.carNumber.digits);
	cout << "������� ����� ������: ";
	getline(cin, newInfo.carNumber.letters);
	cout << "������� ������ ����������: ";
	getline(cin, newInfo.model);
	cout << "������� ���� ����������: ";
	getline(cin, newInfo.color);
	cout << "������� ������� ���������: ";
	getline(cin, newInfo.personInfo.surname);
	cout << "������� ��� ���������: ";
	getline(cin, newInfo.personInfo.name);
	cout << "������� ����� ���������: ";
	getline(cin, newInfo.personInfo.adress);
	cout << "������� ���� �������: ";
	string tempStrDate;
	getline(cin, tempStrDate);
	newInfo.date.day = stoul(tempStrDate);
	cout << "������� ����� �������: ";
	getline(cin, tempStrDate);
	 newInfo.date.month = stoul(tempStrDate);
	cout << "������� ��� �������: ";
	getline(cin, tempStrDate);
	newInfo.date.year = stoul(tempStrDate);


	/*���������� ������������ ����� ����� � ������. �������*/
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
	/*���� ������ �� ������ - ����� ������� ��� �������
	� ��������������� �������*/
	if (table.tableSize != 0) {

		/*��������� ��, ��� ������� ������������� �� �����,
		� ������� �� ������ �������� �������� ���������������*/

		/*���� � ������� ��� ������ ������ �����*/
		if (table.infoList[0].date.year > info.date.year) {
			/*�������� ��� ������� ������*/
			for (unsigned i = table.tableSize - 1; i < 0; i--) {
				table.infoList[i + 1] = table.infoList[i];
			}
			table.infoList[0] = info;
		}

		/*���� � ������� ��� ������ ������ �����*/
		else if (table.infoList[table.tableSize - 1].date.year < info.date.year) {
			table.infoList[table.tableSize] = info;
		}

		/*���� ����� �� else - � ������� ���� ������ ��� � �������� ������,
		��� � �� �������� . ������������ �����, ���� �������� ����� ������, �
		������ � ������� ����� ��������� ������*/
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
	/*������ ������ - ��������� � ������ �������*/
	else {
		table.infoList[table.tableSize] = info;
	}
	table.tableSize++;
}


unsigned deleteInfo(Table& table) {
	string rC, d, l;
	cout << "������� ��� �������: ";
	getline(cin, rC);
	cout << "������� ����� ������: ";
	getline(cin, d);
	cout << "������� ����� ������: ";
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
		cout << "������! ������� �����.\n";
	}
	else {
		string m, c;
		cout << "������� ������ ����������: ";
		getline(cin, m);
		cout << "������� ���� ����������: ";
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

			cout << "| ���. �����  ";

			cout << "| ������ ";
			for (unsigned i = 0; i < maxLens.model - 7 && maxLens.model > 7; i++) {
				cout << " ";
			}

			cout << "| ���� ";
			for (unsigned i = 0; i < maxLens.color - 5 && maxLens.color > 5; i++) {
				cout << " ";
			}

			cout << "| ��� ";
			for (unsigned i = 0; i < maxLens.color - 4 && maxLens.color > 4; i++) {
				cout << " ";
			}

			cout << "| ����� ";
			for (unsigned i = 0; i < maxLens.color - 6 && maxLens.color > 6; i++) {
				cout << " ";
			}

			cout << "| ����      |";


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
			cout << "�� ������� ������ �� ������� :(\n";
		}
	}
}