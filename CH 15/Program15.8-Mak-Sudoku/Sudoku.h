#ifndef SUDOKU_H_
#define SUDOKU_H_

class Sudoku
{
public:
    Sudoku(const char *file_name);

    bool solve() { return solution_found(0, 0); }

    void print() const;

private:
    static const int BLOCK_SIZE = 3;
    static const int GRID_SIZE  = BLOCK_SIZE*BLOCK_SIZE;

    int grid[GRID_SIZE][GRID_SIZE];

    bool solution_found(int row, int col);
    bool is_number_ok(int row, int col, int number) const;
};

#endif /* SUDOKU_H_ */
