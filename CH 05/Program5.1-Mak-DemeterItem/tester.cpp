#include <iostream>
#include "Item.h"

using namespace std;

int main()
{
    Item item("whole chicken", 4.5, 10.31);

    cout << "  name: "  << item.get_name() << endl;
    cout << "weight: "  << item.get_weight() << " lbs" << endl;
    cout << " price: $" << item.get_price() << endl;

    item.set_price(-9.99);
    cout << endl << "new price: $" << item.get_price() << endl;

    return 0;
}
