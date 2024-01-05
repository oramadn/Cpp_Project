#include "Pharmacy.h"
#include <iostream>
#include <string>
using namespace std;

int Pharmacy::nextId = 1;

Pharmacy::Pharmacy() : pharmacyId(nextId++),pharmacyName_("none"),prescriptions_(nullptr),OffTheShelfs_(nullptr), customers_(nullptr), prescriptionSize_(0),OffTheShelfSize_(0),customersSize_(0) {}

Pharmacy::Pharmacy(int pharmacyId, string pharmacyName,int prescriptionSize,int OffTheShelfSize,int customersSize): pharmacyId(pharmacyId), pharmacyName_(pharmacyName), prescriptions_(new Prescription[0]), OffTheShelfs_(new OffTheShelf[0]),customers_(new Customer[0]), prescriptionSize_(prescriptionSize), OffTheShelfSize_(OffTheShelfSize), customersSize_(customersSize) {}

Pharmacy::Pharmacy(const Pharmacy& c): pharmacyId(c.pharmacyId), pharmacyName_(c.pharmacyName_),prescriptions_(nullptr),OffTheShelfs_(nullptr),customers_(nullptr), prescriptionSize_(c.prescriptionSize_), OffTheShelfSize_(c.OffTheShelfSize_),customersSize_(c.customersSize_) {
	if (c.prescriptions_ != nullptr) {
		prescriptions_ = new Prescription[c.prescriptionSize_];
		for (int i = 0; i < c.prescriptionSize_; i++) {
			prescriptions_[i] = c.prescriptions_[i];
		}
	}
	if (c.OffTheShelfs_ != nullptr) {
		OffTheShelfs_ = new OffTheShelf[c.OffTheShelfSize_];
		for (int i = 0; i < c.OffTheShelfSize_; i++) {
			OffTheShelfs_[i] = c.OffTheShelfs_[i];
		}
	}
	if (c.customers_ != nullptr) {
		customers_ = new Customer[c.customersSize_];
		for (int i = 0; i < c.customersSize_; i++) {
			customers_[i] = c.customers_[i];
		}
	}
}
// Copy assignment operator
Pharmacy& Pharmacy:: operator=(const Pharmacy& c) {
	if (this != &c) {  // Self-assignment check
		// Copy static members
		pharmacyName_ = c.pharmacyName_;
		prescriptionSize_ = c.prescriptionSize_;
		OffTheShelfSize_ = c.OffTheShelfSize_;
		customersSize_ = c.customersSize_;

		//Dynamic memory garbage collection
		delete[] prescriptions_;
		delete[] OffTheShelfs_;

		// Copy dynamic members
		if (c.prescriptions_ != nullptr) {
			prescriptions_ = new Prescription[c.prescriptionSize_];
			for (int i = 0; i < c.prescriptionSize_; i++) {
				prescriptions_[i] = c.prescriptions_[i];
			}
		}
		else {
			prescriptions_ = nullptr;
		}

		if (c.OffTheShelfs_ != nullptr) {
			OffTheShelfs_ = new OffTheShelf[c.OffTheShelfSize_];
			for (int i = 0; i < c.OffTheShelfSize_; i++) {
				OffTheShelfs_[i] = c.OffTheShelfs_[i];
			}
		}
		else {
			OffTheShelfs_ = nullptr;
		}

		if (c.customers_ != nullptr) {
			customers_ = new Customer[c.customersSize_];
			for (int i = 0; i < c.OffTheShelfSize_; i++) {
				customers_[i] = c.customers_[i];
			}
		}
		else {
			customers_ = nullptr;
		}
	}
	return *this;
}

Pharmacy::~Pharmacy() {
	delete[] prescriptions_;
	delete[] OffTheShelfs_;
}

void Pharmacy::setName(string name) {
	pharmacyName_ = name;
}

string Pharmacy::getName() const {
	return pharmacyName_;
}

void Pharmacy::addPrescription() {
	Prescription* newprescriptions = new Prescription[prescriptionSize_ + 1];
	for (int i = 0; i < prescriptionSize_; ++i) {
		newprescriptions[i] = prescriptions_[i];
	}

	string stringInput;
	int intInput, day, month, year;
	float floatInput;

	cout << "\nPlease enter the following information:\n";
	cout << "Name: ";
	cin >> stringInput;
	newprescriptions[prescriptionSize_].setName(stringInput);

	cout << "Description: ";
	cin >> stringInput;
	newprescriptions[prescriptionSize_].setDescription(stringInput);

	cout << "Price: ";
	cin >> floatInput;
	newprescriptions[prescriptionSize_].setPrice(floatInput);

	cout << "Quantity: ";
	cin >> intInput;
	newprescriptions[prescriptionSize_].setQuantity_in_Stock(intInput);

	cout << "Expiry date (day): ";
	cin >> day;
	cout << "Expiry date (month): ";
	cin >> month;
	cout << "Expiry date (year): ";
	cin >> year;
	newprescriptions[prescriptionSize_].setDate(day, month, year);

	cout << "Barcode: ";
	cin >> intInput;
	newprescriptions[prescriptionSize_].setbarcode(intInput);

	cout << "FDA number: ";
	cin >> intInput;
	newprescriptions[prescriptionSize_].setFDANumber(intInput);

	cout << "Approval date (day): ";
	cin >> day;
	cout << "Approval date (month): ";
	cin >> month;
	cout << "Approval date (year): ";
	cin >> year;
	newprescriptions[prescriptionSize_].setApprovalDate(day, month, year);
	
	prescriptionSize_++;

	delete[] prescriptions_;
	prescriptions_ = newprescriptions;
}

