//
// Created by davidberiro on 1/17/17.
//

#include "King.h"

King::King(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "King";
    this->pieceCode = "\u265A";
}

std::vector<Coordinate> King::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;

    if (this->isInBoard(x + 1, y) && (board[this->boardIndex(x + 1, y)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x + 1), y));
    }
    if (this->isInBoard(x - 1, y) && (board[this->boardIndex(x - 1, y)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x -1), y));
    }
    if (this->isInBoard(x, y + 1) && (board[this->boardIndex(x, y + 1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x), y + 1));
    }
    if (this->isInBoard(x, y - 1) && (board[this->boardIndex(x, y - 1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x), y - 1));
    }
    if (this->isInBoard(x + 1, y + 1) && (board[this->boardIndex(x + 1, y + 1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x + 1), y + 1));
    }
    if (this->isInBoard(x + 1, y - 1) && (board[this->boardIndex(x + 1, y -1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x + 1), y - 1));
    }
    if (this->isInBoard(x - 1, y + 1) && (board[this->boardIndex(x - 1, y + 1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x - 1), y + 1));
    }
    if (this->isInBoard(x - 1, y - 1) && (board[this->boardIndex(x - 1, y - 1)]->getColor() != this->getColor()))
    {
        result.push_back(Coordinate(char(x - 1), y - 1));
    }
    return result;
}

//std::string King::getPieceCode()
//{
//    return this->pieceCode;
//}
//
//std::string King::getPieceType()
//{
//    return this->pieceType;
//}

King::~King()
{

}