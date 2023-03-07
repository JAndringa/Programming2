//==============================================================
// Filename : package.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the implementation of the Package class,
// which is a base class for different types of packages.
//==============================================================

#include "../include/package.hpp"

// Constructor that initializes the member variables of the Package class
Package::Package(std::string senderName, std::string senderAddress, std::string receiverName,
                 std::string receiverAddress, double weight) :
        senderName(senderName),
        senderAddress(senderAddress),
        receiverName(receiverName),
        receiverAddress(receiverAddress),
        weight(weight) {
}