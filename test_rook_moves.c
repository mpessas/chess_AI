#include <stdio.h>

#include <assert.h>

#include "state.h"
#include "piece.h"
#include "board.h"

int main() {
    init();
    set_computer_player(whitePlayer);
    MoveElem* m = rook_moves(valA1);
    assert(m == 0);

    set_piece_on_cell(Rook, valC1);
    set_player_on_cell(whitePlayer, valC1);
    m = rook_moves(valC1);

    MoveElem* elem;
    for (elem = m; elem != 0; elem = elem->next) {
        printf("%d\n", elem->m->prev);
    }
    
    
    return 0;
}

    
