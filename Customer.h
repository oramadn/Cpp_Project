#ifndef CUSTOMER_H  // Include guard
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "Address.h"
using namespace std;

class Customer {
private:
	//Data Members
	static int nextId; // variable to store the next available ID
	int Customer_ID;
	string Customer_Name;
	Address Address;

public:
	Customer();
	//Constructor
	Customer(string Customer_Name, int Customer_ID, string email_, string city_, string mobile_no_, string street_name_);

	//Setters
	void setCustomer_Name(string Customer_Name);
	void setAddress(string email, string city, string mobile_no, string street_name);

	//Getters
	string getCustomer_Name();
	int getCustomer_ID()const;
	//string getAddress();

	//Member Function to Display customer information
	void printCustomerInfo();
};

#endif