#ifndef LIST_H
#define LIST_H

#include "move.h"

/**
 * A list for storing moves.
 *
 * User has the responsibility for free()-ing the memory of
 * the elements stored in it by callin destroy().
 */

/**
 * The elements of the lsit.
 *
 * Each element holds the actual move and a pointer to
 * the next element of the list.
 */
typedef struct MoveElem {
    Move* m;
    struct MoveElem* next;
} MoveElem;


/**
 * Initialize the list.
 *
 * @returns a pointer to the head of the list.
 */
MoveElem* list_init();

/**
 * Add an element to the head of the list.
 *
 * @param head the head of the list.
 * @param move the element to add to the list.
 */
void list_add(MoveElem** head, Move* move);

/**
 * Get a pointer to the actual move given an element of the lsit.
 *
 * @param elem an element of the list.
 * @returns the move of the element.
 */
Move* list_get(MoveElem* elem);

/**
 * Free all elements of the list pointed at by parameter.
 *
 * Assume that each move is a pointer initializez by malloc().
 *
 * @param head the head of the list.
 */
void list_destroy(MoveElem* head);


#endif
