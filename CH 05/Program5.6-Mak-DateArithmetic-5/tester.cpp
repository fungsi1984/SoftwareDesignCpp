#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

int main()
{
    Date d(2030, 1, 31);  // January 31, 2030
    cout << "starting date: "; d.print(); cout << endl;
    cout << "Julian day number = " << d.get_julian() << endl << endl;

    d.set_month(2);
    cout << "modified date: "; d.print(); cout << endl;
    int j = d.get_julian();
    d.set_julian(j);
    cout << "surprise date: "; d.print(); cout << endl;

    return 0;
}
