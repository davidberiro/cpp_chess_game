//
// Created by davidberiro on 1/17/17.
//
#include "Piece.h"

#ifndef EX2_PAWN_H
#define EX2_PAWN_H

class Pawn : public Piece
{
public:
    Pawn(const char file, const int rank, std::string color);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) override;

//    virtual std::string getPieceCode();
//
//    virtual std::string getPieceType();

    virtual ~Pawn() override ;

//private:
//    std::string pieceCode = "\u265F";
//    std::string pieceType = "Pawn";
};

#endif //EX2_PAWN_H