// ==============================================================
// Filename : customer.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Implementation file for the Customer class
// ==============================================================

#include "../../include/customer/customer.hpp" // Include the header file for the class

// Constructor for the Customer class, which initializes the name and address variables
Customer::Customer(std::string name, std::string address) : name(name), address(address) {}

// Getter function for the name variable
std::string Customer::getName() {
    return name;
}

// Getter function for the address variable
std::string Customer::getAddress() {
    return address;
}
