#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Quicksort
{
public:
    Quicksort(int * const d, const int s) : data(d), size(s) {};

    void sort() { sort(0, size-1); }

    bool verify_sorted();

private:
    int *data;
    int size;

    void sort(const int left_index, const int right_index);
    int partition(const int left_index, const int right_index);
    void swap_values_at(const int index1, const int index2);

    friend ostream& operator <<(ostream& ostr, const Quicksort& q);
};

#endif /* QUICKSORT_H_ */
