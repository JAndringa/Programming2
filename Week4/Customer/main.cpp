//==============================================================
// Filename : main.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This program is a basic implementation of a package delivery system. It includes classes for customers
// and packages, and calculates the cost of each package based on weight and the type of package (two-day or overnight).
// The program also prints out the customer information and a list of contact persons for Christmas cards.
//==============================================================

// Include necessary headers
#include <iostream>
#include <list>
#include <unordered_set>
#include "include/customer/customer.hpp"
#include "include/customer/privateCustomer.hpp"
#include "include/customer/businessCustomer.hpp"
#include "include/package/package.hpp"
#include "include/package/overnightPackage.hpp"
#include "include/package/twoDayPackage.hpp"

// This function takes a list of Package pointers as input and prints
// the cost of each package in the list using the calculateCost() method.
void printCosts(const std::list<Package *> &packages) {
    for (const auto package: packages) {
        std::cout << package->calculateCost() << std::endl; // calculateCost() method calculates the cost of the package
    }
}

// This function takes a list of Customer pointers as input and prints
// the name and address of each customer in the list.
void printCustomerInfo(const std::list<Customer *> &customers) {
    for (const auto customer: customers) {
        std::cout << "Name: " << customer->getName() << std::endl; // getName() method returns the name of the customer
        std::cout << "Address: " << customer->getAddress()
                  << std::endl; // getAddress() method returns the address of the customer
        std::cout << std::endl;
    }
}

// This function takes a list of Package pointers as input and prints
// the contact persons of all BusinessCustomers that are involved in
// the packages. Only unique contact persons are printed.
void printChristmasCardContactPersons(const std::list<Package *> &packages) {
    std::unordered_set<std::string> contactPersons; // temporary list to keep track of which contact persons were already printed

    // Loop through each package in the list
    for (const auto package: packages) {
        // Check if the sender or receiver of the package is a BusinessCustomer
        auto businessCustomerSender = dynamic_cast<BusinessCustomer *>(&package->getSender()); // dynamic_cast is used to cast a Customer pointer to a BusinessCustomer pointer
        auto businessCustomerReceiver = dynamic_cast<BusinessCustomer *>(&package->getReceiver());

        if (businessCustomerSender !=
            nullptr) { // If the sender is a BusinessCustomer, add their contact person to the temporary list
            contactPersons.insert(
                    businessCustomerSender->getContactPerson().getName()); // getContactPerson() method returns the contact person of the BusinessCustomer
        }

        if (businessCustomerReceiver !=
            nullptr) { // If the receiver is a BusinessCustomer, add their contact person to the temporary list
            contactPersons.insert(businessCustomerReceiver->getContactPerson().getName());
        }
    }

    // Print the list of contact persons
    std::cout << "Christmas card recipients:" << std::endl;
    for (const auto &name: contactPersons) {
        std::cout << "- " << name << std::endl;
    }
}


int main() {
    // Example PrivateCustomers
    PrivateCustomer alice("Alice", "123 Main St.");
    PrivateCustomer bob("Bob", "456 Maple Ave.");
    PrivateCustomer charlie("Charlie", "789 Oak St.");

    // Example BusinessCustomers
    BusinessCustomer delta("Delta Airlines", "Atlanta, GA", Customer("John Doe", "123 Main St."));
    BusinessCustomer microsoft("Microsoft", "Redmond, WA", Customer("Jane Smith", "456 Maple Ave."));
    BusinessCustomer coca_cola("Coca-Cola", "Atlanta, GA", Customer("Bob Johnson", "789 Oak St."));

    // List of customers
    std::list<Customer *> customers = {
            &alice, &bob, &charlie, &delta, &microsoft, &coca_cola
    };

    // Create a list of packages that includes two types of packages: TwoDayPackage and OvernightPackage
    std::list<Package *> packages = {
            new TwoDayPackage(alice, bob, 5.0),
            new OvernightPackage(charlie, delta, 2.0),
            new TwoDayPackage(microsoft, alice, 3.5),
            new OvernightPackage(coca_cola, bob, 6.0),
            new TwoDayPackage(delta, bob, 1.5),
            new OvernightPackage(charlie, microsoft, 4.0),
            new TwoDayPackage(microsoft, coca_cola, 2.0)
    };

    // Add customers who are not linked to any package
    PrivateCustomer daniel("Daniel", "1234 Pine St.");
    BusinessCustomer google("Google", "Mountain View, CA", Customer("Larry Page", "1600 Amphitheatre Pkwy"));

    customers.push_back(&daniel);
    customers.push_back(&google);

    // Print information about the customers and packages
    printCosts(packages);
    printCustomerInfo(customers);
    printChristmasCardContactPersons(packages);

    return 0;
}
