//
// Created by davidberiro on 1/17/17.
//

#include "Pawn.h"

Pawn::Pawn(const char file, const int rank, std::string color) : Piece(file, rank, color)
{

}

std::vector<Coordinate> Pawn::getLegalMovesOnEmptyBoard()
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    if (this->getColor() == "white")
    {
        if (y < 7)
        {
            Coordinate legalMove(x, y + 1);
            result.push_back(legalMove);
        }
        if (y == 2)
        {
            Coordinate legalMove(x, 4);
            result.push_back(legalMove);
        }
    }
    else if (this->getColor() == "black")
    {
        if (y > 2)
        {
            Coordinate legalMove(x, y -1);
            result.push_back(legalMove);
        }
        if (y == 7)
        {
            Coordinate legalMove(x, 5);
            result.push_back(legalMove);
        }
    }
    return result;
}

std::string Pawn::getPieceCode()
{
    return this->pieceCode;
}

std::string Pawn::getPieceType()
{
    return this->pieceType;
}

Pawn::~Pawn()
{

}

