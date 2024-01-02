#include "OffTheShelf.h"
#include "Date.h"
#include "Medication.h"
using namespace std;

OffTheShelf::OffTheShelf()// Default sonstructor
{
	BOGOF_ = false;
	setOfferEnds(0, 0, 0000);
}

//Parameterized constructor
OffTheShelf::OffTheShelf(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, bool BOGOF_, int Offerday, int Offermonth, int Offeryear) :Medication(name_, description_, price_, quantity_, Expiryday, Expirymonth, Expiryyear, barcode_),BOGOF_(BOGOF_) {
	setOfferEnds(Offerday, Offermonth, Offeryear);
}

//Copy constructor
OffTheShelf::OffTheShelf(const OffTheShelf& c) {
	BOGOF_ = c.BOGOF_;
	setOfferEnds(c.OfferEnds_.getDay(), c.OfferEnds_.getMonth(), c.OfferEnds_.getYear());
}

//Setters
void OffTheShelf::setBOGOF(bool BOGOF) {
	BOGOF_ = BOGOF;
}

void OffTheShelf::setOfferEnds(int day, int month, int year) {
	OfferEnds_.setDay(day);
	OfferEnds_.setMonth(month);
	OfferEnds_.setYear(year);
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