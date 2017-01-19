//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_ROOK_H
#define EX2_ROOK_H

class Rook : public Piece
{
public:
    Rook(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) override;

    bool isMoved();

    void movedRook();

    virtual ~Rook() override ;

private:
    bool hasMoved;
};

#endif //EX2_ROOK_H