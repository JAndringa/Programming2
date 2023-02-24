// Fig. 19.22: Tree.h
// Tree class-template definition.
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "TreeNode.h"

// Tree class-template definition
template<typename NODETYPE>
class Tree {
public:
    /**
     * Output the tree row by row
     */
    void outputTree() {
        outputRow(rootPtr, 0);
    }

    /**
     * Search for a node with the given key in the tree.
     * @param key The key to search for.
     * @return A pointer to the node with the given key, or nullptr if not found.
     */
    TreeNode<NODETYPE> *search(const NODETYPE &key) {
        return searchHelper(rootPtr, key);
    }

    // insert node in Tree
    void insertNode(const NODETYPE &value) {
        insertNodeHelper(&rootPtr, value);
    }

    // begin preorder traversal of Tree
    void preOrderTraversal() const {
        preOrderHelper(rootPtr);
    }

    // begin inorder traversal of Tree
    void inOrderTraversal() const {
        inOrderHelper(rootPtr);
    }

    // begin postorder traversal of Tree
    void postOrderTraversal() const {
        postOrderHelper(rootPtr);
    }

private:
    TreeNode<NODETYPE> *rootPtr{nullptr};

    /**
     * Output the tree row by row, starting from the given node and depth.
     * @param node The node to start outputting from.
     * @param depth The current depth of the node in the tree.
     */
    void outputRow(TreeNode<NODETYPE> *node, int depth){
        if(node != nullptr){
            outputRow(node->rightPtr, depth+1);
            for (int i = 0; i < depth * 8; i++){
                std::cout << " ";
            }
            std::cout << node->data << std::endl;
            usleep(100000);
            outputRow(node->leftPtr, depth+1);

        }
        else{
            for (int i = 0; i < depth * 8; i++){
                std::cout << " ";
            }
            std::cout << "x" << std::endl;
            usleep(50000);
        }
    }

    /**
     * Helper function to recursively search for a node with the given key.
     * @param node The node to start searching from.
     * @param key The key to search for.
     * @return A pointer to the node with the given key, or nullptr if not found.
     */
    TreeNode<NODETYPE> *searchHelper(TreeNode<NODETYPE> *node, const NODETYPE &key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->data == key) {
            return node;
        }
        if (key < node->data) {
            return searchHelper(node->leftPtr, key);
        }
        if (key > node->data) {
            return searchHelper(node->rightPtr, key);
        }
        std::cout << "ERROR: something went wrong" << std::endl;
        return nullptr;
    }

    // utility function called by insertNode; receives a pointer
    // to a pointer so that the function can modify pointer's value
    void insertNodeHelper(
            TreeNode<NODETYPE> **ptr, const NODETYPE &value) {
        // subtree is empty; create new TreeNode containing value
        if (*ptr == nullptr) {
            *ptr = new TreeNode<NODETYPE>(value);
        }
        else { // subtree is not empty
            // data to insert is less than data in current node
            if (value < (*ptr)->data) {
                insertNodeHelper(&((*ptr)->leftPtr), value);
            }
            else {
                // data to insert is greater than data in current node
                if (value > (*ptr)->data) {
                    insertNodeHelper(&((*ptr)->rightPtr), value);
                }
                else { // duplicate data value ignored
                    std::cout << value << " dup" << std::endl;
                }
            }
        }
    }

    // utility function to perform preorder traversal of Tree
    void preOrderHelper(TreeNode<NODETYPE> *ptr) const {
        if (ptr != nullptr) {
            std::cout << ptr->data << ' '; // process node
            preOrderHelper(ptr->leftPtr); // traverse left subtree
            std::cout << std::endl;
            preOrderHelper(ptr->rightPtr); // traverse right subtree
        }
    }

    // utility function to perform inorder traversal of Tree
    void inOrderHelper(TreeNode<NODETYPE> *ptr) const {
        if (ptr != nullptr) {
            inOrderHelper(ptr->leftPtr); // traverse left subtree
            std::cout << ptr->data << ' '; // process node
            inOrderHelper(ptr->rightPtr); // traverse right subtree
        }
    }

    // utility function to perform postorder traversal of Tree
    void postOrderHelper(TreeNode<NODETYPE> *ptr) const {
        if (ptr != nullptr) {
            postOrderHelper(ptr->leftPtr); // traverse left subtree
            postOrderHelper(ptr->rightPtr); // traverse right subtree
            std::cout << ptr->data << ' '; // process node
        }
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
