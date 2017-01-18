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

//    virtual std::string getPieceCode();
//
//    virtual std::string getPieceType();

    virtual ~Rook() override ;

//private:
//    std::string pieceCode = "\u265C";
//    std::string pieceType = "Rook";
};

#endif //EX2_ROOK_H