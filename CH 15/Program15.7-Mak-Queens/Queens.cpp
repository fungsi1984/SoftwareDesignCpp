#include <iostream>
#include "Queens.h"

using namespace std;

void Queens::print_solutions()
{
    find_solutions(0);
}

void Queens::find_solutions(const int col)
{
    for (int row = 0; row < SIZE; row++)
    {
        if (is_safe_position(row, col))
        {
            occupied[row][col] = true;

            if (col == SIZE - 1) print();
            else                 find_solutions(col + 1);
        }

        occupied[row][col] = false;
    }
}

bool Queens::is_safe_position(const int row, const int col) const
{
    int c = col - 1;

    while (c >= 0)
    {
        if (occupied[row][c]) return false;
        c--;
    }

    int r = row - 1;
    c = col - 1;

    while ((r >= 0) && (c >= 0))
    {
        if (occupied[r][c]) return false;
        r--;
        c--;
    }

    r = row + 1;
    c = col - 1;

    while ((r < SIZE) && (c >= 0))
    {
        if (occupied[r][c]) return false;
        r++;
        c--;
    }

    return true;
}

void Queens::print()
{
    count++;

    cout << endl << "Solution #" << count << endl << endl;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << (occupied[row][col] ? "Q " : ". ");
        }
        cout << endl;
    }
}
