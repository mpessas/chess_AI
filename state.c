#include "state.h"
#include "board.h"

/* Computer player */
static unsigned short player = 0;
/* Pieces on board */
static unsigned short* chessPositions;
/* Players on board */
static unsigned short* chessPlayerPawns;

/* Put the pieces on board */
static void init_pieces();
/* Put the players on board */
static void init_players();

void init()
{
    // Allocate memory
    chessPositions = (unsigned short*) malloc(sizeof(unsigned short) * MAX_POS + 1);
    chess Players = (unsigned short*) malloc(sizeof(unsigned short) * MAX_POS + 1);
    // Initialize the tables
    unsigned short i;
    for (i = valA1; i <= valH8; ++i) {
        chessPositions[i]=empty;
        chessPlayerPawns[i] = noPlayer;
    }
    
    init_pieces();
    init_players();
}

void destroy() 
{
    // Release memory
    free(chessPositions);
    free(chessPlayerPawns);
}

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


/* Put white pieces on board */
static void init_white_pieces();
/* Put black pieces on board */
static void init_black_pieces();

void init_pieces()
{
    init_white_pieces();
    init_black_pieces();
}

void init_white_pieces()
{
    chessPositions[valA1]=Rook;
    chessPositions[valB1]=Knight;
    chessPositions[valC1]=Bishop;
    chessPositions[valD1]=King;
    chessPositions[valE1]=Queen;
    chessPositions[valF1]=Bishop;
    chessPositions[valG1]=Knight;
    chessPositions[valH1]=Rook;
    chessPositions[valA2]=WhitePawnOriginal;
    chessPositions[valB2]=WhitePawnOriginal;
    chessPositions[valC2]=WhitePawnOriginal;
    chessPositions[valD2]=WhitePawnOriginal;
    chessPositions[valE2]=WhitePawnOriginal;
    chessPositions[valF2]=WhitePawnOriginal;
    chessPositions[valG2]=WhitePawnOriginal;
    chessPositions[valH2]=WhitePawnOriginal;
}

void init_black_pieces() 
{
    chessPositions[valA8]=Rook;
    chessPositions[valB8]=Knight;
    chessPositions[valC8]=Bishop;
    chessPositions[valD8]=King;
    chessPositions[valE8]=Queen;
    chessPositions[valF8]=Bishop;
    chessPositions[valG8]=Knight;
    chessPositions[valH8]=Rook;
    chessPositions[valA7]=BlackPawnOriginal;
    chessPositions[valB7]=BlackPawnOriginal;
    chessPositions[valC7]=BlackPawnOriginal;
    chessPositions[valD7]=BlackPawnOriginal;
    chessPositions[valE7]=BlackPawnOriginal;
    chessPositions[valF7]=BlackPawnOriginal;
    chessPositions[valG7]=BlackPawnOriginal;
    chessPositions[valH7]=BlackPawnOriginal;
}


/* Set the pieces that belong to white */
static void init_white_player();
/* Set the pieces that belong to black */
static void init_black_player();

void init_players() 
{
    init_white_player();
    init_black_player();
}

void init_white_player() 
{
    chessPlayerPawns[valA1]=whitePlayer;
    chessPlayerPawns[valB1]=whitePlayer;
    chessPlayerPawns[valC1]=whitePlayer;
    chessPlayerPawns[valD1]=whitePlayer;
    chessPlayerPawns[valE1]=whitePlayer;
    chessPlayerPawns[valF1]=whitePlayer;
    chessPlayerPawns[valG1]=whitePlayer;
    chessPlayerPawns[valH1]=whitePlayer;
    chessPlayerPawns[valA2]=whitePlayer;
    chessPlayerPawns[valB2]=whitePlayer;
    chessPlayerPawns[valC2]=whitePlayer;
    chessPlayerPawns[valD2]=whitePlayer;
    chessPlayerPawns[valE2]=whitePlayer;
    chessPlayerPawns[valF2]=whitePlayer;
    chessPlayerPawns[valG2]=whitePlayer;
    chessPlayerPawns[valH2]=whitePlayer;
}

void init_black_player() 
{
    chessPlayerPawns[valA8]=blackPlayer;
    chessPlayerPawns[valB8]=blackPlayer;
    chessPlayerPawns[valC8]=blackPlayer;
    chessPlayerPawns[valD8]=blackPlayer;
    chessPlayerPawns[valE8]=blackPlayer;
    chessPlayerPawns[valF8]=blackPlayer;
    chessPlayerPawns[valG8]=blackPlayer;
    chessPlayerPawns[valH8]=blackPlayer;
    chessPlayerPawns[valA7]=blackPlayer;
    chessPlayerPawns[valB7]=blackPlayer;
    chessPlayerPawns[valC7]=blackPlayer;
    chessPlayerPawns[valD7]=blackPlayer;
    chessPlayerPawns[valE7]=blackPlayer;
    chessPlayerPawns[valF7]=blackPlayer;
    chessPlayerPawns[valG7]=blackPlayer;
    chessPlayerPawns[valH7]=blackPlayer;
}
