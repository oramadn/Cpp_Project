#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Customer {
private:
	//Data Members
	static int nextId; // variable to store the next available ID
	int Customer_ID;
	string Customer_Name;
	string Phone_Number;
	string Address;

public:
	Customer();
	//Constructor
	Customer(string Customer_Name, int Customer_ID, string Phone_Number, string Address);

	//Setters
	void setCustomer_Name(string Customer_Name);
	void setPhone_Number(string Phone_Number);
	void setAddress(string Address);

	//Getters
	string getCustomer_Name();
	int getCustomer_ID()const;
	string getPhone_Number();
	string getAddress();

	//Member Function to Display customer information
	void printCustomerInfo();
};