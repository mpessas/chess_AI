#include <stdlib.h>

#include "rank.h"
#include "defines.h"
#include "board.h"
#include "state.h"


/* Return the points for the specified piece */
static Rank points_of_piece(Piece);
/* Return the bonus points for holding the specified position */
static Rank points_for_pos(Position);
/* Return the points for threatening an opponent's piece */
static Rank points_for_threat(Position);


Rank rank(Move* moves) 
{
    Rank white_rank = 0;
    Rank black_rank = 0;

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


Rank points_of_piece(piece piece)
{
    const Rank king_points = 1000; /* ensure king's absence equals failure */
    const Rank queen_points = 9;
    const Rank rook_points = 5;
    const Rank bk_points = 3;
    const Rank pawn_points = 1;
    
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

Rank points_for_pos(Position pos) 
{
    const Rank special_pos_points = 2;
    const Rank normal_pos_points = 0;
    unsigned short special_positions[] = {valD4, valD5, valE4, valE5};
    unsigned short i;
    for (i = 0; i < 4; ++i)
        if (pos == special_positions[i])
            return special_pos_points;
    return normal_pos_points;
}

/*
 * Find the pieces that a piece threatens, when in pos.
 */
static void find_opponents(unsigned short,
                           unsigned short*);

Rank points_for_threat(Position pos)
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

