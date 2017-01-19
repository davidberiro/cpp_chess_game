//
// Created by davidberiro on 1/17/17.
//

#include "Pawn.h"

Pawn::Pawn(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceCode = "\u265F";
    this->pieceType = "Pawn";
}

std::vector<Coordinate> Pawn::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    if (this->getColor() == "white")
    {
        if (board[this->boardIndex(x, y + 1)]->getColor() == "none")
        {
            result.push_back(Coordinate(x, y + 1));
        }
        if (y == 2 && board[this->boardIndex(x, y + 2)]->getColor() == "none")
        {
            result.push_back(Coordinate(char(x), 4));
        }
        if (this->isInBoard(x + 1, y + 1) && board[this->boardIndex(x + 1, y + 1)]->getColor() == "black")
        {
            result.push_back(Coordinate(char(x + 1), y + 1));
        }
        if (this->isInBoard(x - 1, y + 1) && board[this->boardIndex(x - 1, y + 1)]->getColor() == "black")
        {
            result.push_back(Coordinate(char(x - 1), y + 1));
        }
    }
    else if (this->getColor() == "black")
    {
        if (board[this->boardIndex(x, y - 1)]->getColor() == "none")
        {
            result.push_back(Coordinate(char(x), y - 1));
        }
        if (y == 7 && board[this->boardIndex(x, y - 2)]->getColor() == "none")
        {
            result.push_back(Coordinate(char(x), y - 2));
        }
        if (this->isInBoard(x - 1, y - 1) && board[this->boardIndex(x - 1, y - 1)]->getColor() == "white")
        {
            result.push_back(Coordinate(char(x - 1), y - 1));
        }
        if (this->isInBoard(x + 1, y - 1) && board[this->boardIndex(x + 1, y - 1)]->getColor() == "white")
        {
            result.push_back(Coordinate(char(x + 1), y - 1));
        }
    }
    return result;
}

//std::string Pawn::getPieceCode()
//{
//    return this->pieceCode;
//}
//
//std::string Pawn::getPieceType()
//{
//    return this->pieceType;
//}

Pawn::~Pawn()
{

}

