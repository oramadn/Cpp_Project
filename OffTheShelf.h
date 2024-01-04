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
	OffTheShelf(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, bool BOGOF_);
	OffTheShelf(const OffTheShelf& c);

	//Setters
	void setBOGOF(bool BOGOF);
	void setOfferEnds();

	//Getters
	bool getBOGOF() const;
	Date getOfferEnds() const;

	//Print function
	void printOffTheShelf() const;
};
#endif