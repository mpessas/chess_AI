#ifndef STATE_H
#define STATE_H

/**
 * Get/Set computer player
 */
unsigned short computer_player();
void set_computer_player(unsigned short);

/**
 * Get/Set pieces on cell of board
 */
unsigned short piece_on_cell(unsigned short);
void set_piece_on_cell(unsigned short, unsigned short);

/**
 * Get/Set player on cell
 */
unsigned short player_on_cell(unsigned short);
void set_player_on_cell(unsigned short, unsigned short);

#endif
