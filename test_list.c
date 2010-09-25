#include <stdlib.h>

#include "list.h"
#include "move.h"

int main() 
{
    Move* a = (Move*)malloc(sizeof(Move));
    a->piece = 3;
    a->prev = 3;
    Move* b = (Move*)malloc(sizeof(Move));
    b->piece = 4;
    b->prev = 4;


    MoveElem* list = list_init();
    list_add(&list, a);
    list_add(&list, b);
    list_destroy(list);

    return 0;
}

    
    
    
