//
// Created by davidberiro on 1/17/17.
//

#include "Rook.h"

Rook::Rook(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Rook";
    this->pieceCode = "\u265C";
}

std::vector<Coordinate> Rook::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    int curIndex;
    bool collided_up = false;
    bool collided_down = false;
    bool collided_right = false;
    bool collided_left = false;
    for (int i = 1; i <=7; i++)
    {
        if (this->isInBoard(x - i, y) && !(collided_left))
        {
            curIndex = this->boardIndex(x - i, y);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y));
            }
            else
            {
                collided_left = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y));
                }
            }

        }
        if (this->isInBoard(x + i, y) && !(collided_right))
        {
            curIndex = this->boardIndex(x + i, y);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y));
            }
            else
            {
                collided_right = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y));
                }
            }
        }
        if (this->isInBoard(x, y - i) && !(collided_down))
        {
            curIndex = this->boardIndex(x, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x), y - i));
            }
            else
            {
                collided_down = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x), y - i));
                }
            }
        }
        if (this->isInBoard(x, y + i) && !(collided_up))
        {
            curIndex = this->boardIndex(x, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x), y + i));
            }
            else
            {
                collided_up = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x), y + i));
                }
            }
        }

    }
    return result;
}

//std::string Rook::getPieceCode()
//{
//    return this->pieceCode;
//}
//
//std::string Rook::getPieceType()
//{
//    return this->pieceType;
//}

Rook::~Rook()
{

}