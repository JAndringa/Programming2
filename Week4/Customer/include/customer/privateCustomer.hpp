// =============================================================================
// Filename: privateCustomer.hpp
// Authors: Jibbe Andringa S2336219
// Group: 12
// License: N.A.
// Description: Header file for the PrivateCustomer class, which is derived from
// the Customer class.
// =============================================================================

#ifndef PRIVATECUSTOMER_HPP
#define PRIVATECUSTOMER_HPP

#include "customer.hpp" // Include the base class header file.

// The PrivateCustomer class represents a private customer. The class is
// derived from the Customer class, which has member variables for the customer's
// name and address. The PrivateCustomer class has a constructor that takes the
// customer's name and address as arguments and passes them to the base class
// constructor.
class PrivateCustomer : public Customer {
public:
// Constructor that takes customer's name and address as arguments and passes them to the base class constructor.
    explicit PrivateCustomer(std::string name, std::string address);
};

#endif // PRIVATECUSTOMER_HPP
