#include <iostream>
#include "Address.h"

using namespace std;

//Deafult constructor
Address::Address() {
	email_ = "No email";
	city_ = "No city";
	mobile_no_ = "0";
	street_name_ = "No name";
}

// Parameterized constructor
Address::Address(string email_, string city_, string mobile_no_, string street_name_):
	email_(email_), city_(city_), mobile_no_(mobile_no_), street_name_(street_name_) {}

// Copy constructor
Address::Address(const Address& c) //Copy constructor
{
	cout << "Medication copy constructer used" << endl;
	email_ = c.email_;
	city_ = c.city_;
	mobile_no_ = c.mobile_no_;
	street_name_ = c.street_name_;
}

void Address::setEmail(string email) {
	email_ = email;
}

void Address::setCity(string city) {
	city_ = city;
}

void Address::setMobile(string mobile_no_) {

	// Handle error: the phone number is not 10 digits long
	while (mobile_no_.length() != 10) {
		cout << "Invalid input. Phone number must be 10 digits, Please enter a new Phone Number: \n";
		cin >> mobile_no_;
		this->mobile_no_ = mobile_no_;
	}

	// Handle error: the phone number contains non-numeric characters
	int flag = 0;
	while (flag == 0) {
		for (char ch : mobile_no_) {
			if (!isdigit(ch)) {
				cout << "Invalid input. Phone number must contain only digits,Please enter a new Phone Number:\n";
				cin >> mobile_no_;
				this->mobile_no_ = mobile_no_;
				break;
			}
			if (isdigit(ch) && ch == mobile_no_.back()) { 
				this->mobile_no_ = mobile_no_;
				flag = 1; }
		}
	}
}

void Address::setStreet(string street_name) {
	street_name_ = street_name;
}

string Address::getEmail() const {
	return email_;
}

string Address::getCity() const {
	return city_;
}

string Address::getMobile() const {
	return mobile_no_;
}

string Address::getStreet() const {
	return street_name_;
}

void Address::printAddress() const {
	cout << "Email: " << email_ << endl;
	cout << "City: " << city_ << endl;
	cout << "Mobile No.: " << mobile_no_ << endl;
	cout << "Street Name: " << street_name_ << endl;
}

