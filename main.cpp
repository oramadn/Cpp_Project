//Omar Ramadan 20190692
//Omar Ashraf AlQerm 20210894
//Mohammad Toubasi 20220496
//Yousef Mahmoud 20220448

//Github link: https://github.com/oramadn/Cpp_Project

#include<iostream>
#include<string>
#include "Customer.h"
#include "Medication.h"
#include "Prescription.h"
#include "OffTheShelf.h"
#include "Address.h"
#include "Date.h"
#include "Pharmacy.h"
using namespace std;

void addPharmacy(Pharmacy*& pharmacies,int& pharmaciesSize) { // "*& is used to modify the actual passed pointer
	//Initialize object
	string stringInput;
	cout << "\nPlease enter pharmacy name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //The getline function was getting skipped due to the buffer being full, so had to add this line to clear the buffer
	getline(cin, stringInput); // To capture name even with spaces
	Pharmacy entry;
	entry.setName(stringInput);

	Pharmacy* newpharmacies = new Pharmacy[pharmaciesSize + 1];
	for (int i = 0; i < pharmaciesSize; ++i) {
		newpharmacies[i] = pharmacies[i];
	}
	newpharmacies[pharmaciesSize++] = entry;

	delete[] pharmacies;
	pharmacies = newpharmacies;
}

int choosePharmacy(Pharmacy* pharmacies,int pharmaciesSize){
	cout << "\nChoose a pharmacy (enter the number):\n";
	for (int i = 0; i < pharmaciesSize; i++) {
		cout << i << ". " << pharmacies[i].getName() << endl;
	}

	int pharmacyChoice;
	cin >> pharmacyChoice;

	if (pharmacyChoice >= 0 && pharmacyChoice <= sizeof(pharmacies)) {
		return pharmacyChoice;
	}
	else {
		cout << "Invalid option. Please choose a valid pharmacy." << endl;
		return -1; //error
	}
}

int main() {
	//Program starts here
	Pharmacy* pharmacies = nullptr;
	int chosenPharmacy = -1, pharmaciesSize = 0;
	char choice, medicineChoice;
	cout << "\nManagement system initiated";
	while (1) { //Running the program indefinitely until an 'x' is inputted
		cout << "\n\nPlease choose the required operation:\n(1) Add pharmacy\n(2) Add medication\n(3) Add customer\n(4) Display medication\n(5) Remove a medication from a pharmacy\n(6) Display list of customers\n(x) Exit\n\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case('x'):
			cout << "\nExiting program";
			return 0; 
		case('1'): //Add pharmacy
			addPharmacy(pharmacies, pharmaciesSize);
			break;

		case('2')://Add medication
			if (pharmacies == nullptr) {
				cout << "There are no pharamcies in the system. Please add a pharmacy first";
				break;
			}
			chosenPharmacy = choosePharmacy(pharmacies, pharmaciesSize);
			if (chosenPharmacy!=-1){
				cout << "Would you like to add a prescription medicine (p) or an Off the shelf medicine (o)?: ";
				cin >> medicineChoice;
				if (medicineChoice == 'p' || medicineChoice == 'P'){ pharmacies[chosenPharmacy].addPrescription(); }
				else if (medicineChoice == 'o' || medicineChoice == 'O') { pharmacies[chosenPharmacy].addOfftheshelf(); }
				else {
					cout << "\nInvalid choice. Please enter one of the provided options\n\n";
					break;
				}
			}
			break;

		case('3')://Add customer
			if (pharmacies == nullptr) {
				cout << "There are no pharamcies in the system. Please add a pharmacy first";
				break;
			}
			cout << "\nWhich pharmacy would you like to add customer to?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmaciesSize);
			if (chosenPharmacy != -1) {
				pharmacies[chosenPharmacy].addCustomer();
			}
			break;

		case('4')://Display available medication
			if (pharmacies == nullptr) {
				cout << "There are no pharamcies in the system. Please add a pharmacy first";
				break;
			}
			cout << "\nWhich pharmacy would you like to display its medication in stock?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmaciesSize);
			if (chosenPharmacy != -1) {
				pharmacies[chosenPharmacy].displayMedications();
			}
			else {
				cout << "\nInvalid choice. Please enter one of the provided options";
			}
			break;

		case('5'): //Remove a medication from a pharmacy
			if (pharmacies == nullptr) {
				cout << "There are no pharamcies in the system. Please add a pharmacy first";
				break;
			}
			cout << "\nWhich pharmacy would you like to remove a medication from?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmaciesSize);
			if (chosenPharmacy != -1) {
				cout << "Would you like to remove a prescription medicine (p) or an Off the shelf medicine (o)?: ";
				cin >> medicineChoice;
				if (medicineChoice == 'p' || medicineChoice == 'P') { pharmacies[chosenPharmacy].removePrescription(); }
				else if (medicineChoice == 'o' || medicineChoice == 'O') { pharmacies[chosenPharmacy].removeOfftheshelf(); }
				else {
					cout << "\nInvalid choice. Please enter one of the provided options\n\n";
					break;
				}
			}
			else {
				cout << "\nInvalid choice. Please enter one of the provided options";
			}
			break;
		case('6'): //Display customers
			if (pharmacies == nullptr) {
				cout << "There are no pharamcies in the system. Please add a pharmacy first";
				break;
			}
			cout << "\nWhich pharmacy would you like to display its customers?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmaciesSize);
			if (chosenPharmacy != -1) {
				pharmacies[chosenPharmacy].displayCustomers();
			}
			break;
		default:
			cout << "\nInvalid input! Please enter a valid choice";
		}
	}
	return 0;
}
