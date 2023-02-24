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

// Function to get a valid integer key from the user
int getKeyFromUser() {
    std::string input;
    std::cout << "Please give the number you are searching for" << std::endl;
    std::cin >> input;

    // Check if the input is a valid integer
    bool valid = true;
    for (char c: input) {
        if (!std::isdigit(c)) {
            valid = false;
            break;
        }
    }

    // If the input is valid, convert it to an integer and return
    if (valid) {
        try {
            return std::stoi(input);
        }
        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    // If the input is not valid, prompt the user to try again
    std::cout << "Error: input is not a valid number. Please try again." << std::endl;
    return getKeyFromUser();
}

int main() {
    // Create an empty binary search tree
    Tree tree = Tree<int>();

    // Insert some numbers into the tree
    std::array<int, 10> numbers = {{32, 12, 35, 63, 51, 65, 92, 1, 9, 7}};
    for (auto number: numbers) {
        tree.insertNode(number);
    }

    // Prompt the user to enter a key to search for
    int key = getKeyFromUser();

    // Search for the key in the tree and print the result
    if (tree.search(key)) {
        std::cout << "Your number was found!!!" << std::endl;
    }
    else {
        std::cout << "Your number was not present." << std::endl;
    }

    // Output the tree structure
    tree.outputTree();

    return 0;
}
