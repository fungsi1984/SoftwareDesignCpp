#ifndef APPOINTMENTS_H_
#define APPOINTMENTS_H_

#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

class Appointments
{
public:
    vector<Date> get_dates() const { return dates; }

    Date at(const int index) const { return dates[index]; }
    void append(const Date date)   { dates.push_back(date); }

    void insert(const int index, const Date date)
    {
        dates.insert(dates.begin() + index, date);
    }

    void remove(const int index)
    {
        dates.erase(dates.begin() + index);
    }

private:
    vector<Date> dates;
};

#endif /* APPOINTMENTS_H_ */
