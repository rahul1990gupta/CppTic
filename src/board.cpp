#include <string>
#include "board.h"

using namespace std;

Board::Board(int r,int c) {
    ROWS = r;
    COLS = c;
    for(int i=0; i < ROWS; i++){
        vector<Cell> temp;
        for (int j =0; j < COLS; j++){
            temp.push_back(Cell(i, j));
        }
        cells.push_back(temp);
    }
}

void Board::clear() {
    for(int i=0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j].clear();
        }
    }
}

bool Board::is_draw() {
    for(int i=0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cells[i][j].content == EMPTY){
                return false;
            }
        }
    }
    return true;
}

bool Board::has_won(SEED the_seed) {
    bool three_in_row = (cells[current_row][0].content == the_seed )
                       && (cells[current_row][1].content == the_seed )
                       && (cells[current_row][2].content == the_seed);
    
    bool three_in_column = cells[0][current_col].content == the_seed \
                          && cells[1][current_col].content == the_seed \
                          && cells[2][current_col].content == the_seed;

    bool three_in_diagonal = current_row == current_col \
                            && cells[0][0].content == the_seed \
                            && cells[1][1].content == the_seed \
                            && cells[2][2].content == the_seed;

    bool three_in_opposite_diagonal = (current_row + current_col == 2) \
                                 && cells[0][2].content == the_seed \
                                 && cells[1][1].content == the_seed \
                                 && cells[2][0].content == the_seed;

    return three_in_row|| three_in_column|| three_in_diagonal|| three_in_opposite_diagonal;
}

string Board::to_string() {
    string final_str = "\n|";
    for (int j =97; j < 97 + COLS; j++){
        final_str += (char)j;
        final_str+= "|";
    }
    final_str += "\n";
    for(int i =0; i < ROWS; i++){
        string row_str = std::to_string(i+1) + "|";
        for(int j=0; j< COLS; j++){
            row_str += cells[i][j].to_string() + "|";
        }
        final_str += row_str + "\n";
    }
    return final_str;
}
