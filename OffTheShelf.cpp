#include "OffTheShelf.h"
#include "Date.h"
#include "Medication.h"
#include <ctime> // For getting today's date
#pragma warning(disable : 4996) //Used to avoid (_CRT_SECURE_NO_WARNINGS)
using namespace std;

OffTheShelf::OffTheShelf()// Default sonstructor
{
	BOGOF_ = false;
	setOfferEnds();
}

//Parameterized constructor
OffTheShelf::OffTheShelf(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, bool BOGOF_) :Medication(name_, description_, price_, quantity_, Expiryday, Expirymonth, Expiryyear, barcode_),BOGOF_(BOGOF_) {
	setOfferEnds();
}

//Copy constructor
OffTheShelf::OffTheShelf(const OffTheShelf& c) {
	BOGOF_ = c.BOGOF_;
	setOfferEnds();
}

//Setters
void OffTheShelf::setBOGOF(bool BOGOF) {
	BOGOF_ = BOGOF;
}

void OffTheShelf::setOfferEnds() {
	time_t now = time(0); // get current date and time  
	tm* ltm = localtime(&now); //Create a date and time object

	if (BOGOF_ == true) {
		OfferEnds_.setYear(1900 + ltm->tm_year + 2);
		OfferEnds_.setMonth(1 + ltm->tm_mon);
		OfferEnds_.setDay(ltm->tm_mday);
	}
	else {
		OfferEnds_.setYear(1900 + ltm->tm_year);
		OfferEnds_.setMonth(1 + ltm->tm_mon + 3);
		OfferEnds_.setDay(ltm->tm_mday);
	}
}

//Getters
bool OffTheShelf::getBOGOF() const {
	return BOGOF_;
}

Date OffTheShelf::getOfferEnds() const {
	return OfferEnds_;
}

//Print function
void OffTheShelf::printOffTheShelf() const {
	cout << "Buy 1 Get 1 Free status: " << BOGOF_ << endl;
	cout << "Offer ends on: ";
	OfferEnds_.printDate();
}