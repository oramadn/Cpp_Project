#ifndef PHARMACY_H  // Include guard
#define PHARMACY_H

#include "Medication.h"
#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;

class Pharmacy {
private:
	static int nextId;
	const int pharmacyId;
	string pharmacyName;
	Medication medications[50];
	Customer customers[50];
	int currentMedicationCount;
	int currentCustomerCount;

public:
	Pharmacy();
	Pharmacy(int pharmacyId, string pharmacyName, int currentMedicationCount, int currentCustomerCount);
	Pharmacy(const Pharmacy& c);

	void setName(string name);
	void addMedication();
	void removeMedication();
	void addCustomer();
	string getName ();
	void displayMedications();
	void displayCustomers();
};

#endif
