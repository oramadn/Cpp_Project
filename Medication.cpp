#include "Medication.h"
using namespace std;

Medication::Medication() {
	name_ = "none";
	description_ = "none";
	price_ = 0.0;
	quantity_ = 0;
	expiry_date_ = "0";
	barcode_ = 0;
}

Medication::Medication(string name_, string description_, float price_, int quantity_, string expiry_date_, int barcode_) :
	name_(name_), description_(description_), price_(price_), quantity_(quantity_), expiry_date_(expiry_date_), barcode_(barcode_){}

Medication::Medication(const Medication& c) //Copy constructor
{
	cout << "Medication copy constructer used" << endl;
	name_ = c.name_;
	description_ = c.description_;
	price_ = c.price_;
	quantity_ = c.quantity_;
	expiry_date_ = c.expiry_date_;
	barcode_ = c.barcode_;
}

void Medication::setName(string name_)
{
	this->name_ = name_;
}
void Medication::setDescription(string description_)
{
	this->description_ = description_;
}
void Medication::setPrice(float price_)
{
	this->price_ = price_;
}
void Medication::setQuantity_in_Stock(int quantity_)
{
	this->quantity_ = quantity_;
}
void Medication::setExpiry_Date(string expiry_date_)
{
	this->expiry_date_ = expiry_date_;
}
void Medication::setbarcode(int barcode_)
{
	this->barcode_ = barcode_;
}
string Medication::getName()
{
	return name_;
}
string Medication::getDescription()
{
	return description_;
}
double Medication::getPrice()
{
	return price_;
}
int Medication::getQuantity()
{
	return quantity_;
}
string Medication::getExpiry_Date()
{
	return expiry_date_;
}
int Medication::getBarcode()
{
	return barcode_;
}
void Medication::display_medication_information()
{
	cout << "Name: " << getName() << endl << "ID: " << getDescription() << endl << "Number: " << getPrice() << endl << "Address: " << getQuantity() << endl << "Expiry date: "<< getExpiry_Date() << endl << "Barcode: "<< getBarcode() << endl;
}