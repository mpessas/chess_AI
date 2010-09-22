#ifndef MOVE_H
#define MOVE_H

typedef struct Move {
    unsigned short cur;         /* Current position of piece */
    unsigned short next;        /* Next position of piece */
} Move;

extern const Move INVALID_MOVE;

#endif
