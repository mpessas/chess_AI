#include <assert.h>

#include "defines.h"
#include "board.h"
#include "rank_function.h"
#include "state.h"

int main(int argc, char** argv)
{
    set_computer_player(whitePlayer);
    
    unsigned short chessPositions[65];
    unsigned short chessPlayerPawns[65];

    unsigned short i;
    for (i = MIN_POS; i <= MAX_POS; ++i) {
        chessPositions[i] = empty;
        chessPlayerPawns[i] = noPlayer;
    }
    chessPlayerPawns[valA1] = whitePlayer;
    chessPositions[valA1] = Queen;

    unsigned r = rank(chessPositions, chessPlayerPawns);
    assert(r == 9);

    chessPlayerPawns[valD4] = whitePlayer;
    chessPositions[valD4] = Rook;
    r = rank(chessPositions, chessPlayerPawns);
    assert(r == 9 + 7);

    return 0;
}

