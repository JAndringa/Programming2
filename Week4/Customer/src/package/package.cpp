// ==============================================================
// Filename : package.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the implementation of the Package class,
// which is a base class for different types of packages.
// ==============================================================

#include "../../include/package/package.hpp" // Include the header file for the class

// Constructor that initializes the member variables of the Package class
Package::Package(Customer& sender, Customer& receiver, double weight)
        : sender(sender), receiver(receiver), weight(weight) {}

// Getter function for the sender member variable
Customer& Package::getSender() {
    return sender;
}

// Getter function for the receiver member variable
Customer& Package::getReceiver() {
    return receiver;
}