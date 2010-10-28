#ifndef MOVE_H
#define MOVE_H

#include "game.h"
#include "board.h"

typedef struct Move {
    Piece piece;    /* Player's piece */
    Position prev;  /* Current position of piece */
    Position next;  /* Next position of piece */
    Piece eats;     /* Piece of opponent */
    Player player;  /* The player that performs the move */
    Player eaten;   /* THe player on the cell the piece is moved to */
} Move;

/**
 * Computer makes move.
 */
void make_move();

/**
 * Apply a move to the current state.
 *
 * @param m the move to perform
 */
void apply_move(Move* m);

/**
 * Temporarily apply a move.
 *
 * @param m undo the particular move.
 *          Must be last move performed.
 */
void undo_move(Move* m);

#endif
