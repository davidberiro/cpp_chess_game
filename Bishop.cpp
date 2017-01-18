//
// Created by davidberiro on 1/17/17.
//

#include "Bishop.h"

Bishop::Bishop(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Bishop";
    this->pieceCode = "\u265D";
}

std::vector<Coordinate> Bishop::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    int curIndex;
    bool collided_1 = false;
    bool collided_2 = false;
    bool collided_3 = false;
    bool collided_4 = false;
    for (int i = 1; i <=7; i++)
    {
        if (this->isInBoard(x + i, y + i) && !(collided_1))
        {
            curIndex = this->boardIndex(x + i, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y + i));
            }
            else
            {
                collided_1 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y + i));
                }
            }
        }
        if (this->isInBoard(x + i, y - i) && !(collided_2))
        {
            curIndex = this->boardIndex(x + i, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y - i));
            }
            else
            {
                collided_2 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y - i));
                }
            }
        }
        if (this->isInBoard(x - i, y + i) && !(collided_3))
        {
            curIndex = this->boardIndex(x - i, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y + i));
            }
            else
            {
                collided_3 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y + i));
                }
            }
        }
        if (this->isInBoard(x - i, y - i) && !(collided_4))
        {
            curIndex = this->boardIndex(x - i, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y - i));
            }
            else
            {
                collided_4 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y - i));
                }
            }
        }
    }
    return result;
}

//std::string Bishop::getPieceCode()
//{
//    return this->pieceCode;
//}
//
//std::string Bishop::getPieceType()
//{
//    return this->pieceType;
//}

Bishop::~Bishop()
{

}
