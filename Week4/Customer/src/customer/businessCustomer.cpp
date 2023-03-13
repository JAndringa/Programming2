// ==============================================================
// Filename : businessCustomer.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Implementation file for the BusinessCustomer class
// ==============================================================

#include "../../include/customer/businessCustomer.hpp" // Include the header file for the class

// Constructor for the BusinessCustomer class, which calls the constructor for the base class (Customer) and initializes the contact person
BusinessCustomer::BusinessCustomer(std::string name, std::string address, Customer contactPerson) :
        Customer(name, address),
        contactPerson(contactPerson) {
}

// Member function to get the contact person for the business customer
Customer BusinessCustomer::getContactPerson() {
    return contactPerson;
}