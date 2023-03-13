// ==============================================================
// Filename : privateCustomer.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : Implementation file for the PrivateCustomer class
// ==============================================================

#include "../../include/customer/privateCustomer.hpp" // Include the header file for the class

// Constructor for the PrivateCustomer class, which calls the constructor for the base class (Customer)
PrivateCustomer::PrivateCustomer(std::string name, std::string address) : Customer(name, address) {
}
