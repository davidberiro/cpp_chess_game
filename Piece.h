//
// Created by davidberiro on 1/17/17.
//
#include "Coordinate.h"
#include <vector>
#include <iostream>

#ifndef EX2_CHESSPIECE_H
#define EX2_CHESSPIECE_H

class Piece
{
public:
    Piece(const char x, const int y, std::string color);

    std::string getType();

    Coordinate* getLocation();

    void setLocation(Coordinate* newLocation);

    bool isInBoard(char x, int y);

    std::string getColor() const;

    std::string getPieceColorCode();

    std::string getPieceCode();

    int boardIndex(char x, int y);

    int boardIndex(int x, int y);

    virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard(Piece *board[]) = 0;

    virtual ~Piece();


protected:
    Coordinate* location;
    std::string color;
    std::string pieceType;
    std::string pieceCode;
};

#endif //EX2_CHESSPIECE_H
