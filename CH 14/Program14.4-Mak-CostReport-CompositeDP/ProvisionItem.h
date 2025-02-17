#ifndef PROVISIONITEM_H_
#define PROVISIONITEM_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class InvalidOperation {};

class ProvisionItem
{
public:
    virtual ~ProvisionItem() {}

    string get_id() const { return id; }

    virtual double get_cost() const { return cost; }

    virtual void print(const int indentation)
    {
        for (int i = 0; i < indentation; i++) cout << "    ";

        cout << setw(6) << get_id() << " cost: $"
             << setw(2) << get_cost() << endl;
    }

    virtual vector<ProvisionItem *> get_provisions() const
    {
        throw new InvalidOperation();
    }

    virtual void add(ProvisionItem *item)
    {
        throw new InvalidOperation();
    }

    virtual void remove(ProvisionItem *item)
    {
        throw new InvalidOperation();
    }

protected:
    ProvisionItem(const string id) : id(id), cost(0) {}

    ProvisionItem(const string id, const double c)
        : id(id), cost(c) {}

private:
    string id;
    double cost;
};

#endif /* PROVISIONITEM_H_ */
