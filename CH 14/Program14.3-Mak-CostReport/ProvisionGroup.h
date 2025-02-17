#ifndef PROVISIONGROUP_H_
#define PROVISIONGROUP_H_

#include <vector>
#include <algorithm>
#include "ProvisionItem.h"

using namespace std;

class ProvisionGroup
{
public:
    ProvisionGroup(string id) : id(id) {}

    ~ProvisionGroup()
    {
        for (ProvisionItem *item : provisions) { delete item; };
    }

    string get_id() const { return id; }

    vector<ProvisionItem *> get_provisions() const
    {
        return provisions;
    }

    void add(ProvisionItem *item) { provisions.push_back(item); }

    void remove(ProvisionItem *item)
    {
        auto pos = find(provisions.begin(), provisions.end(), item);
        if (pos != provisions.end()) provisions.erase(pos);
    }

private:
    string id;
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
