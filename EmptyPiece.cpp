//
// Created by davidberiro on 1/18/17.
//

#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(const char file, const int rank) : Piece(file, rank, "none")
{

    this->pieceType = "none";
    this->pieceCode = " ";
}

std::vector<Coordinate> EmptyPiece::getLegalMovesOnEmptyBoard(Piece *board[])
{
    std::vector<Coordinate> a;
    return a;
}

