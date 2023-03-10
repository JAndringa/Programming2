//==============================================================
// Filename    : main.cpp
// Authors     : Jibbe Andringa S2336219
// Group       : 12
// License     : N.A. or opensource license like LGPL
// Description : List class-template definition.
//==============================================================
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h" // ListNode class definition

template<typename NODETYPE>
class List {
public:
    // default constructor
    List() : firstPtr(nullptr), lastPtr(nullptr) {
        // empty body
    } // end List constructor

    // destructor
    ~List() {
        if (!isEmpty()) { // List is not empty
            std::cout << "Destroying nodes ...\n";

            ListNode<NODETYPE> *currentPtr{firstPtr};
            ListNode<NODETYPE> *tempPtr{nullptr};

            while (currentPtr != nullptr) { // delete remaining nodes
                tempPtr = currentPtr;
                std::cout << tempPtr->data << '\n';
                currentPtr = currentPtr->nextPtr;
                delete tempPtr;
            }
        }

        std::cout << "All nodes destroyed\n\n";
    }

    // insert node at front of list
    void insertAtFront(const NODETYPE &value) {
        ListNode<NODETYPE> *newPtr{getNewNode(value)}; // new node

        if (isEmpty()) { // List is empty
            firstPtr = lastPtr = newPtr; // new list has only one node
        }
        else { // List is not empty
            newPtr->nextPtr = firstPtr; // point new node to old 1st node
            firstPtr = newPtr; // aim firstPtr at new node
        }
    }

    // insert node at back of list
    void insertAtBack(const NODETYPE &value) {
        ListNode<NODETYPE> *newPtr{getNewNode(value)}; // new node

        if (isEmpty()) { // List is empty
            firstPtr = lastPtr = newPtr; // new list has only one node
        }
        else { // List is not empty
            lastPtr->nextPtr = newPtr; // update previous last node
            lastPtr = newPtr; // new last node
        }
    }

    // delete node from front of list
    bool removeFromFront(NODETYPE &value) {
        if (isEmpty()) { // List is empty
            return false; // delete unsuccessful
        }
        else {
            ListNode<NODETYPE> *tempPtr{firstPtr}; // hold item to delete

            if (firstPtr == lastPtr) {
                firstPtr = lastPtr = nullptr; // no nodes remain after removal
            }
            else {
                firstPtr = firstPtr->nextPtr; // point to previous 2nd node
            }

            value = tempPtr->data; // return data being removed
            delete tempPtr; // reclaim previous front node
            return true; // delete successful
        }
    }

    // delete node from back of list

    bool removeFromBack(NODETYPE &value) {
        if (isEmpty()) { // List is empty
            return false; // delete unsuccessful
        }
        else {
            ListNode<NODETYPE> *tempPtr{lastPtr}; // hold item to delete

            if (firstPtr == lastPtr) { // List has one element
                firstPtr = lastPtr = nullptr; // no nodes remain after removal
            }
            else {
                ListNode<NODETYPE> *currentPtr{firstPtr};

                // locate second-to-last element
                while (currentPtr->nextPtr != lastPtr) {
                    currentPtr = currentPtr->nextPtr; // move to next node
                }

                lastPtr = currentPtr; // remove last node
                currentPtr->nextPtr = nullptr; // this is now the last node
            }

            value = tempPtr->data; // return value from old last node
            delete tempPtr; // reclaim former last node
            return true; // delete successful
        }
    }

    // is List empty?

    bool isEmpty() const {
        return firstPtr == nullptr;
    }

    // display contents of List
    void print() const {
        if (isEmpty()) { // List is empty
            std::cout << "The list is empty\n\n";
            return;
        }

        ListNode<NODETYPE> *currentPtr{firstPtr};

        std::cout << "The list is: ";

        while (currentPtr != nullptr) { // get element data
            std::cout << currentPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
        }

        std::cout << "\n\n";
    }

    /**
     * @brief Concatenates the given list to the end of this list.
     * If the given list is empty, nothing happens.
     *
     * @param other Pointer to the list to concatenate to this list.
     */
    void concatenate(List *other) {
        if (!other->isEmpty()) {
            // Connect the last node of this list to the first node of the other list.
            lastPtr->nextPtr = other->firstPtr;

            // Update the last node pointer to the last node of the other list.
            lastPtr = other->lastPtr;
        }
        // Set the first node pointer of the other list to null to prevent
        // it from deleting nodes when its destructor is called.
        other->firstPtr = nullptr;
    }

private:
    ListNode<NODETYPE> *firstPtr{nullptr}; // pointer to first node
    ListNode<NODETYPE> *lastPtr{nullptr}; // pointer to last node

    // utility function to allocate new node
    ListNode<NODETYPE> *getNewNode(const NODETYPE &value) {
        return new ListNode<NODETYPE>{value};
    }
};

#endif

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
