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
	unsigned day;
	unsigned month;
	size_t year;
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

struct maxStrLen {
	size_t name = 0;
	size_t adress = 0;
	size_t model = 0;
	size_t color = 0;
	size_t year = 0;
};