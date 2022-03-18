#pragma once
#include <string>
#include <vector>

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
	vector<TechInspectInfo> infoList{};
};

struct maxFieldsLen {
	size_t name = 0;
	size_t adress = 0;
	size_t model = 0;
	size_t color = 0;
	size_t year = 0;
};