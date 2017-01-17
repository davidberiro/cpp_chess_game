//
// Created by davidberiro on 1/17/17.
//

#include "Queen.h"

Queen::Queen(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Queen";
}

std::vector<Coordinate> Queen::getLegalMovesOnEmptyBoard()
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    for (int i = 1; i <=7; i++)
    {
        if (this->isInBoard(x + i, y + i))
        {
            result.push_back(Coordinate(char(x + i), y + i));
        }
        if (this->isInBoard(x + i, y - i))
        {
            result.push_back(Coordinate(char(x + i), y - i));
        }
        if (this->isInBoard(x - i, y + i))
        {
            result.push_back(Coordinate(char(x - i), y + i));
        }
        if (this->isInBoard(x - i, y - i))
        {
            result.push_back(Coordinate(char(x - i), y - i));
        }
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

std::string Queen::getPieceCode()
{
    return this->pieceCode;
}

std::string Queen::getPieceType()
{
    return this->pieceType;
}

Queen::~Queen()
{

}