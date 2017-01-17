//
// Created by davidberiro on 1/17/17.
//

#include "King.h"

King::King(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "King";
}

std::vector<Coordinate> King::getLegalMovesOnEmptyBoard()
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;

    if (this->isInBoard(x + 1, y))
    {
        result.push_back(Coordinate(char(x + 1), y));
    }
    if (this->isInBoard(x - 1, y))
    {
        result.push_back(Coordinate(char(x -1), y));
    }
    if (this->isInBoard(x, y + 1))
    {
        result.push_back(Coordinate(char(x), y + 1));
    }
    if (this->isInBoard(x, y - 1))
    {
        result.push_back(Coordinate(char(x), y - 1));
    }
    if (this->isInBoard(x + 1, y + 1))
    {
        result.push_back(Coordinate(char(x + 1), y + 1));
    }
    if (this->isInBoard(x + 1, y - 1))
    {
        result.push_back(Coordinate(char(x + 1), y - 1));
    }
    if (this->isInBoard(x - 1, y + 1))
    {
        result.push_back(Coordinate(char(x - 1), y + 1));
    }
    if (this->isInBoard(x - 1, y - 1))
    {
        result.push_back(Coordinate(char(x - 1), y - 1));
    }
    return result;
}

std::string King::getPieceCode()
{
    return this->pieceCode;
}

std::string King::getPieceType()
{
    return this->pieceType;
}

King::~King()
{

}