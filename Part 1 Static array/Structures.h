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
	unsigned day;
	unsigned month;
	unsigned year;
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

struct maxStrLens {
	unsigned name = 0;
	unsigned adress = 0;
	unsigned model = 0;
	unsigned color = 0;
};