#ifndef MEDICATION_H 
#define MEDICATION_H

#include <iostream>
#include <string>
using namespace std;
#include "Date.h"

class Pharmacy;

class Medication
{
private:
	static int nextId; // variable to store the next available ID
	int id_; 
	string name_;
	string description_;
	Date expiry_date_;
	float price_;
	int quantity_;
	int barcode_;

public:
	Medication();
	Medication(string name_, string description_, float price_, int quantity_, int day, int month, int year, int barcode_);
	Medication(const Medication& c);
	void setName(string name_);
	void setDescription(string description_);
	void setPrice(float price_);
	void setQuantity_in_Stock(int quantity_);
	void setbarcode(int barcode_);
	int getId() const;
	string getName();
	string getDescription();
	double getPrice();
	int getQuantity();
	void setDate(int day, int month, int year);
	int getBarcode();
	void display_medication_information();
	friend class Pharmacy;
};

#endif

