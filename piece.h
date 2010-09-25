#ifndef PIECE_H
#define PIECE_H

#include "list.h"

/**
 * Available moves to a rook.
 *
 * @param pos the position on the board of the rook. 
 * @returns a list of possible moves.
 */
MoveElem* rook_moves(Position pos);

/**
 * Available moves to a bishop.
 *
 * @param pos the position on the board of the rook. 
 * @returns a list of possible moves.
 */
MoveElem* bishop_moves(Position pos);


#endif
