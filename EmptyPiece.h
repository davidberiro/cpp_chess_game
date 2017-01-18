//
// Created by davidberiro on 1/18/17.
//
#include "Piece.h"

#ifndef EX2_EMPTYPIECE_H
#define EX2_EMPTYPIECE_H

class EmptyPiece : public Piece
{
public:
    EmptyPiece(const char file, const int rank);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) override ;

};






#endif //EX2_EMPTYPIECE_H
