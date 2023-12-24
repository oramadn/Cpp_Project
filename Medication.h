#include <iostream>
#include <string>
using namespace std;

class Medication
{
private:
	static int nextId; // variable to store the next available ID
	int id_; 
	string name_;
	string description_;
	string expiry_date_;
	float price_;
	int quantity_;
	int barcode_;

public:
	Medication();
	Medication(int id_, string name_, string description_, float price_, int quantity_, string expiry_date_, int barcode_);
	Medication(const Medication& c);
	void setName(string name_);
	void setDescription(string description_);
	void setPrice(float price_);
	void setQuantity_in_Stock(int quantity_);
	void setExpiry_Date(string expiry_date_);
	void setbarcode(int barcode_);
	int getId() const;
	string getName();
	string getDescription();
	double getPrice();
	int getQuantity();
	string getExpiry_Date();
	int getBarcode();
	void display_medication_information();
};

