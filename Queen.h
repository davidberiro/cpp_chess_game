//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_QUEEN_H
#define EX2_QUEEN_H

class Queen : public Piece
{
public:
    Queen(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) override ;

//    virtual std::string getPieceCode();

//    virtual std::string getPieceType();

    virtual ~Queen() override ;

//private:
//    std::string pieceCode = "\u265B";
//    std::string pieceType = "Queen";
};

#endif //EX2_QUEEN_H