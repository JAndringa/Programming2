//==============================================================
// Filename : twoDayPackage.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the implementation of the TwoDayPackage class,
// which is derived from the Package class.
//==============================================================

#include "../include/twoDayPackage.hpp"

// Member function that calculates the cost of the two day package.
double TwoDayPackage::calculateCost() {
    return 2.5 * weight + 5;
}