#ifndef CELL_H
#define CELL_H

#include <string>
#include "constant.h"


class Cell
{
public:
    SEED content;
    int row;
    int col;

public:
    Cell(int r, int c);
    void clear();
    string to_string();
};

#endif