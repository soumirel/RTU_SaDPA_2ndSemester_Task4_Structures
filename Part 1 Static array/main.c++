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
	short rowsCounter;
	bool isTableCreated;


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


void printTable(Table* table, bool* isCreated) {

}


void insertInfo(Table* table, short &rowsCounter) {
	string tempStr;
	char inputChar;
	inputChar = getchar();
	CarInfo info{};
	short spaceCounter = 0;
	while (inputChar != '\n') {
		if (inputChar == ' ') {
			switch (spaceCounter) {
			case 0:
				info.carNumber.regionCode = tempStr;
				break;
			case 1:
				info.carNumber.digits = tempStr;
				break;
			case 2:
				info.carNumber.letters = tempStr;
				break;
			case 3:
				info.model = tempStr;
				break;
			case 4:
				info.color = tempStr;
				break;
			case 5:
				info.personInfo.surname = tempStr;
				break;
			case 6:
				info.personInfo.name = tempStr;
				break;
			case 7:
				info.personInfo.adress = tempStr;
				break;
			case 8:
				info.personInfo.adress = tempStr;
				break;
			}
			spaceCounter++;
			tempStr = "";
		}
		else {
			tempStr += inputChar;
		}
	}
	table->infoList[rowsCounter] = info;
	rowsCounter++;
}


void deleteInfo(Table* table) {

}


void createSortedTable() {

}