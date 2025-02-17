#include <iostream>
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
    date1.add_days(count).print(); cout << endl;

    return 0;
}
