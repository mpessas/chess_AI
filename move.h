#ifndef MOVE_H
#define MOVE_H

#include "game.h"
#include "board.h"

typedef struct Move {
    Position cur;               /* Current position of piece */
    Position next;              /* Next position of piece */
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
