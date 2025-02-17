#include <iostream>
#include <iomanip>
#include "BST.h"

using namespace std;

void BST::insert(const int value, Node*& link)
{
    if      (link == nullptr)      link = new Node(value);
    else if (value <= link->value) insert(value, link->left);
    else                           insert(value, link->right);
}

void BST::print(const Node * const link) const
{
    if (link != nullptr)
    {
        print(link->left);
        cout << setw(3) << link->value;
        print(link->right);
    }
}

void BST::remove(const Node * const link) const
{
    if (link != nullptr)
    {
        remove(link->left);
        remove(link->right);

        delete link;
    }
}
