#include <iostream>
#include <string>
using namespace std;

class Medication
{
private:
	string name_;
	string description_;
	string expiry_date_;
	float price_;
	int quantity_;
	int barcode_;

public:
	Medication();
	Medication(string name_, string description_, float price_, int quantity_, string expiry_date_, int barcode_);
	Medication(const Medication& c);
	void setName(std::string name_);
	void setDescription(std::string description_);
	void setPrice(float price_);
	void setQuantity_in_Stock(int quantity_);
	void setExpiry_Date(string expiry_date_);
	void setbarcode(int barcode_);
	std::string getName();
	std::string getDescription();
	double getPrice();
	int getQuantity();
	string getExpiry_Date();
	int getBarcode();
	void display_medication_information();
};

