#include <iostream>
#include <string>
#include <cctype>
#include "Customer.h"

int Customer::nextId = 1;
using namespace std;

// Default Constructor
Customer::Customer() : Customer_Name("None"), Customer_ID(nextId++) {}

// Constructor to initialize customer attributes
Customer::Customer(string Customer_Name, int Customer_ID, string email_, string city_, string mobile_no_, string street_name_) : Customer_Name(Customer_Name), Customer_ID(Customer_ID), Address(email_, city_, mobile_no_, street_name_) {

	setCustomer_Name(Customer_Name);
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

//// Setter for Address
void Customer::setAddress(string email,string city,string mobile_no,string street_name) {
	Address.setEmail(email);
	Address.setCity(city);
	Address.setMobile(mobile_no);
	Address.setStreet(street_name);
}
// Getter for Customer_Name
string Customer::getCustomer_Name() {
	return Customer_Name;
}

// Getter for Customer_ID
int Customer::getCustomer_ID() const {
	return Customer_ID;
}

// Member Function to Display customer information
void Customer::printCustomerInfo() {
	cout << "\nName: " << getCustomer_Name() << endl
		<< "ID: " << getCustomer_ID() << endl;
	Address.printAddress();
}