#include <string>
#include "cell.h"

using namespace std;

Cell::Cell(int r, int c) {
    content = EMPTY;
    row = r;
    col = c;
}

void Cell::clear(){
    content = EMPTY;
};

string Cell::to_string() {
    char c = SEED_REPR[content];
    string s = "";
    s+=c;
    return s;
}
