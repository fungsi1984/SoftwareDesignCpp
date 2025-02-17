#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 5;

void reverse(vector<int>& v);

int main()
{
    vector<int> data;

    for (int i = 1; i <= SIZE; i++) data.push_back(10*i);

    cout << "Reverse of";
    for (int d : data) cout << setw(3) << d;
    cout << endl;

    reverse(data);

    cout << "        is";
    for (int d : data) cout << setw(3) << d;
    cout << endl;

    return 0;
}

void reverse(vector<int>& v)
{
    if (v.size() == 1) return;

    int first_value = v[0];
    v.erase(v.begin());

    reverse(v);
    v.push_back(first_value);
}
