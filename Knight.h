//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_KNIGHT_H
#define EX2_KNIGHT_H

class Knight : public Piece
{
public:
    Knight(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard();

    virtual std::string getPieceCode();

    virtual std::string getPieceType();

    ~Knight() ;

private:
    std::string pieceCode = "\u265E";
    std::string pieceType = "Knight";
};

#endif //EX2_KNIGHT_H