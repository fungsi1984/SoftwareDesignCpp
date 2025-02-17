#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

int main()
{
    Date date1(2025, 9, 2);  // September 2, 2025
    Date date2(2027, 4, 3);  // April 3, 2027

    cout << "date1 = "; date1.print(); cout << endl;
    cout << "date2 = "; date2.print(); cout << endl;

    int count = date2.days_from(date1);
    cout << "count = " << count << endl;

    cout << "should be date2: ";
    date1.add_days(count).print(); cout << endl << endl;

    int j1 = date1.get_julian();
    cout << "date1 Julian number = " << j1 << endl << endl;

    Date d;
    int js[] = { 0, 2440000, 3000000 };

    for (int j : js)
    {
        d.set_julian(j);
        cout << setw(8) << d.get_julian();
        cout << ": "; d.print(); cout << endl;
    }

    cout << endl;

    d.set_julian(j1);
    cout << "should be date1: "; d.print(); cout << endl;

    return 0;
}
