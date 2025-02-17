#ifndef FOOTWEAR_H_
#define FOOTWEAR_H_

#include "ProvisionItem.h"

using namespace std;

class Socks : public ProvisionItem
{
public:
    Socks(const double cost) : ProvisionItem("socks", cost) {}
};

class Shoes : public ProvisionItem
{
public:
    Shoes(const double cost) : ProvisionItem("shoes", cost) {}
};

#endif /* FOOTWEAR_H_ */
