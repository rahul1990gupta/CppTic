#ifndef CONSTANT_H
#define CONSTANT_H

#include <string>

using namespace std;

enum GAME_STATE {PLAYING, DRAW, CROSS_WON, NOUGHT_WON};
enum SEED {EMPTY, NOUGHT, CROSS};

string get_player_name(SEED seed);

inline char SEED_REPR[3] = {' ', 'O', 'X'};

#endif
