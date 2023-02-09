//==============================================================
// Filename :main.cpp
// Authors : Jibbe Andringa S2336219
// Group : 12
// License : N.A.
// Description : This is a simple program that performs integer division.
//==============================================================

#include <iostream>
#include "divide.hpp"

int main(void) {
    int a = 7;
    int b = 0;
    int c = divide(a, b);
    std::cout << a << "/" << b << "=" << c << std::endl;
    return 0;
}