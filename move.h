#ifndef MOVE_H
#define MOVE_H

#include "game.h"
#include "board.h"

typedef struct Move {
    Piece piece                 /* Player's oppontent */
    Position prev;              /* Current position of piece */
    Position next;              /* Next position of piece */
    Piece opponent;             /* Piece of opponent */
    Player player;              /* The player that performs the move */
} Move;

/**
 * The invalid move of the game.
 */
extern const Move INVALID_MOVE;

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
