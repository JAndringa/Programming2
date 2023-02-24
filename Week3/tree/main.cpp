//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================
#include <array>
#include <string.h>
#include "Tree.h"

int getKeyFromUser() {
    std::string input;
    std::cout << "Please give the number you are searching for" << std::endl;
    std::cin >> input;

    bool valid = true;
    for (char c: input) {
        if (!std::isdigit(c)) {
            valid = false;
            break;
        }
    }

    if (valid) {
        try {
            return std::stoi(input);
        }
        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << "Error: input is not a valid number. Please try again." << std::endl;
    return getKeyFromUser();
}

int main() {
    Tree tree = Tree<int>();
    std::array<int, 10> numbers = {{32, 12, 35, 63, 51, 65, 92, 1, 9, 7}};
    for (auto number: numbers) {
        tree.insertNode(number);
    }
    if (tree.search(getKeyFromUser())) {
        std::cout << "Your number was found!!!" << std::endl;
    }
    else {
        std::cout << "Your number was not present." << std::endl;
    }
    tree.outputTree();
    return 0;
}
