#include <iostream>
#include <iomanip>
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
    double equipment_cost = 0;
    for (ProvisionItem *pi : equipment->get_provisions())
    {
        equipment_cost += pi->get_cost();
    }

    double uniform_cost = 0;
    for (ProvisionItem *pi : uniform->get_provisions())
    {
        uniform_cost += pi->get_cost();
    }

    double footwear_cost = 0;
    for (ProvisionItem *pi : footwear->get_provisions())
    {
        footwear_cost += pi->get_cost();
    }

    uniform_cost += footwear_cost;

    cout << "PROVISIONS" << endl;

    cout << "    " << equipment->get_id() << endl;
    for (ProvisionItem *pi : equipment->get_provisions())
    {
        cout << "        ";
        pi->print();
    }
    cout << "    " << equipment->get_id() << " total: $"
         << setw(2) << equipment_cost << endl;

    cout << "    " << uniform->get_id() << endl;
    for (ProvisionItem *pi : uniform->get_provisions())
    {
        cout << "        ";
        pi->print();
    }

    cout << "        " << footwear->get_id() << endl;
    for (ProvisionItem *pi : footwear->get_provisions())
    {
        cout << "            ";
        pi->print();
    }
    cout << "        " << footwear->get_id() << " total: $"
         << setw(2) << footwear_cost << endl;

    cout << "    " << uniform->get_id() << " total: $"
         << setw(2) << uniform_cost << endl;

    cout << "    ";
    sunscreen->print();

    double provisions_total = equipment_cost
                            + uniform_cost
                            + sunscreen->get_cost();
    cout << "PROVISIONS total: $" << provisions_total << endl;

    cout << endl;
    cout << "GRAND TOTAL: $" << provisions_total << endl;
}
