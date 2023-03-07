//==============================================================
// Filename : overnightPackage.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the implementation of the OvernightPackage class,
// which is derived from the Package class.
//==============================================================

#include "../include/overnightPackage.hpp"

// Member function that calculates the cost of the overnight package.
double OvernightPackage::calculateCost() {
    return 1.1 * weight * weight + 2.5 * weight + 5;
}