//
// Created by davidberiro on 1/17/17.
//

#include "Queen.h"

Queen::Queen(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "Queen";
    this-> pieceCode = "\u265B";
}

std::vector<Coordinate> Queen::getLegalMovesOnEmptyBoard(Piece *board[])
{
    Coordinate* location = this->getLocation();
    std::vector<Coordinate> result;
    char x = location->file;
    int y = location->rank;
    int curIndex;
    bool coll_1 = false;
    bool coll_2 = false;
    bool coll_3 = false;
    bool coll_4 = false;
    bool coll_5 = false;
    bool coll_6 = false;
    bool coll_7 = false;
    bool coll_8 = false;
    for (int i = 1; i <=7; i++)
    {
        if (this->isInBoard(x + i, y + i) && !(coll_1))
        {
            curIndex = this->boardIndex(x + i, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y + i));
            }
            else
            {
                coll_1 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y + i));
                }
            }
        }
        if (this->isInBoard(x + i, y - i) && !(coll_2))
        {
            curIndex = this->boardIndex(x + i, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y - i));
            }
            else
            {
                coll_2 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y - i));
                }
            }
        }
        if (this->isInBoard(x - i, y + i) && !(coll_3))
        {
            curIndex = this->boardIndex(x - i, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y + i));
            }
            else
            {
                coll_3 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y + i));
                }
            }
        }
        if (this->isInBoard(x - i, y - i) && !(coll_4))
        {
            curIndex = this->boardIndex(x - i, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y - i));
            }
            else
            {
                coll_4 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y - i));
                }
            }
        }
        if (this->isInBoard(x - i, y) && !(coll_5))
        {
            curIndex = this->boardIndex(x - i, y);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x - i), y));
            }
            else
            {
                coll_5 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x - i), y));
                }
            }
        }
        if (this->isInBoard(x + i, y) && !(coll_6))
        {
            curIndex = this->boardIndex(x + i, y);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x + i), y));
            }
            else
            {
                coll_6 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x + i), y));
                }
            }
        }
        if (this->isInBoard(x, y - i) && !(coll_7))
        {
            curIndex = this->boardIndex(x, y - i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x), y - i));
            }
            else
            {
                coll_7 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x), y - i));
                }
            }
        }
        if (this->isInBoard(x, y + i) && !(coll_8))
        {
            curIndex = this->boardIndex(x, y + i);
            if (board[curIndex]->getColor() == "none")
            {
                result.push_back(Coordinate(char(x), y + i));
            }
            else
            {
                coll_8 = true;
                if (board[curIndex]->getColor() != this->getColor())
                {
                    result.push_back(Coordinate(char(x), y +  i));
                }
            }
        }

    }
    return result;
}

Queen::~Queen()
{

}