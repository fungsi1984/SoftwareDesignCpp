#ifndef UNIFORM_H_
#define UNIFORM_H_

#include "ProvisionItem.h"

using namespace std;

class Cap : public ProvisionItem
{
public:
    Cap(const double cost) : ProvisionItem("cap", cost) {}
};

class Jersey : public ProvisionItem
{
public:
    Jersey(const double cost) : ProvisionItem("jersey", cost) {}
};

class Pants : public ProvisionItem
{
public:
    Pants(const double cost) : ProvisionItem("pants", cost) {}
};

#endif /* UNIFORM_H_ */
