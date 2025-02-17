#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int SIZE = 12;

int largest(vector<int> v);

int main()
{
    vector<int> data;

    srand(time(0));
    for (int i = 0; i < SIZE; i++) data.push_back(rand()%100);

    cout << "Largest of";
    for (int d : data) cout << setw(3) << d;
    cout << endl;
    cout << "is" << setw(3) << largest(data);

    return 0;
}

int largest(vector<int> v)
{
    if (v.size() == 1) return v[0];

    int first_value = v[0];
    v.erase(v.begin());

    int largest_of_rest = largest(v);

    return first_value > largest_of_rest ? first_value
                                         : largest_of_rest;
}
