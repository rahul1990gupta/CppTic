#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "cell.h"

using namespace std;

class Board{
public:
    int ROWS;
    int COLS;
    vector<vector<Cell>> cells;
    int current_row;
    int current_col;

public:
    Board(int r, int c);
    void clear();
    bool is_draw();
    bool has_won(SEED the_seed);
    string to_string();
};

#endif