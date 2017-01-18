//
// Created by davidberiro on 1/17/17.
//

#include "Piece.h"

Piece::Piece(const char x, const int y, std::string color)
{
    this->location = new Coordinate(x, y);
    this->color = color;
    this->pieceType = "all";
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

std::string Piece::getColor() const
{
    return this->color;
}

std::string Piece::getPieceColorCode()
{
    if (this->color == "white")
    {
        return "[37;";
    }
    else if (this->color == "black")
    {
        return "[30;";
    }
    else
    {
        return "[0;";
    }
}

std::string Piece::getPieceCode()
{
    return this->pieceCode;
}

int Piece::boardIndex(char x, int y)
{
    return (8 * (y - 1)) + (int(x) % int('A'));
}

int Piece::boardIndex(int x, int y)
{
    return (8 * (y - 1)) + (int(x) % int('A'));
}

Piece::~Piece()
{

}
