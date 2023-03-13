// =============================================================================
// Filename: package.hpp
// Authors: Jibbe Andringa S2336219
// Group: 12
// License: N.A.
// Description: This header file contains the declaration of the Package class,
// which is a base class for different types of packages.
// =============================================================================

#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>
#include "../customer/customer.hpp"

class Package {
private:
    Customer& sender; // Member variable to store the sender of the package
    Customer& receiver; // Member variable to store the receiver of the package
protected:
    double weight; // Member variable to store the weight of the package
public:
// Constructor that initializes the member variables of the Package class
    explicit Package(Customer& sender, Customer& receiver, double weight);

// Virtual destructor
    virtual ~Package() = default;

// Virtual member function that calculates the cost of the package.
// This is a pure virtual function, which means that any class derived from the Package class
// must provide its own implementation.
    virtual double calculateCost() = 0;

// Getter method to retrieve the sender of the package
    Customer& getSender();

// Getter method to retrieve the receiver of the package
    Customer& getReceiver();

};

#endif // PACKAGE_HPP
