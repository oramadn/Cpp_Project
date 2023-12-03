#include <iostream>
#include <string>
#include <cctype>
#include "Customer.h"

using namespace std;

// Default Constructor
Customer::Customer() : Customer_Name("None"), Customer_ID(0), Phone_Number("0000000000"), Address("None") {
}

// Constructor to initialize customer attributes
Customer::Customer(string Customer_Name, int Customer_ID, string Phone_Number, string Address) : Customer_Name(Customer_Name), Customer_ID(Customer_ID), Phone_Number(Phone_Number), Address(Address) {

	setCustomer_Name(Customer_Name);
	setPhone_Number(Phone_Number);
}

// Setter for Customer_Name
void Customer::setCustomer_Name(string Customer_Name) {

	//Handle error: Checking if all characters are alphabets, No numbers.
	int flag = 0;
	while (flag == 0) {
		for (char ch : Customer_Name) {
			if (isdigit(ch)) {
				cout << "Invalid input. Name should not contain numbers,Please enter a new Name: \n";
				cin >> Customer_Name;
				this->Customer_Name = Customer_Name;
				break;
			}
			if (!isdigit(ch) && ch == Customer_Name.back()) { flag = 1; }
		}
	}
}

// Setter for Phone_Number
void Customer::setPhone_Number(string Phone_Number) {

	// Handle error: the phone number is not 10 digits long
	while (Phone_Number.length() != 10) {
		cout << "Invalid input. Phone number must be 10 digits, Please enter a new Phone Number: \n";
		cin >> Phone_Number;
		this->Phone_Number = Phone_Number;
	}

	// Handle error: the phone number contains non-numeric characters
	int flag = 0;
	while (flag == 0) {
		for (char ch : Phone_Number) {
			if (!isdigit(ch)) {
				cout << "Invalid input. Phone number must contain only digits,Please enter a new Phone Number:\n";
				cin >> Phone_Number;
				this->Phone_Number = Phone_Number;
				break;
			}
			if (isdigit(ch) && ch == Phone_Number.back()) { flag = 1; }
		}
	}
}


// Setter for Address
void Customer::setAddress(string Address) {
	this->Address = Address;
}
// Getter for Customer_Name
string Customer::getCustomer_Name() {
	return Customer_Name;
}

// Getter for Customer_ID
int Customer::getCustomer_ID() const {
	return Customer_ID;
}

// Getter for Phone_Number
string Customer::getPhone_Number() {
	return Phone_Number;
}

// Getter for Address
string Customer::getAddress() {
	return Address;
}

// Member Function to Display customer information
void Customer::printCustomerInfo() {
	cout << "\nName: " << getCustomer_Name() << endl
		<< "ID: " << getCustomer_ID() << endl
		<< "Number: " << getPhone_Number() << endl
		<< "Address: " << getAddress() << endl << endl;
}