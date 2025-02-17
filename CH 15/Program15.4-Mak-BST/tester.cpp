#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

using namespace std;

int main()
{
    const int TREE_SIZE = 20;

    BST tree;
    srand(time(0));

    cout << "Inserting:";
    for (int i = 0; i < TREE_SIZE; i++)
    {
        int value = rand()%100;
        tree.insert(value);
        cout << setw(3) << value;
    }

    cout << endl << " Printing:";
    tree.print();
}
