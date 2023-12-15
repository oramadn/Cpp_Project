//Omar Ramadan 20190692
//Omar Ashraf AlQerm 20210894
//Mohammad Toubasi 20220496
//Yousef Mahmoud 20220448

//Github link: https://github.com/oramadn/Cpp_Project

#include<iostream>
#include<string>
#include "Customer.h"
#include "Medication.h"
#include "Address.h"
#include "Date.h"
using namespace std;

void addMedication(Medication& obj) {
	string stringInput;
	float floatInput;
	int intInput;

	cout << "\nPlease enter the following information:\n";
	cout << "Name: ";
	cin >> stringInput;
	obj.setName(stringInput);

	cout << "Description: ";
	cin >> stringInput;
	obj.setDescription(stringInput);

	cout << "Price: ";
	cin >> floatInput;
	obj.setPrice(floatInput);

	cout << "Quantity: ";
	cin >> intInput;
	obj.setQuantity_in_Stock(intInput);

	int year, month, day;
	while (true) {
		cout << "Expiry date (YYYY-MM-DD): ";
		cin >> stringInput;

		if (stringInput == "x" || stringInput == "X") {
			cout << "Cancelling operation." << endl;
			return;  // Cancel the operation
		}

		// Parse the string to extract year, month, and day
		if (sscanf_s(stringInput.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
			// Correct format
			break;
		}
		else {
			// Wrong, try again
			cout << "Invalid date format. Try again enter 'x' to cancel" << endl;
		}
	}
	obj.setExpiry_Date(stringInput);

	cout << "Barcode: ";
	cin >> intInput;
	obj.setbarcode(intInput);
	return;
}
void addCustomer(Customer& obj) {
	string stringInput;
	int intInput;

	cout << "\nPlease enter the following information:\n";
	cout << "Name: ";
	cin >> stringInput;
	obj.setCustomer_Name(stringInput);

	/*cout << "ID: ";
	cin >> intInput;
	obj.set(stringInput);*/

	cout << "Phone number: ";
	cin >> stringInput;
	obj.setPhone_Number(stringInput);

	cout << "Address: ";
	cin >> stringInput;
	obj.setAddress(stringInput);
	return;
}

int main() {
	//Testing default constructors
	Customer customer1;
	//customer1.printCustomerInfo();

	Medication med1;
	//med1.display_medication_information();

	Date add1;
	add1.printDate();
	
	//Program starts here
	char choice;
	cout << "\nManagement system initiated";
	while (1) { //Running the program indefinitely until an 'x' is inputted
		cout << "\n\nPlease choose the required operation:\n(1) Add medication\n(2) Add customer\n(3) Make purchase\n(4) Display available medication\n(5) Calculate and display total sales and profit\n(x) Exit\n\nYour choice: ";
		cin >> choice;
		switch (choice) {
		case('x'):
			cout << "\nExiting program";
			return 0; 
		case('1'): //Add medication
			addMedication(med1);
			break;
		case('2')://Add customer
			addCustomer(customer1);
			break;
		case('3')://Make purchase
			cout << "\nWhat would you like to buy?";
			break;
		case('4')://Display available medication
			med1.display_medication_information(); //This will print an array later on
			break;
		case('5'): //Calculate and display total sales and profit
			cout << "\nProfit goes here";
			break;
		default:
			cout << "\nInvalid input! Please enter a valid choice";
		}
	}
	return 0;
}
