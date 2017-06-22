
#include <string>
#include <random>
#include <iostream>
#include <algorithm>
#include "game.h"

using namespace std;


// What the hell is this ?
Game::Game(int rows, int cols): board(rows, cols) {
    board = Board(rows, cols);
    initialize();
}

void Game::initialize() {
    current_state = PLAYING;
    current_player =  (SEED)(rand() % 2 + 1);
}

void Game::play() {
    while(current_state == PLAYING){
        player_move(current_player);
        cout<< board.to_string() << endl;
        update_game(current_player);

        if (current_state == CROSS_WON){
            cout<< get_player_name(CROSS)<<endl;
        } else if (current_state == NOUGHT_WON){
            cout<<get_player_name(NOUGHT) << endl;
        } else if (current_state == DRAW){
            cout<< "It is a Draw"<<endl;
        }
        current_player = (current_player== CROSS) ? NOUGHT : CROSS;
    }
}

void Game::player_move(SEED the_seed) {
    bool valid_input = false;
    string player_name = get_player_name(the_seed);
    while(!valid_input){
        string user_choice;
        cout << ", which square? (e.g. 2B, 2b, B2 or b2)";
        cin >> user_choice;
        if (is_valid(user_choice) && is_available(user_choice)){
            vector<int> row_col = get_row_col(user_choice);
            int row = row_col[0];
            int col = row_col[1];
            board.cells[row][col].content = the_seed;
            board.current_row = row;
            board.current_col = col;
            valid_input = true;
        }
        else{
            cout<<user_choice << " is not valid. Please Try again!"<<endl;
        }
    }
}

void Game::update_game(SEED the_seed) {
    if (board.has_won(the_seed)){
        current_state = (the_seed == CROSS) ? CROSS_WON : NOUGHT_WON;
    }
    else if(board.is_draw()){
        current_state = DRAW;
    }
}


bool Game::is_valid(string user_choice) {
    sort(user_choice.begin(), user_choice.end());

    string user_choice_normalized = "" ;
    for (int i=0 ; i < user_choice.length(); i++){
        user_choice_normalized += tolower(user_choice[i]);
    }

    for(int i=1; i<board.ROWS+1; i++){
        for(int j=97; j < 97 + board.COLS; j++){
           string s = to_string(i);
            s += (char)j;
           if (s == user_choice_normalized){
               return true;
           }
        }
    }
    return false;
}

bool Game::is_available(string user_choice) {
    vector<int> row_col = get_row_col(user_choice);
    int row = row_col[0];
    int col = row_col[1];

    return board.cells[row][col].content == EMPTY;
}

vector<int> Game::get_row_col(string user_choice) {

    sort(user_choice.begin(), user_choice.end());

    string user_choice_normalized = "" ;
    for (int i=0 ; i < user_choice.length(); i++){
        user_choice_normalized += tolower(user_choice[i]);
    }
    vector<int> row_col ;
    row_col.push_back(int(user_choice_normalized[0] -'1'));
    row_col.push_back(user_choice_normalized[1]- 'a');

    return row_col;
}


int main(){
    Game game = Game(3,3);
    game.play();
}
