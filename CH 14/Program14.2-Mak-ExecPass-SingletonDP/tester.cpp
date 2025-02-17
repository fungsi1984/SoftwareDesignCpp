#include <iostream>
#include "ExecutivePass.h"

using namespace std;

int main()
{
    ExecutivePass *pass = ExecutivePass::obtain("Ron");
    cout << "obtain: "; pass->print();

    pass = ExecutivePass::obtain("Sal");
    cout << "obtain: "; pass->print();

    delete pass;
    cout << "delete" << endl;

    pass = ExecutivePass::obtain("Bob");
    cout << "obtain: "; pass->print();

    pass = ExecutivePass::obtain("Flo");
    cout << "obtain: "; pass->print();

    delete pass;
    return 0;
}
