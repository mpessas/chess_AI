#include <limits.h>

#include "defines.h"
#include "rank.h"
#include "state.h"

static const unsigned short DEPTH = 2;

const Move INVALID_MOVE = {-1, -1};

/**
 * Alpha - beta algorithm:
 * params:
 *   moves array of moves of length DEPTH
 *   depth depth of this level
 *   alpha min calue
 *   beta max value
 */
int alphabeta(Move* moves, unsigned short depth, short alpha, short beta);

/*
 * Calculate next move of computer.
 */
void next_move(unsigned short* positions,
               unsigned short* playerPawns,
               unsigned short pos,
               unsigned short p)
{
    Move moves[DEPTH];
    unsigned i;
    for (i = 0; i < DEPTH; ++i)
        moves[i] = INVALID_MOVE;

    alphabeta(moves, DEPTH, SHRT_MIN, SHRT_MAX);
}


int alphabeta(Move* moves, unsigned short depth, short alpha, short beta) 
{
    if (depth == 0) {
        return rank(moves);
    }

    return -1;
}

