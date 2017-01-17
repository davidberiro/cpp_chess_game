//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_KING_H
#define EX2_KING_H

class King : public Piece
{
public:
    King(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard();

    virtual std::string getPieceCode();

    virtual std::string getPieceType();

    ~King();

private:
    std::string pieceCode = "\u265A";
    std::string pieceType = "King";
};


#endif //EX2_KING_H
