
#include <string>
#include "Address.h"  
using namespace std;  

class Customer {
private:
    static int nextId;
    string name;
    int customerId;
    Address address;  

public:
    // Constructor
    Customer(const string& name, const Address& address);

    // Setters
    void setName(const string& name);
    void setAddress(const Address& address);

    // Getters
    string getName() const;
    int getCustomerId() const;
    Address getAddress() const;

    // Method to display customer information
    void printCustomerInfo() const;
};


