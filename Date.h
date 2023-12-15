#include <iostream>

using namespace std;

class Date {
private:
	int day_;
	int month_;
	int year_;

public:
	// Default constructor
	Date();

	// Parameterized default constructor
	Date(int day_, int month_, int year_);

	//Copy constructor
	Date(const Date& c);

	//Setters of the date
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	//Getters of the date
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	//Display of Date
	void printDate() const;
};