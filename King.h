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

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) override;

    bool isMoved();

    void movedKing();

    virtual ~King() override;

private:
    bool hasMoved;
};


#endif //EX2_KING_H
