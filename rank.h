#ifndef RANK_H
#define RANK_H

#include "move.h"

typedef unsogned short Rank;
/*
 * Return the rank of the given state for the specified player.
 *
 * Each player gets points for
 *   (i) the pieces he has left
 *   (ii) holding special cells
 *   (iii) going in a position that threatens an opponent's piece
 */
Rank rank(Move* moves);

#endif
