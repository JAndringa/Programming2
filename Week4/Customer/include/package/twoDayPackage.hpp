//==============================================================
// Filename : twoDayPackage.hpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This header file contains the declaration of the TwoDayPackage class,
// which is a derived class of the Package class.

#ifndef TWODAYPACKAGE_HPP
#define TWODAYPACKAGE_HPP

#include "package.hpp" // Include the base class header file

// TwoDayPackage class declaration, derived from Package class
class TwoDayPackage : public Package {
public:
    // Inherit constructor from the Package class
    using Package::Package;

    // Virtual member function that calculates the cost of the two-day package.
    double calculateCost() override;

    // Virtual destructor
    ~TwoDayPackage() override = default;

};

#endif //TWODAYPACKAGE_HPP
