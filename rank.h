#ifndef RANK_H
#define RANK_H

#include "move.h"

/*
 * Return the rank of the given state for the specified player.
 *
 * Each player gets points for
 *   (i) the pieces he has left
 *   (ii) holding special cells
 *   (iii) going in a position that threatens an opponent's piece
 */
unsigned short rank(Move* moves);

#endif
