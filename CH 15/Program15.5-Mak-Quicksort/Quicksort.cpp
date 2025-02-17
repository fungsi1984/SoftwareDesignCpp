#include <iostream>
#include <iomanip>
#include "Quicksort.h"

using namespace std;

void Quicksort::sort(const int left_index, const int right_index)
{
    int partition_size = right_index - left_index + 1;

    if (partition_size < 2) return;

    if (partition_size == 2)
    {
        if (data[left_index] > data[right_index])
        {
            swap_values_at(left_index, right_index);
        }
    }
    else
    {
        int pivot_index = partition(left_index, right_index);

        sort(left_index, pivot_index - 1);
        sort(pivot_index + 1, right_index);
    }
}

int Quicksort::partition(const int left_index, const int right_index)
{
    int middle_index = (left_index + right_index)/2;
    int pivot_value  = data[middle_index];

    swap_values_at(middle_index, right_index);

    int i = left_index - 1;
    int j = right_index;

    while (i < j)
    {
        do
        {
            i++;
        } while ((i < right_index) && (data[i] < pivot_value));

        do
        {
            j--;
        } while ((j >= left_index) && (data[j] > pivot_value));

        if (i < j) swap_values_at(i, j);
    }

    swap_values_at(i, right_index);
    return i;
}

void Quicksort::swap_values_at(const int index1, const int index2)
{
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

bool Quicksort::verify_sorted()
{
    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] > data[i+1]) return false;
    }

    return true;
}

ostream& operator <<(ostream& ostr, const Quicksort& q)
{
    for (int i = 0; i < q.size; i++) ostr << setw(3) << q.data[i];

    return ostr;
}
