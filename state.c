#include "state.h"
#include "board.h"

/* Computer player */
static unsigned short player = 0;
/* Pieces on board */
static unsigned short chessPositions[MAX_POS + 1];
/* Players on board */
static unsigned short chessPlayerPawns[MAX_POS + 1];

unsigned short computer_player() 
{
    return player;
}

void set_computer_player(unsigned short p)
{
    player = p;
}

unsigned short piece_on_cell(unsigned short pos) 
{
    return chessPositions[pos];
}

void set_piece_on_cell(unsigned short piece, unsigned short pos)
{
    chessPositions[pos] = piece;
}

unsigned short player_on_cell(unsigned short pos)
{
    return chessPlayerPawns[pos];
}

void set_player_on_cell(unsigned short player, unsigned short pos)
{
    chessPlayerPawns[pos] = player;
}

