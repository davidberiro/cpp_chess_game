//
// Created by davidberiro on 1/17/17.
//
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Coordinate.h"

#ifndef EX2_BOARD_H
#define EX2_BOARD_H
#define BOARD_SIZE 64

class Board
{
public:
    /**
     * creates starting board
     * @return
     */
    Board();

    int movePiece(std::string command);

    void printBoard();

private:
    Piece *boardArray[BOARD_SIZE];

    int indexInBoardArray(Coordinate location);

    int indexInBoardArray(char x, int y);
};


#endif //EX2_BOARD_H