//
// Created by davidberiro on 1/17/17.
//

#include "Rook.h"

Rook::Rook(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Rook";
}

std::vector<Coordinate> Rook::getLegalMovesOnEmptyBoard()
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    for (int i = 1; i <=7; i++)
    {
        if (this->isInBoard(x - i, y))
        {
            result.push_back(Coordinate(char(x - i), y));
        }
        if (this->isInBoard(x + i, y))
        {
            result.push_back(Coordinate(char(x + i), y));
        }
        if (this->isInBoard(x, y - i))
        {
            result.push_back(Coordinate(char(x), y - i));
        }
        if (this->isInBoard(x, y + i))
        {
            result.push_back(Coordinate(char(x), y + i));
        }

    }
    return result;
}

std::string Rook::getPieceCode()
{
    return this->pieceCode;
}

std::string Rook::getPieceType()
{
    return this->pieceType;
}

Rook::~Rook()
{

}