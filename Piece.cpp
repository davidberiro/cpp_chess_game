//
// Created by davidberiro on 1/17/17.
//

#include "Piece.h"

Piece::Piece(const char x, const int y, std::string color)
{
    this->location = new Coordinate(x, y);
    this->color = color;
}

std::string Piece::getType()
{
    return this->pieceType;
}

Coordinate* Piece::getLocation()
{
    return this->location;
}

void Piece::setLocation(Coordinate* newLocation)
{
    this->location = newLocation;
}

bool Piece::isInBoard(char x, int y)
{
    return x <= 'H' && y <= 8 && y>=1 && x>='A';
}

std::string Piece::getColor()
{
    return this->color;
}
