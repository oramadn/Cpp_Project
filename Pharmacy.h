#ifndef PHARMACY_H  // Include guard
#define PHARMACY_H

#include "Medication.h"
#include "Customer.h"
#include "Prescription.h"
#include "OffTheShelf.h"
#include <iostream>
#include <string>

using namespace std;

class Pharmacy {
private:
	static int nextId;
	const int pharmacyId;
	string pharmacyName_;

	Prescription* prescriptions_;
	OffTheShelf* OffTheShelfs_;
	Customer* customers_;
	int prescriptionSize_;
	int OffTheShelfSize_;
	int customersSize_;

public:
	Pharmacy();
	Pharmacy(int pharmacyId, string pharmacyName, int prescriptionSize, int OffTheShelfSize, int currentCustomerCount);
	Pharmacy(const Pharmacy& c);
	Pharmacy& operator=(const Pharmacy& other);
	~Pharmacy();

	void setName(string name);
	void addPrescription();
	void addOfftheshelf();
	void removePrescription();
	void removeOfftheshelf();
	void addCustomer();
	string getName () const;
	void displayMedications() const;
	void displayCustomers();
};

#endif
