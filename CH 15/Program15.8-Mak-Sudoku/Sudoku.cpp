#include <iostream>
#include <fstream>
#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku(const char *file_name)
{
    try
    {
        ifstream grid_file(file_name);
        grid_file.exceptions(ifstream::failbit | ifstream::badbit);

        for (int row = 0; row < GRID_SIZE; row++)
        {
            for (int col = 0; col < GRID_SIZE; col++)
            {
                grid_file >> grid[row][col];
            }
        }
    }
    catch (ifstream::failure& ex)
    {
        cerr << "Input file error: " << file_name << endl;
        exit(-1);
    }
}

bool Sudoku::solution_found(int row, int col)
{
    if ((row == GRID_SIZE-1) && (col == GRID_SIZE)) return true;

    if (col == GRID_SIZE)
    {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0) return solution_found(row, col + 1);

    for (int number = 1; number <= GRID_SIZE; number++)
    {
        if (is_number_ok(row, col, number))
        {
            grid[row][col] = number;
            if (solution_found(row, col + 1)) return true;
        }
    }

    grid[row][col] = 0;
    return false;
}

bool Sudoku::is_number_ok(int row, int col, int number) const
{
    for (int c = 0; c < GRID_SIZE; c++)
    {
        if (grid[row][c] == number) return false;
    }

    for (int r = 0; r < GRID_SIZE; r++)
    {
        if (grid[r][col] == number) return false;
    }

    int block_row_start = row - row%BLOCK_SIZE;
    int block_col_start = col - col%BLOCK_SIZE;
    int block_row_end = block_row_start + BLOCK_SIZE;
    int block_col_end = block_col_start + BLOCK_SIZE;

    for (int r = block_row_start; r < block_row_end; r++)
    {
        for (int c = block_col_start; c < block_col_end; c++)
        {
            if (grid[r][c] == number) return false;
        }
    }

    return true;
}

void Sudoku::print() const
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        if ((row > 0) && (row%BLOCK_SIZE == 0))
        {
            cout << "------+-------+-------" << endl;
        }

        for (int col = 0; col < GRID_SIZE; col++)
        {
            if ((col > 0) && (col%BLOCK_SIZE == 0)) cout << "| ";

            int g = grid[row][col];
            if (g > 0) cout << g << " ";
            else       cout << ". ";
        }

        cout << endl;
    }
}
