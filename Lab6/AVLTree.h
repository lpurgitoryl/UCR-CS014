#ifndef _AVLTREE_H
#define _AVLTREE_H

#include "Node.h"
#include <iostream>
#include <string>

using namespace  std;


class AVLTree
{
    private:
        Node* root;
       


    public:
        AVLTree(): root(0){}

        void insert(const string &);
        // Insert an item to the binary search tree and perform rotation if necessary.
        int balanceFactor(Node *) ;
        // // Return the balance factor of a given node.
        // void printBalanceFactors() ;
        // // Traverse and print the tree in inorder notation.
        // // Print the string followed by its balance factor in parentheses followed by a, and one space.
        // void visualizeTree(const string &) ;
        // // Generate dotty file and visualize the tree using dotty program.
        // Call this function before and after rotation.
        void printTester();

    private:
         Node* findUnbalancedNode(Node* );// uses get balnce
        // void rotate(Node*);// uses rotate left and right and find parent
        // Node* rotateLeft(Node* );
        // Node* rotateLeft(Node* );
        
        Node* search(Node*, string &);
        void updateHeight(Node*);
        int getBalance(Node* );
        
        void printTester(Node* node);
        // void printBalanceFactors(Node *);
        // void visualizeTree(ofstream &, Node *);
        
};

#endif


        