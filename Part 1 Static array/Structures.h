#pragma once

const int maxTableSize = 100;

#include <string>

using namespace std;

struct CarNumber {
	string regionCode;
	string digits;
	string letters;
};

struct PersonInfo {
	string name;
	string surname;
	string adress;
};

struct Date {
	string day;
	string month;
	string year;
};

struct CarInfo {
	CarNumber carNumber;
	string model;
	string color;
	PersonInfo personInfo;
	Date date;
};

struct Table {
	CarInfo infoList[maxTableSize] = {};
	int tableSize = 0;
};