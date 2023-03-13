//==============================================================
// Filename : twoDayPackage.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the implementation of the TwoDayPackage class,
// which is derived from the Package class.
//==============================================================

#include "../../include/package/twoDayPackage.hpp"

// Member function that calculates the cost of the two-day package.
// The cost is calculated as the weight times a flat rate of 2.5 plus an additional fixed fee of 5.
double TwoDayPackage::calculateCost() {
    return 2.5 * weight + 5;
}