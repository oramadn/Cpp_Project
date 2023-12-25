#include <iostream>
#include "Date.h"

using namespace std;
// Default constructor
Date::Date() : day_(1), month_(1), year_(2000) {}

// Parameterized default constructor
Date::Date(int day_, int month_, int year_) : day_(day_), month_(month_), year_(year_) {}

// Copy constructor
Date::Date(const Date& c) //Copy constructor
{
	//cout << "Date copy constructer used" << endl;
	day_ = c.day_;
	month_ = c.month_;
	year_ = c.year_;
}

//Validation of Day 
void Date::setDay(int day) {
	if (month_ == 2) {
		if (day > 28) {
			day_ = 28;
		}
		else day_ = day;
	}
	if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 9 || month_ == 10 || month_ == 12) {
		if (day > 31) {
			day_ = 31;
		}
		else day_ = day;
	}
	if (month_ == 4 || month_ == 6 || month_ == 8 || month_ == 11) {
		if (day > 30) {
			day_ = 30;
		}
		else day_ = day;
	}
}

//Validation of Month
void Date::setMonth(int month) {
	if (month > 12) { month_ = 12; }
	else month_ = month;
}

//Setter of Year
void Date::setYear(int year) {
	year_ = year;
}

int Date::getDay() const {
	return day_;
}

int Date::getMonth() const {
	return month_;
}

int Date::getYear() const {
	return year_;
}

void Date::printDate() const {
	cout << day_ << "/" << month_ << "/" << year_ << endl;
}
