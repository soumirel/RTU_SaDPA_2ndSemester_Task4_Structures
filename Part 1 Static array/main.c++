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

string inputCheck(string inputType) {
	string inputStr = "";
	bool isCorrectInput = false;

	if (inputType == "menuSwitch") {
		while (!(cin >> inputStr) || (inputStr.length() != 1 && inputStr[0] < 48 && inputStr[0] > 57)) {
			cout << "������ �����! ��������� ����: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return inputStr;
		}

		if (inputType == "infoString") {
			getline(cin, inputStr);
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	// ������� ����������
	Table table{};
	bool isTableCreated;

	//���������� ��� ������
	maxStrLens maxLens;

	//���������� ��� ����������������� �����.
	int userChoice = -1;

	while (userChoice != 0) { // ������� ����-����.
		system("cls");


	}
	return 0;
}

void printMenu(Table* table, bool* isCreated) {
	cout << "������������ ������ #4 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� 4 - ���������. ���������� ������.\n"
		"================����================\n";
}


void printTable(Table* table, maxStrLens* maxLens, bool& isCreated) {
	unsigned headerLen = 37 + maxLens->adress + maxLens->name +
		maxLens->color + maxLens->model;
	if (isCreated) {

		for (unsigned i = 0; i < headerLen; i++) cout << "=";
		cout << endl;

		for (unsigned i = 0; i < table->tableSize; i++){

			cout << "= ";

			if (table->infoList[i].carNumber.regionCode.length() == 2) {
				cout << " " << table->infoList[i].carNumber.regionCode;
			}
			else {
				cout << table->infoList[i].carNumber.regionCode;
			}

			cout << " = ";
		}
	}
	else {
		cout << "������� �����\n";
	}
}


void insertInfo(Table* table, maxStrLens* maxLens) {
	string tempStr;
	char inputChar;
	inputChar = getchar();
	CarInfo newInfoRow{};
	unsigned spaceCounter = 0;
	unsigned dotCounter = 0;
	while (inputChar != '\n') {
		if (inputChar == ' ' || inputChar == '.') {
			switch (spaceCounter) {
			case 0:
				newInfoRow.carNumber.regionCode = tempStr;
				break;
			case 1:
				newInfoRow.carNumber.digits = tempStr;
				break;
			case 2:
				newInfoRow.carNumber.letters = tempStr;
				break;
			case 3:
				newInfoRow.model = tempStr;
				break;
			case 4:
				newInfoRow.color = tempStr;
				break;
			case 5:
				newInfoRow.personInfo.surname = tempStr;
				break;
			case 6:
				newInfoRow.personInfo.name = tempStr;
				break;
			case 7:
				newInfoRow.personInfo.adress = tempStr;
				break;
			case 8:
				switch (dotCounter) {
				case 0:
					newInfoRow.date.day = stoi(tempStr);
					break;
				case 1:
					newInfoRow.date.month = stoi(tempStr);
					break;
				case 2:
					newInfoRow.date.year = stoi(tempStr);
					break;
				}
			}
			(inputChar == ' ') ? spaceCounter++ : dotCounter++;
			tempStr = "";
		}
		else{
			tempStr += inputChar;
		}
	}

	/*���������� ������������ ����� ����� � ������. �������*/
	if (newInfoRow.model.length() > maxLens->model) {
		maxLens->model = tempStr.length();
	}
	if (newInfoRow.color.length() > maxLens->color) {
		maxLens->color = tempStr.length();
	}
	if (newInfoRow.personInfo.surname.length() +
		newInfoRow.personInfo.name.length() > maxLens->name) {
		maxLens->name = newInfoRow.personInfo.surname.length() +
			newInfoRow.personInfo.name.length();
	}
	if (newInfoRow.personInfo.adress.length() >
		maxLens->adress) {
		maxLens->adress = newInfoRow.personInfo.adress.length();
	}

	/*���� ������ �� ������ - ����� ������� ��� �������
	� ��������������� �������*/
	if (table->tableSize != 0) {

		/*��������� ��, ��� ������� ������������� �� �����,
		� ������� �� ������ �������� �������� ���������������*/

		/*���� � ������� ��� ������ ������ �����*/
		if (table->infoList[0].date.year > newInfoRow.date.year) {
			/*�������� ��� ������� ������*/
			for (unsigned i = table->tableSize - 1; i < 0; i--) {
				table->infoList[i + 1] = table->infoList[i];
			}
			table->infoList[0] = newInfoRow;
		}

		/*���� � ������� ��� ������ ������ �����*/
		else if (table->infoList[table->tableSize - 1].date.year < newInfoRow.date.year) {
			table->infoList[table->tableSize] = newInfoRow;
		}

		/*���� ����� �� else - � ������� ���� ������ ��� � �������� ������,
		��� � �� �������� -> ������������ �����, ���� �������� ����� ������, �
		������ � ������� ����� ��������� ������*/
		else {
			unsigned i = 0;
			for (; table->infoList[i].date.year < newInfoRow.date.year; i++)
			for (; table->infoList[i].date.month < newInfoRow.date.month; i++) 
			for (; table->infoList[i].date.day < newInfoRow.date.day; i++)
			for (unsigned j = table->tableSize - 1; j >= i; j--) {
				table->infoList[j + 1] = table->infoList[j];
			}
			table->infoList[i] = newInfoRow;
		}
	}
	/*������ ������ - ��������� � ������ �������*/
	else {
		table->infoList[table->tableSize] = newInfoRow;
	}
	table->tableSize++;
}


void deleteInfo(Table* table) {

}


void createSortedTable() {

}