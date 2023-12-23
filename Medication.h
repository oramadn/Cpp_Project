#ifndef MEDICATION_H
#define MEDICATION_H

#include "ExpiryDate.h"
#include <iostream>

class Medication {
private:
    string name_;
    string description_;
    float price_;
    int quantity_;
    ExpiryDate expiry_date_;
    int barcode_;

public:
    Medication(); // Default constructor
    Medication(string name_, string description_, float price_, int quantity_, const ExpiryDate& expiry_date_, int barcode_); // Parameterized constructor
    Medication(const Medication& c); // Copy constructor

    // Setters
    void setName(string name_);
    void setDescription(string description_);
    void setPrice(float price_);
    void setQuantity_in_Stock(int quantity_);
    void setExpiry_Date(const ExpiryDate& expiry_date_);
    void setBarcode(int barcode_);

    // Getters
    string getName();
    string getDescription();
    float getPrice();
    int getQuantity();
    ExpiryDate getExpiry_Date();
    int getBarcode();

    void display_medication_information();
};

#endif // MEDICATION_H