void Pharmacy::addOfftheshelf() {
	OffTheShelf* newofftheshelf= new OffTheShelf[OffTheShelfSize_+ 1];
	for (int i = 0; i < OffTheShelfSize_; ++i) {
		newofftheshelf[i] = OffTheShelfs_[i];
	}

	string stringInput;
	int intInput, day, month, year;
	float floatInput;
	char charInput;

	cout << "\nPlease enter the following information:\n";
	cout << "Name: ";
	cin >> stringInput;
	newofftheshelf[OffTheShelfSize_].setName(stringInput);

	cout << "Description: ";
	cin >> stringInput;
	newofftheshelf[OffTheShelfSize_].setDescription(stringInput);

	cout << "Price: ";
	cin >> floatInput;
	newofftheshelf[OffTheShelfSize_].setPrice(floatInput);

	cout << "Quantity: ";
	cin >> intInput;
	newofftheshelf[OffTheShelfSize_].setQuantity_in_Stock(intInput);

	cout << "Expiry date (day): ";
	cin >> day;
	cout << "Expiry date (month): ";
	cin >> month;
	cout << "Expiry date (year): ";
	cin >> year;
	newofftheshelf[OffTheShelfSize_].setDate(day, month, year);

	cout << "Barcode: ";
	cin >> intInput;
	newofftheshelf[OffTheShelfSize_].setbarcode(intInput);

	cout << "Buy 1 get 1 free offer?: (Y/N)";
	cin >> charInput;
	if(charInput == 'y' || charInput == 'Y'){ newofftheshelf[OffTheShelfSize_].setBOGOF(true); }
	else if (charInput == 'n' || charInput == 'N') { newofftheshelf[OffTheShelfSize_].setBOGOF(false); }

	newofftheshelf[OffTheShelfSize_].setOfferEnds();

	OffTheShelfSize_++;

	delete[] OffTheShelfs_;
	OffTheShelfs_ = newofftheshelf;
}

void Pharmacy::removePrescription() {
	// Display a list of available medications
	cout << "Available Medications:" << endl;
	for (int i = 0; i < prescriptionSize_; ++i) {
		cout << i + 1 << ". ";
		cout << prescriptions_[i].getName() << endl;
	}
	// Which medication to remove?
	int choice;
	cout << "Enter the number of the medication to remove: ";
	cin >> choice;
	// Validation
	if (choice >= 1 && choice <= prescriptionSize_) {
		for (int i = choice - 1; i < prescriptionSize_ - 1; ++i) {
			prescriptions_[i] = prescriptions_[i + 1];
		}
		prescriptionSize_--;

		cout << "Medication removed successfully." << endl;
	}
	else {
		cout << "Invalid choice. No medication removed." << endl;
	}
}

void Pharmacy::removeOfftheshelf() {
	// Display a list of available medications
	cout << "Available Medications:" << endl;
	for (int i = 0; i < OffTheShelfSize_; ++i) {
		cout << i + 1 << ". ";
		cout << OffTheShelfs_[i].getName() << endl;
	}
	// Which medication to remove?
	int choice;
	cout << "Enter the number of the medication to remove: ";
	cin >> choice;
	// Validation
	if (choice >= 1 && choice <= OffTheShelfSize_) {
		for (int i = choice - 1; i < OffTheShelfSize_ - 1; ++i) {
			OffTheShelfs_[i] = OffTheShelfs_[i + 1];
		}
		OffTheShelfSize_--;

		cout << "Medication removed successfully." << endl;
	}
	else {
		cout << "Invalid choice. No medication removed." << endl;
	}
}

void Pharmacy::addCustomer() { //Adding customer
	Customer* newcustomers = new Customer[customersSize_ + 1];
	for (int i = 0; i < customersSize_; ++i) {
		newcustomers[i] = customers_[i];
	}

	string name, email, city,mobile_no,street_name;

	cout << "\nPlease enter the following information:\n";
	cout << "Name: ";
	cin >> name;
	newcustomers[customersSize_].setCustomer_Name(name);

	cout << "Email: ";
	cin >> email;
		
	cout << "City: ";
	cin >> city;
		
	cout << "Mobile number: ";
	cin >> mobile_no;
		
	cout << "Street name: ";
	cin >> street_name;
	newcustomers[customersSize_].setAddress(email, city, mobile_no, street_name);

	customersSize_++;

	delete[] customers_;
	customers_ = newcustomers;
}

void Pharmacy::displayMedications() const {
	if (prescriptionSize_ == 0 && OffTheShelfSize_ == 0) {
		cout << "No medications available." << endl;
	}
	else {
		for (int i = 0; i < prescriptionSize_; ++i) {
			prescriptions_[i].printPrescription();
		}
		for (int i = 0; i < OffTheShelfSize_; ++i) {
			OffTheShelfs_[i].printOffTheShelf();
		}
	}
}

void Pharmacy::displayCustomers() {
	if (customersSize_ == 0) {
		cout << "No customers registered." << endl;
	}
	else {
		for (int i = 0; i < customersSize_; ++i) {
			customers_[i].printCustomerInfo();
			cout << endl;
		}
	}
}
