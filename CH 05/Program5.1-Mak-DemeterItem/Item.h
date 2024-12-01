#ifndef ITEM_H_
#define ITEM_H_

#include <string>

using namespace std;

class Item
{
public:
    Item(const string n, const double w, const double p)
        : name(n), weight(w), price(p) {}

    string get_name()   const { return name; }
    double get_weight() const { return weight; }
    double get_price()  const { return price; }

    void set_price(const double p)
    {
        assert(p > 0.00);
        price = p;
    }

private:
    string name;
    double weight;
    double price;
};

#endif /* ITEM_H_ */
