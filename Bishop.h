//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_BISHOP_H
#define EX2_BISHOP_H

class Bishop : public Piece
{
public:
    Bishop(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard();

    virtual std::string getPieceCode();

    virtual std::string getPieceType();

    ~Bishop();

private:
    std::string pieceCode = "\u265D";
    std::string pieceType = "Bishop";
};



#endif //EX2_BISHOP_H