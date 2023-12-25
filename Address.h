#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>

using namespace std;

class Address {
private:
	string email_;
	string city_;
	string mobile_no_;
	string street_name_;

public:
	//Deafult constructor 
	Address();

	//Default parametrized constructor
	Address(string email_, string city_, string mobile_no_, string street_name_);

	//Copy constructor
	Address(const Address& c);

	//Setters of Address
	void setEmail(string email);
	void setCity(string city);
	void setMobile(string mobile_no);
	void setStreet(string street_name);

	//Getters of Address
	string getEmail() const;
	string getCity() const;
	string getMobile() const;
	string getStreet() const;

	//Display of Address
	void printAddress() const;
};

#endif // ADDRESS_H
