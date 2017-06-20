#ifndef GAME_H
#define GAME_H

#include <random>
#include "board.h"

using namespace std;


class Game{
private:
    Board board;
    GAME_STATE current_state;
    SEED current_player;

public:
    Game(int rows, int cols);
    void initialize();
    void play();
    void player_move(SEED the_seed);
    void update_game(SEED the_seed);
    bool is_valid(string user_choice);
    bool is_available(string user_choice);
    vector<int> get_row_col(string user_choice);

};

#endif