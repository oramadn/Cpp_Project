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

void addPharmacy(Pharmacy& obj) {
	string stringInput;

	cout << "\nPlease enter pharmacy name: ";
	cin >> stringInput;
	obj.setName(stringInput);
}

int choosePharmacy(Pharmacy pharmacies[], int pharmacyCnt) {
	cout << "\nChoose a pharmacy (enter the number):\n";
	for (int i = 0; i < pharmacyCnt; i++) {
		cout << i << ". " << pharmacies[i].getName() << endl;
	}

	int pharmacyChoice;
	cin >> pharmacyChoice;

	if (pharmacyChoice >= 0 && pharmacyChoice <= pharmacyCnt) {
		return pharmacyChoice;
	}
	else {
		cout << "Invalid option. Please choose a valid pharmacy." << endl;
		return -1; //error
	}
}

int main() {
	
	/*Prescription pre("bob","wow",2.1,1,10,15,2001,123123,3,20,12,2013);
	pre.printPrescription();*/

	/*OffTheShelf off("bob", "wow", 2.1, 1, 10, 15, 2001, 123123, true, 20, 12, 2013);
	off.printOffTheShelf();*/

	//Program starts here
	Pharmacy pharmacies[10];
	int pharmacyCnt = 0, chosenPharmacy = -1;
	char choice;
	cout << "\nManagement system initiated";
	while (1) { //Running the program indefinitely until an 'x' is inputted
		cout << "\n\nPlease choose the required operation:\n(1) Add pharmacy\n(2) Add medication\n(3) Add customer\n(4) Display medication\n(5) Remove a medication from a pharmacy\n (6) Display list of customers\n (x) Exit\n\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case('x'):
			cout << "\nExiting program";
			return 0; 
		case('1'): //Add pharmacy
			addPharmacy(pharmacies[pharmacyCnt]);
			pharmacyCnt++;
			break;
		case('2')://Add medication
			chosenPharmacy = choosePharmacy(pharmacies, pharmacyCnt);
			if (chosenPharmacy!=-1){
				pharmacies[chosenPharmacy].addMedication();
			}
			break;
		case('3')://Add customer
			cout << "\nWhich pharmacy would you like to add customer to?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmacyCnt);
			if (chosenPharmacy != -1) {
				pharmacies[chosenPharmacy].addCustomer();
			}
			break;
		case('4')://Display available medication
			cout << "\nWhich pharmacy would you like to display its medicaiont?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmacyCnt);
			if (chosenPharmacy != -1) {
				pharmacies[chosenPharmacy].displayMedications();
			}
			break;
		case('5'): //Remove a medication from a pharmacy
			cout << "\nWhich pharmacy would you like to remove a medication from?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmacyCnt);
			if (chosenPharmacy != -1) {
				cout << "\nWhich medication would you like to get removed? (enter number)\n";
				pharmacies[chosenPharmacy].removeMedication();
			}
			break;
		case('6'): //Display customers
			cout << "\nWhich pharmacy would you like to display its customers?\n";
			chosenPharmacy = choosePharmacy(pharmacies, pharmacyCnt);
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
