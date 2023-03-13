//==============================================================
// Filename : overnightPackage.hpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This file contains the declaration of the OvernightPackage class,
// which is derived from the Package class.
//==============================================================

#ifndef OVERNIGHTPACKAGE_HPP
#define OVERNIGHTPACKAGE_HPP

#include "package.hpp"

class OvernightPackage : public Package {
public:
    // Inheriting the constructors of the base class.
    using Package::Package;

    // Default destructor.
    ~OvernightPackage() override = default;

    // Member function that calculates the cost of the overnight package.
    double calculateCost() override;

};

#endif //OVERNIGHTPACKAGE_HPP