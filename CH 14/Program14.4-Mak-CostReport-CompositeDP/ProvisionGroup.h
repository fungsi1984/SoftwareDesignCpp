#ifndef PROVISIONGROUP_H_
#define PROVISIONGROUP_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "ProvisionItem.h"

using namespace std;

class ProvisionGroup : public ProvisionItem
{
public:
    ProvisionGroup() : ProvisionItem("PROVISIONS") {}

    ~ProvisionGroup()
    {
        for (ProvisionItem *item : provisions) { delete item; };
    }

    double get_cost() const override
    {
        double cost = 0;
        for (ProvisionItem *item : provisions)
        {
            cost += item->get_cost();
        }

        return cost;
    }

    void print(const int indentation) override
    {
        for (int i = 0; i < indentation; i++) cout << "    ";
        cout << get_id() << endl;

        for (ProvisionItem *item : provisions)
        {
            item->print(indentation + 1);
        }

        for (int i = 0; i < indentation; i++) cout << "    ";
        cout << get_id() << " total: $" << get_cost() << endl;
    }

    vector<ProvisionItem *> get_provisions() const override
    {
        return provisions;
    }

    void add(ProvisionItem *item) override
    {
        provisions.push_back(item);
    }

    void remove(ProvisionItem *item) override
    {
        auto pos = find(provisions.begin(), provisions.end(), item);
        if (pos != provisions.end()) provisions.erase(pos);
    }

protected:
    ProvisionGroup(const string id) : ProvisionItem(id) {}

private:
    vector<ProvisionItem *> provisions;
};

class Equipment : public ProvisionGroup
{
public:
    Equipment() : ProvisionGroup("EQUIPMENT") {}
};

class Uniform : public ProvisionGroup
{
public:
    Uniform() : ProvisionGroup("UNIFORM") {}
};

class Footwear : public ProvisionGroup
{
public:
    Footwear() : ProvisionGroup("FOOTWEAR") {}
};

#endif /* PROVISIONGROUP_H_ */
