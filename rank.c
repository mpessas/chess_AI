#include <stdlib.h>

#include "defines.h"
#include "board.h"
#include "state.h"


/* Return the points for the specified piece */
static unsigned short points_of_piece(unsigned short);
/* Return the bonus points for holding the specified position */
static unsigned short points_for_pos(unsigned short);
/* Return the points for threatening an opponent's piece */
static unsigned short points_for_threat(unsigned short);


unsigned short rank() 
{
    unsigned short white_rank = 0;
    unsigned short black_rank = 0;

    unsigned short pos;
    for (pos = MIN_POS; pos <= MAX_POS; ++pos) {
        if (player_on_cell(pos) == whitePlayer) {
            /* calculate white points */
            white_rank += points_of_piece(piece_on_cell(pos));
            white_rank += points_for_pos(pos);
            white_rank += points_for_threat(pos);
        } else if (player_on_cell(pos) == blackPlayer) {
            /* Calculate black points */
            black_rank += points_of_piece(piece_on_cell(pos));
            black_rank += points_for_pos(pos);
            black_rank += points_for_threat(pos);
        }
    }

    return (computer_player() == whitePlayer) ?
        white_rank - black_rank : black_rank - white_rank;
}


unsigned short points_of_piece(unsigned short piece)
{
    const unsigned short king_points = 1000; /* ensure king's absence equals failure */
    const unsigned short queen_points = 9;
    const unsigned short rook_points = 5;
    const unsigned short bk_points = 3;
    const unsigned short pawn_points = 1;
    
    switch (piece) {
        case King:
            return king_points;
        case Queen:
            return queen_points;
        case Rook:
            return rook_points;
        case Bishop:
        case Knight:
            return bk_points;
        case WhitePawn:
        case BlackPawn:
            return pawn_points;
        default:
            return 0;
    }
}

unsigned short points_for_pos(unsigned short pos) 
{
    unsigned short special_positions[] = {valD4, valD5, valE4, valE5};
    unsigned short i;
    for (i = 0; i < 4; ++i)
        if (pos == special_positions[i])
            return 2;
    return 0;
}

/*
 * Find the pieces that a piece threatens, when in pos.
 */
static void find_opponents(unsigned short,
                           unsigned short*);

unsigned short points_for_threat(unsigned short pos)
{
    unsigned short* opponents = 0;
    find_opponents(pos, opponents);

    free(opponents);
    return 0;
}

void find_opponents(unsigned short pos,
                    unsigned short* opponents) 
{
}

