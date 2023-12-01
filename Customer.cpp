#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

//Default Constructor
Customer::Customer():Customer_ID(Customer_ID) {
	this->Customer_Name = '0';
	this->Phone_Number = '0';
	this->Address = '0';
}

// Constructor to initialize customer attributes.
Customer::Customer(string Customer_Name, int Customer_ID, string Phone_Number, string Address) : Customer_ID(Customer_ID) {

	this->Customer_Name = Customer_Name;
	this->Phone_Number = Phone_Number;
	this->Address = Address;
}

//Setter for Customer_Name
void Customer::setCustomer_Name(string Customer_Name) {
	this->Customer_Name = Customer_Name;
}

//Setter for Phone_Number
void Customer::setPhone_Number(string Phone_Number) {
	this->Phone_Number = Phone_Number;
}

//Setter for Address
void Customer::setAddress(string Address) {
	this->Address = Address;
}

//(No Setter for Customer_ID, Because it's const)

//Getter for Customer_Name
string Customer::getCustomer_Name() {
	return Customer_Name;
}

//Getter for Customer_ID
int Customer::getCustomer_ID()const {
	return Customer_ID;
}

//Getter for Phone_Number
string Customer::getPhone_Number() {
	return Phone_Number;
}

//Getter for Address
string Customer::getAddress() {
	return Address;
}

//Member Function to Display customer information
void Customer::printCustomerInfo() {
	cout << "\nName: " << getCustomer_Name() << endl << "ID: " << getCustomer_ID() << endl << "Number: " << getPhone_Number() << endl << "Address: " << getAddress() << endl << endl;
}