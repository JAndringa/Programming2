//==============================================================
// Filename    : main.cpp
// Authors     : Jibbe Andringa S2336219
// Group       : 12
// License     : N.A.
// Description : 
//==============================================================
#include <string.h>

#include "List.h"

void fillList(List<char>* list, std::string word){
    for(auto letter : word){
        list->insertAtBack(letter);
    }
}

int main() {
    List list1 = List<char>();
    List list2 = List<char>();
    fillList(&list1, "singlylinkedlist");
    fillList(&list2, "abcdefg");

    list1.print();
    list2.print();

    List list3 = List<char>();
    List list4 = List<char>();
    fillList(&list3, "hijklmnop");
    fillList(&list4, "qrstuvw");

    list2.concatenate(&list3);
    list2.concatenate(&list4);

    list2.print();
    return 0;
}
