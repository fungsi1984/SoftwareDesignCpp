#ifndef PROVISIONITEM_H_
#define PROVISIONITEM_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ProvisionItem
{
public:
    ProvisionItem(const string id, const double c)
        : id(id), cost(c) {}

    string get_id()   const { return id; }
    double get_cost() const { return cost; }

    void print()
    {
        cout << setw(6) << get_id() << " cost: $"
             << setw(2) << get_cost() << endl;
    }

private:
    string id;
    double cost;
};

#endif /* PROVISIONITEM_H_ */
