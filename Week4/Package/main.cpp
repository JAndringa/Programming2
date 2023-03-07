// ==============================================================
// Filename : main.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This program creates a list of packages that includes
// two types of packages: TwoDayPackage and OvernightPackage,
// and prints the cost of each package.
// ==============================================================

#include <iostream>
#include <list>
#include "include/twoDayPackage.hpp"
#include "include/overnightPackage.hpp"

// This function takes a list of Package pointers as input and prints
// the cost of each package in the list using the calculateCost() method.
void printCosts(const std::list<Package *> &packages) {
    for (const auto package: packages) {
        std::cout << package->calculateCost() << std::endl; // calculateCost() method calculates the cost of the package
        delete package; // free memory allocated for the package
    }
}

int main() {
    // Create a list of packages that includes two types of packages: TwoDayPackage and OvernightPackage
    std::list<Package *> packages = {
            new TwoDayPackage("Alice", "123 Main St", "Bob", "456 Oak St", 5.0),
            new OvernightPackage("Carol", "789 Elm St", "Dave", "012 Pine St", 2.0),
            new TwoDayPackage("Eve", "345 Maple Ave", "Frank", "678 Cedar Rd", 3.5),
            new OvernightPackage("Grace", "901 Walnut Blvd", "Harry", "234 Cherry Ln", 6.0)
    };

    printCosts(packages); // print the cost of each package
    return 0;

}