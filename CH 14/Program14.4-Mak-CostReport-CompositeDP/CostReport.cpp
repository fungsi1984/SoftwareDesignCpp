#include <iostream>
#include <iomanip>
#include <vector>

#include "ProvisionItem.h"
#include "ProvisionGroup.h"
#include "Equipment.h"
#include "Uniform.h"
#include "Footwear.h"
#include "Sunscreen.h"
#include "CostReport.h"

using namespace std;

CostReport::CostReport()
    : equipment(new Equipment()), uniform(new Uniform()),
      footwear(new Footwear()), sunscreen(new Sunscreen(5))
{
    equipment->add(new Ball(5));
    equipment->add(new Bat(25));
    equipment->add(new Glove(35));

    uniform->add(new Cap(15));
    uniform->add(new Jersey(25));
    uniform->add(new Pants(35));

    footwear->add(new Socks(5));
    footwear->add(new Shoes(50));

    uniform->add(footwear);

    provisions.add(equipment);
    provisions.add(uniform);
    provisions.add(sunscreen);
}

CostReport::~CostReport()
{
    delete equipment;
    delete uniform;
    delete footwear;
    delete sunscreen;
}

void CostReport::generate_report()
{
    provisions.print(0);

    cout << endl;
    cout << "GRAND TOTAL: $" << provisions.get_cost() << endl;
}
