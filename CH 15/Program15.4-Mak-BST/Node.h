#ifndef NODE_H_
#define NODE_H_

#include "BST.h"

class Node
{
public:
    Node(const int v) : value(v), left(nullptr), right(nullptr) {}

    friend class BST;

public:
    int value;
    Node *left;
    Node *right;
};

#endif /* NODE_H_ */
