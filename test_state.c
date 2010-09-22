#include <assert.h>

#include "state.h"
#include "defines.h"

int main() 
{
    init();
    set_computer_player(whitePlayer);
    unsigned short p = computer_player();
    assert(p == whitePlayer);

    set_piece_on_cell(Queen, valA1);
    p = piece_on_cell(valA1);
    assert(p == Queen);

    set_player_on_cell(blackPlayer, valH8);
    p = player_on_cell(valH8);
    assert(p == blackPlayer);

    destroy();

    return 0;
}
