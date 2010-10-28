#include "piece.h"

#include "game.h"
#include "move.h"

static void get_xy_from_pos(Position pos, int* x, int* y) {
    *x = (pos - 1) / 8;
    *y = (pos - 1) % 8;
}

/**
 * List of possible moves for a rook in position pos.
 *
 * @param pos the position the rook is in.
 * @returns list of moves.
 */
MoveElem* rook_moves(Position pos) 
{
    MoveElem* moves = list_init();
    Position x, y, i, j;
    get_xy_from_pos(pos, &x, &y);

    //icrDecrY is the value by which our vertice is being incremented
    //in the Y axis each time
    int incrDecrY[4];
    incrDecrY[0] = 0;
    incrDecrY[1] = 1;
    incrDecrY[2] = 0;
    incrDecrY[3] = -1;

    //icrDecrX is the value by which our vertice is being incremented
    //in the X axis each time
    int incDecrX[4];
    incDecrX[0] = 1;
    incDecrX[1] = 1;
    incDecrX[2] = -1;
    incDecrX[3] = -1;

    //This is the starting point of reference for our vertices
    int startingPoint[4];
    startingPoint[0] = x + 1 + 1;
    startingPoint[1] = y + 1;
    startingPoint[2] = x + 1 - 1;
    startingPoint[3] = y;

    //verticeCounter is the counter variable for our 4 vertices
    int verticeCounter;
    for (verticeCounter = 0; verticeCounter < 4; verticeCounter++) {
        //Set the j to start at the Y axis we want
        j = y + incrDecrY[verticeCounter];
        //Start spreading from our position towards the chessboard boundary
        for (i = startingPoint[verticeCounter];
             i <= 8 && i > 0;
             i += incDecrX[verticeCounter]) {
            //Set the relevancy towards the x-y axis in regards to our current position
            if (verticeCounter == 0)
                targetPosition = j * 8 + i;
            else if (verticeCounter == 1)
                targetPosition = j * 8 + (x + 1);
            else if (verticeCounter == 2)
                targetPosition = j * 8 + i;
            else if (verticeCounter == 3)
                targetPosition = j * 8 + (x + 1);
            //Check if we are within the chessboard boundaries
            if(j * 8 + i > 0 && j * 8 + i < 64 + 1) {
                //If we are, check if there is no other piece in the target position
                if (chessPlayerPawns[targetPosition] == noPlayer) {
                    //Since there is no piece on our target, we enable it
                    //[chessButtons[targetPosition] setAlpha: 0.7];
                    //chessValidPositions[targetPosition] = YES;
                    validTargeting[targetPosition] = valid;
                    /* add move to list */
                    Move m;
                    m.piece = Rook;
                    m.prev = pos;
                    m.next = targetPosition;
                    m.eats = piece_on_cell(targetPosition);
                    m.player = player_on_cell(pos);
                    m.eaten = player_on_cell(targetPosition);
                    list_add(&moves, m);
                } else {
                    validTargeting[targetPosition] = friend;
                    //If there is another piece on our target,
                    //check to see if it is friend or foe
                    if (chessPlayerPawns[targetPosition] != chessPlayerPawns[pos]) {
                        //If it's the enemy, paint it red, and activate it
                        //[chessButtons[targetPosition] setBackgroundColor: redColor];
                        //[chessButtons[targetPosition] setAlpha: 0.7];
                        //chessValidPositions[targetPosition] = YES;
                        validTargeting[targetPosition] = enemy;
                        /* add move to list */
                        Move m;
                        m.piece = Rook;
                        m.prev = pos;
                        m.next = targetPosition;
                        m.eats = piece_on_cell(targetPosition);
                        m.player = player_on_cell(pos);
                        m.eaten = player_on_cell(targetPosition);
                        list_add(&moves, m);
                    }
                    break;
                }
            }
            //Increment/Decrement the Y axis as necessary
            j += incrDecrY[verticeCounter];
        }
    }
    return moves;
}
