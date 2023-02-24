//==============================================================
// Filename    : main.cpp
// Authors     : Jibbe Andringa S2336219
// Group       : 12
// License     : N.A.
// Description : 
//==============================================================
#include <string.h>
#include "List.h"

/**
 * @brief A function that takes a List object and a string, and populates
 * the list with each character of the string.
 *
 * @param list  a pointer to a List object of characters
 * @param word  a string to populate the List with
 */

void fillList(List<char>* list, std::string word){
    for(auto letter : word){
        list->insertAtBack(letter);
    }
}

/**
 * @brief The main function and starting point of the program.
 */
int main() {
    List list1 = List<char>();  // create a new List object of characters
    List list2 = List<char>();  // create another new List object of characters
    fillList(&list1, "singlylinkedlist");  // fill the first list with a string of characters
    fillList(&list2, "abcdefg");           // fill the second list with a string of characters

    list1.print();  // print the first list
    list2.print();  // print the second list

    List list3 = List<char>();  // create a third List object of characters
    List list4 = List<char>();  // create a fourth List object of characters
    fillList(&list3, "hijklmnop");  // fill the third list with a string of characters
    fillList(&list4, "qrstuvw");    // fill the fourth list with a string of characters

    list2.concatenate(&list3);  // concatenate the second and third lists
    list2.concatenate(&list4);  // concatenate the result with the fourth list

    list2.print();  // print the final concatenated list
    return 0;
}
