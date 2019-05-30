#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
    public:
        string data;
        Node* left;
        Node* right;
        Node* parent;
        int count;
        int hieght;
        // char key;

        Node(string data): data(data), left(0), right(0),parent(0) ,count (0), hieght(0){}
};

#endif