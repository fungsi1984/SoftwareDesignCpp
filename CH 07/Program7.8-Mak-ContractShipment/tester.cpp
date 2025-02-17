#include <iostream>
#include "Shipment.h"

using namespace std;

void ship_it(Shipment * const s);

int main()
{
    Shipment *shipment      = new Shipment();
    Shipment *expedited     = new Expedited();
    Shipment *international = new International();

    ship_it(shipment);
    ship_it(expedited);
    ship_it(international);

    delete shipment;
    delete expedited;
    delete international;

    return 0;
}

void ship_it(Shipment * const s)
{
    try
    {
        cout << endl << "Shipping " << s->get_type();

        s->set_cost(2.00);

        s->calculate_days();
        int days = s->get_days();
        if (!((days > 0) && (days < 14))) throw days;
    }
    catch (double cost)
    {
        cout << " *** Invalid cost: " << cost;
    }
    catch (int days)
    {
        cout << " *** Invalid days: " << days;
    }
}
