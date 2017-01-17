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

    std::string getColor();

    //virtual std::vector<Coordinate> getLegalMovesOnEmptyBoard() = 0;

    ~Piece(){};


private:
    Coordinate* location;
    std::string color;
    std::string pieceType;
};

#endif //EX2_CHESSPIECE_H
