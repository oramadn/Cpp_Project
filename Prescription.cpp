#include "Prescription.h"
#include "Date.h"
using namespace std;

Prescription::Prescription() //Default constructor
{
	FDANumber_ = 0;
	setApprovalDate(1, 1, 2000);
}

//Parameterized constructor
Prescription::Prescription(string name_, string description_, float price_, int quantity_, int Expiryday, int Expirymonth, int Expiryyear, int barcode_, int FDANumber_, int Approvalday, int Approvalmonth, int Approvalyear) :Medication(name_, description_, price_, quantity_, Expiryday, Expirymonth, Expiryyear, barcode_),FDANumber_(FDANumber_){
	setApprovalDate(Approvalday, Approvalmonth, Approvalyear);
}

//Copy constructor
Prescription::Prescription(const Prescription& c)
{
	FDANumber_ = c.FDANumber_;
	setApprovalDate(c.ApprovalDate_.getDay(), c.ApprovalDate_.getMonth(), c.ApprovalDate_.getYear());
}

//Setters
void Prescription::setFDANumber(int FDANumber) {
	FDANumber_ = FDANumber;
}

void Prescription::setApprovalDate(int day, int month, int year) {
	ApprovalDate_.setDay(day);
	ApprovalDate_.setMonth(month);
	ApprovalDate_.setYear(year);
}

//Getters
int Prescription::getFDANumber() const {
	return FDANumber_;
}

Date Prescription::getApprovalDate() const {
	return ApprovalDate_;
}

void Prescription::printPrescription() const {
	cout << "FDA number: " << FDANumber_ << endl;
	cout << "Approval date: ";
	ApprovalDate_.printDate();
}