#ifndef SHIPMENT_H_
#define SHIPMENT_H_

#include <string>

using namespace std;

class Shipment
{
public:
    virtual ~Shipment() {}

    virtual string get_type() const { return "REGULAR"; }
    virtual double get_cost() const { return cost; }
    virtual int    get_days() const { return days; }

    /**
     * @precondition c > 0
     */
    virtual void set_cost(const double c)
    {
        if (!(c > 0)) throw c;
        cost = c;
    }

    /**
     * @postcondition (days > 0) && (days < 14)
     */
    virtual int calculate_days()
    {
        days = 5;

        if (!((days > 0) && (days < 14))) throw days;
        return days;
    }

protected:
    double cost;
    int days;
};

class Expedited : public Shipment
{
public:
    string get_type() const override { return "EXPEDITED"; }

    /**
     * @precondition (c > 5)  INVALID!
     */
    void set_cost(const double c) override
    {
        if (!(c > 5)) throw c;
        cost = c;
    }

    /**
     * @postcondition (days == 1) || (days == 2)
     */
    int calculate_days() override
    {
        days = 2;

        if (!((days == 1) || (days == 2))) throw days;
        return days;
    }
};

class International : public Shipment
{
public:
    string get_type() const override { return "INTERNATIONAL"; }

    /**
     * @precondition c > 0
     */
    void set_cost(const double c) override
    {
        if (!(c > 0)) throw c;
        cost = c;
    }

    /**
     * @postcondition days > 12  INVALID!
     */
    int calculate_days() override
    {
        days = 20;
        return days;
    }
};

#endif /* SHIPMENT_H_ */
