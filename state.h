#ifndef STATE_H
#define STATE_H

#include "game.h"
#include "board.h"

/**
 * Initialize/clear game
 */
void init();
void destroy();

/**
 * Get/Set computer player
 */
Player computer_player();
void set_computer_player(Player);

/**
 * Get/Set pieces on cell of board
 */
Piece piece_on_cell(Piece);
void set_piece_on_cell(Piece, Position);

/**
 * Get/Set player on cell
 */
Player player_on_cell(Position);
void set_player_on_cell(Player, Position);

#endif
