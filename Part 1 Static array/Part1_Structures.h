#pragma once
#include <string>

using namespace std;

const size_t maxTableSize = 100;

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
	size_t day;
	size_t month;
	size_t year;
};

struct TechInspectInfo {
	CarNumber carNumber;
	string model;
	string color;
	PersonInfo personInfo;
	Date date;
};

struct TechInspectTable {
	TechInspectInfo infoList[maxTableSize] = {};
	int tableSize = 0;
};

struct maxFieldsLen {
	size_t name = 0;
	size_t adress = 0;
	size_t model = 0;
	size_t color = 0;
	size_t year = 0;
};