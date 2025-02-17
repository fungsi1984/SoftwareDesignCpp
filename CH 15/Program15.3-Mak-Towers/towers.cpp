#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int N = 3;

void solve(const int  n,
           const char source,
           const char temporary,
           const char destination);

int main()
{
    solve(N, 'L', 'M', 'R');

    return 0;
}

void solve(const int  n,
           const char source,
           const char temporary,
           const char destination)
{
    if (n == 1)
    {
        cout << "Move " << source << " ==> " << destination << endl;
    }
    else
    {
        solve(n - 1, source,    destination, temporary);
        solve(1,     source,    temporary,   destination);
        solve(n - 1, temporary, source,      destination);
    }
}
