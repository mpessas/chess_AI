#include <limits.h>

#include "defines.h"
#include "rank.h"
#include "state.h"

static const unsigned short DEPTH = 2;

/**
 * Alpha - beta algorithm:
 * @param p the player that makes this move
 * @param moves array of moves of length DEPTH
 * @param depth depth of this level
 * @param alpha min calue
 * @param beta max value
 */
Rank alphabeta(Player p, Move* moves, unsigned short depth, short alpha, short beta);

/**
 * Calculate next move of computer.
 */
void make_move()
{
    Move moves[DEPTH];          /* Recoed moves to undo/redo */
    alphabeta(computer_player(), moves, DEPTH, SHRT_MIN, SHRT_MAX);
}


Rank alphabeta(Player p, Move* moves, unsigned short depth, short alpha, short beta) 
{
    if (depth == 0) {
        return rank(moves);
    }
    Position pos;
    for (pos = 0; pos < MAX_POS; ++pos) {
        if (player_on_cell(pos) == p) {
            Player new_p = (p == blackPlayer) ? whitePlayer : blackPlayer;
            alpha = alphabeta(new_p, moves, depth - 1, alpha, beta);
        }
    }
    

    return -1;
}

void apply_move(Move* m) 
{
    set_piece_on_cell(m->piece, m->next);
    set_piece_on_cell(empty, m->prev);
    set_player_on_cell(m->player, m->next);
    set_player_on_cell(noPlayer, m->prev);
}

void undo_move(Move* m) 
{
    set_piece_on_cell(m->piece, m->prev);
    set_piece_on_cell(m->eats, m->next);
    set_player_on_cell(m->player, m->prev);
    set_player_on_cell(m->eaten, m->next);
}
