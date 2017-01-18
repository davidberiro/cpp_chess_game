//
// Created by davidberiro on 1/17/17.
//

#include "Knight.h"

Knight::Knight(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Knight";
    this->pieceCode = "\u265E";
}

std::vector<Coordinate> Knight::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;

    if (this->isInBoard(x + 2, y + 1) && (board[this->boardIndex(x + 2, y + 1)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x + 2), y + 1);
        result.push_back(a);
    }
    if (this->isInBoard(x + 2, y - 1) && (board[this->boardIndex(x + 2, y - 1)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x + 2), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 2, y + 1) && (board[this->boardIndex(x - 2, y + 1)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x - 2), y + 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 2, y - 1) && (board[this->boardIndex(x - 2, y - 1)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x - 2), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x + 1, y + 2) && (board[this->boardIndex(x + 1, y + 2)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x + 1), y + 2);
        result.push_back(a);
    }
    if (this->isInBoard(x + 1, y - 2) && (board[this->boardIndex(x + 1, y - 2)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x + 1), y - 1);
        result.push_back(a);
    }
    if (this->isInBoard(x - 1, y + 2) && (board[this->boardIndex(x - 1, y + 2)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x - 1), y + 2);
        result.push_back(a);
    }
    if (this->isInBoard(x - 1, y - 2) && (board[this->boardIndex(x - 1, y - 2)]->getColor() != this->getColor()))
    {
        Coordinate a(char(x - 1), y - 2);
        result.push_back(a);
    }
    return result;
}

//std::string Knight::getPieceCode()
//{
//    return this->pieceCode;
//}

Knight::~Knight()
{

}