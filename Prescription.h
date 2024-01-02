#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include "Medication.h"
#include "Date.h"
using namespace std;

class Prescription : public Medication
{
private:
	//Data members
	int FDANumber_;
	Date ApprovalDate_;

public:
	Prescription();
	Prescription(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, int FDANumber_, int Approvalday, int Approvalmonth, int Approvalyear);
	Prescription(const Prescription& c);

	//Setters
	void setFDANumber(int FDANumber);
	void setApprovalDate(int day, int month, int year);

	//Getters
	int getFDANumber() const;
	Date getApprovalDate() const;

	//Print function
	void printPrescription() const;
};

#endif