#include <assert.h>
#include <stdlib.h>

#include "defines.h"
#include "board.h"
#include "rank.h"
#include "state.h"
#include "move.h"


static const unsigned short DEPTH = 2;

int main(int argc, char** argv)
{
    init();
    set_computer_player(whitePlayer);

    Move* moves = (Move*) malloc(sizeof(Move) * DEPTH);
    unsigned short i;
    for (i = 0; i < DEPTH; ++i)
        moves[i] = INVALID_MOVE;
    
    assert(rank(moves) == 0);
    
    return 0;
}

