//==============================================================
// Filename : package.hpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This header file contains the declaration of the Package class,
// which is a base class for different types of packages.
//==============================================================

#ifndef PACKAGE_HPP
#define PACKAGE_HPP

#include <string>

class Package {
private:
    std::string senderName;
    std::string senderAddress;
    std::string receiverName;
    std::string receiverAddress;
protected:
    double weight;
public:
    // Constructor that initializes the member variables of the Package class
    explicit Package(std::string senderName, std::string senderAddress, std::string receiverName,
                     std::string receiverAddress, double weight);


    // Virtual destructor
    virtual ~Package() = default;

    // Virtual member function that calculates the cost of the package.
    // This is a pure virtual function, which means that any class derived from the Package class
    // must provide its own implementation.
    virtual double calculateCost() = 0;
};

#endif //PACKAGE_HPP