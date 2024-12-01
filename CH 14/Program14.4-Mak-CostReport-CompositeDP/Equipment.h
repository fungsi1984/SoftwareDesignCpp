#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include "ProvisionItem.h"

using namespace std;

class Ball : public ProvisionItem
{
public:
    Ball(const double cost) : ProvisionItem("ball", cost) {}
};

class Bat : public ProvisionItem
{
public:
    Bat(const double cost) : ProvisionItem("bat", cost) {}
};

class Glove : public ProvisionItem
{
public:
    Glove(const double cost) : ProvisionItem("glove", cost) {}
};

#endif /* EQUIPMENT_H_ */
