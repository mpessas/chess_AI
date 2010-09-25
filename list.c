#include "list.h"

#include <stdlib.h>

MoveElem* list_init()
{
    MoveElem* head = 0;
    return head;
}

void list_add(MoveElem** head, Move* move) 
{
    /* Create an MoveElem from the elem */
    MoveElem* elem = (MoveElem*)malloc(sizeof(MoveElem));
    elem->m = move;
    elem->next = 0;
    
    /* If list is empty, just point head to it. */
    if (*head == 0) {
        *head = elem;
        return;
    }

    elem->next = *head;
    *head = elem;
}

Move* list_get(MoveElem* elem) 
{
    return elem->m;
}

void list_destroy(MoveElem* head) 
{
    /* You have to free both the Move* pointer and the element itself. */
    MoveElem* elem = head;
    MoveElem* rm;
    while (elem != 0) {
        rm = elem;
        elem = elem->next;
        free(rm->m);
        free(rm);
    }
}

        
