//
// Created by davidberiro on 1/17/17.
//

#include "Bishop.h"

Bishop::Bishop(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Bishop";
}

std::vector<Coordinate> Bishop::getLegalMovesOnEmptyBoard()
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
    }
    return result;
}

std::string Bishop::getPieceCode()
{
    return this->pieceCode;
}

std::string Bishop::getPieceType()
{
    return this->pieceType;
}

Bishop::~Bishop()
{

}
