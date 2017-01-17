//
// Created by davidberiro on 1/17/17.
//

#include "Knight.h"

Knight::Knight(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Knight";
}

std::vector<Coordinate> Knight::getLegalMovesOnEmptyBoard()
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;

    if (this->isInBoard(x + 2, y + 1))
    {
        Coordinate a(char(x + 2), y + 1);
        result.push_back(a);
    }
    if (this->isInBoard(x + 2, y - 1))
    {
        Coordinate a(char(x + 2), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 2, y + 1))
    {
        Coordinate a(char(x - 2), y + 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 2, y - 1))
    {
        Coordinate a(char(x - 2), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x + 1, y + 2))
    {
        Coordinate a(char(x + 1), y + 2);
        result.push_back(a);
    }
    if (this->isInBoard(x + 1, y - 2))
    {
        Coordinate a(char(x + 1), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 1, y + 2))
    {
        Coordinate a(char(x - 1), y + 2);
        result.push_back(a);
    }
    if (this->isInBoard(x - 1, y - 2))
    {
        Coordinate a(char(x - 1), y - 2);
        result.push_back(a);
    }
    return result;
}

std::string Knight::getPieceCode()
{
    return this->pieceCode;
}

std::string Knight::getPieceType()
{
    return this->pieceType;
}

Knight::~Knight()
{

}