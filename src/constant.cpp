/*
This module stores all the constants used in the Game libraries
*/

# include<string>
# include "constant.h"

using namespace std;

GAME_STATE current_state = PLAYING;

string get_player_name(SEED seed){
    string s = "";
    s+= SEED_REPR[seed];
    return s;
}
