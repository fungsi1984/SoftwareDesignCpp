#ifndef BST_H_
#define BST_H_

#include "Node.h"

class BST
{
public:
    BST() : root(nullptr) {}

    virtual ~BST() { remove(root); }

    void insert(const int value) { insert(value, root); }
    void print() const           { print(root); }

private:
    Node *root;

    void insert(const int value, Node*& link);
    void print (const Node * const link) const;
    void remove(const Node * const link) const;
};

#endif /* BST_H_ */
