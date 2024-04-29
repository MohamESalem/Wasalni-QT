#ifndef NODE_H
#define NODE_H

#include <string>
struct Node {
    int X, Y;
    std::string name;
    Node* next;
    Node(int X, int Y, std::string name) {
        this->X = X;
        this->Y = Y;
        this->name = name;
    }
};

#endif // NODE_H
