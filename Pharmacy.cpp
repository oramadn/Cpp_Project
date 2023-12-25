#include "Pharmacy.h"
#include <iostream>
#include <string>
using namespace std;

int Pharmacy::nextId = 1;

Pharmacy::Pharmacy() : pharmacyId(nextId++),pharmacyName("none"),currentMedicationCount(0),currentCustomerCount(0) {}

Pharmacy::Pharmacy(int pharmacyId, string pharmacyName, int currentMedicationCount, int currentCustomerCount): pharmacyId(pharmacyId),pharmacyName(pharmacyName), currentMedicationCount(currentMedicationCount),currentCustomerCount(currentCustomerCount) {}

Pharmacy::Pharmacy(const Pharmacy& c): pharmacyId(c.pharmacyId), pharmacyName(c.pharmacyName), currentMedicationCount(c.currentMedicationCount), currentCustomerCount(c.currentCustomerCount) {}

void Pharmacy::setName(string name) {
	pharmacyName = name;
}

void Pharmacy::addMedication() { //Adding medication
	if (currentMedicationCount < 50) {
		string stringInput;
		int intInput,day,month,year;
		float floatInput;

		cout << "\nPlease enter the following information:\n";
		cout << "Name: ";
		cin >> stringInput;
		
		medications[currentMedicationCount].setName(stringInput);

		cout << "Description: ";
		cin >> stringInput;
		medications[currentMedicationCount].setDescription(stringInput);

		cout << "Price: ";
		cin >> floatInput;
		medications[currentMedicationCount].setPrice(floatInput);

		cout << "Quantity: ";
		cin >> intInput;
		medications[currentMedicationCount].setQuantity_in_Stock(intInput);

		cout << "Expiry date (day): ";
		cin >> day;
		cout << "Expiry date (month): ";
		cin >> month;
		cout << "Expiry date (year): ";
		cin >> year;
		medications[currentMedicationCount].setDate(day,month,year);

		cout << "Barcode: ";
		cin >> intInput;
		medications[currentMedicationCount].setbarcode(intInput);
		currentMedicationCount++;
	}
	else {
		cout << "Medication inventory full. Cannot add more medications." << endl;
	}
}

void Pharmacy::removeMedication() {
	for (int i = 0; i < currentMedicationCount; ++i) {
		cout <<i<<". "<< medications[i].getName()<<endl;
	}

	int choice;
	cin >> choice;
	if (choice == currentMedicationCount) {
		currentMedicationCount--;
	}
	else {
		for (int i = choice; i < currentMedicationCount - choice; i++) {
			medications[choice] = medications[choice + 1];
		}
		currentMedicationCount--;
	}
}

void Pharmacy::addCustomer() { //Adding customer
	if (currentCustomerCount < 50) {
		string name, email, city,mobile_no,street_name;

		cout << "\nPlease enter the following information:\n";
		cout << "Name: ";
		cin >> name;

		cout << "Email: ";
		cin >> email;
		
		cout << "City: ";
		cin >> city;
		
		cout << "Mobile number: ";
		cin >> mobile_no;
		
		cout << "Street name: ";
		cin >> street_name;

		customers[currentCustomerCount].setCustomer_Name(name);
		customers[currentCustomerCount].setAddress(email,city,mobile_no,street_name);

		currentCustomerCount++;
	}
	else {
		cout << "Customer list full. Cannot add more customers." << endl;
	}
}

string Pharmacy::getName() {
	return pharmacyName;
}

void Pharmacy::displayMedications() {
	if (currentMedicationCount == 0) {
		cout << "No medications available." << endl;
	}
	else {
		for (int i = 0; i < currentMedicationCount; ++i) {
			medications[i].display_medication_information();
		}
	}
}

void Pharmacy::displayCustomers() {
	if (currentCustomerCount == 0) {
		cout << "No customers registered." << endl;
	}
	else {
		for (int i = 0; i < currentCustomerCount; ++i) {
			customers[i].printCustomerInfo();
			cout << endl;
		}
	}
}
