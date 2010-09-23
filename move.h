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

extern const Move INVALID_MOVE;

/**
 * Apply a move to the current state
 */
void apply_move(Move*, Player);
/**
 * Temporarily apply a move
 */
void temp_apply_move(Move*, Player);

#endif
