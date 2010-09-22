#ifndef RANK_FUNCTION_H
#define RANK_FUNCTION_H

/*
 * Return the rank of the given state for the specified player.
 *
 * Each player gets points for
 *   (i) the pieces he has left
 *   (ii) holding special cells
 *   (iii) going in a position that threatens an opponent's piece
 */
unsigned short rank();

#endif
