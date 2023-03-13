// =============================================================================
// Filename: businessCustomer.hpp
// Authors: Jibbe Andringa S2336219
// Group: 12
// License: N.A.
// Description: Header file for the BusinessCustomer class, which is derived from
// the Customer class.
// =============================================================================

#ifndef BUSINESSCUSTOMER_HPP
#define BUSINESSCUSTOMER_HPP

#include "customer.hpp" // Include the base class header file.

// The BusinessCustomer class represents a customer who is a business. The class
// is derived from the Customer class, which has member variables for the
// customer's name and address. In addition, the BusinessCustomer class has a
// member variable for the contact person for the business. The class has a
// constructor that takes the customer's name, address, and contact person as
// arguments, and a getter method to retrieve the contact person.
class BusinessCustomer : public Customer {
private:
    Customer contactPerson; // Member variable to store the contact person for the business customer.

public:
// Constructor that takes customer's name, address, and contact person as
// arguments and passes the name and address to the base class constructor.
    explicit BusinessCustomer(std::string name, std::string address, Customer contactPerson);

// Destructor for the class.
    ~BusinessCustomer() override = default;

// Getter method to retrieve the contact person for the business customer.
    Customer getContactPerson();

};

#endif // BUSINESSCUSTOMER_HPP