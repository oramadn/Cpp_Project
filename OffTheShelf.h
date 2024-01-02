#ifndef OFFTHESHELF_H
#define OFFTHESHELF_H

#include "Medication.h"
#include "Date.h"
using namespace std;

class OffTheShelf : public Medication
{
private:
	//Data members
	bool BOGOF_;
	Date OfferEnds_;

public:
	OffTheShelf();
	OffTheShelf(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, bool BOGOF_, int Offerday, int Offermonth, int Offeryear);
	OffTheShelf(const OffTheShelf& c);

	//Setters
	void setBOGOF(bool BOGOF);
	void setOfferEnds(int day, int month, int year);

	//Getters
	bool getBOGOF() const;
	Date getOfferEnds() const;

	//Print function
	void printOffTheShelf() const;
};
#endif