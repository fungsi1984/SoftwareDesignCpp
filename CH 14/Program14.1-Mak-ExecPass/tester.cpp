#include <iostream>
#include "ExecutivePass.h"

ExecutivePass pass;

using namespace std;

int main()
{
    pass.obtain("Ron");
    cout << "obtain: "; pass.print();

    pass.obtain("Sal");
    cout << "obtain: "; pass.print();

    ExecutivePass copy1;
    copy1 = pass;
    copy1.obtain("Bob");
    cout << "copy 1: "; copy1.print();

    ExecutivePass copy2(pass);
    copy2.obtain("Flo");
    cout << "copy 2: "; copy2.print();

    return 0;
}
