// =============================================================================
// Filename: customer.hpp
// Authors: Jibbe Andringa S2336219
// Group: 12
// License: N.A.
// Description: Header file for the Customer class.
// =============================================================================

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

// The Customer class represents a customer of a business. The class has two
// member variables: name and address, both of type std::string. The class has
// a constructor that takes the customer's name and address as arguments, as
// well as getter methods to retrieve the name and address.
class Customer {
protected:
    std::string name; // Member variable to store customer's name.
    std::string address; // Member variable to store customer's address.

public:
// Constructor that takes customer's name and address as arguments.
    explicit Customer(std::string name, std::string address);

// Virtual destructor to ensure proper destruction of derived classes.
    virtual ~Customer() = default;

// Getter method to retrieve customer's name.
    std::string getName();

// Getter method to retrieve customer's address.
    std::string getAddress();

};

#endif // CUSTOMER_HPP