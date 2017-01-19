//
// Created by davidberiro on 1/17/17.
//

#include "King.h"
#include "Rook.h"

King::King(const char file, const int rank, std::string color) : Piece(file, rank, color)
{
    this->pieceType = "King";
    this->pieceCode = "\u265A";
    this->hasMoved = false;
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
    if (this->isInBoard(x + 1, y - 1) && (board[this->boardIndex(x + 1, y - 1)]->getColor() != this->getColor()))
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
    //checking for castling and whatnots, fml its messy
    if (x == 'E' && !this->isMoved())
    {
        Piece *kingsBishop = board[this->boardIndex('F', y)];
        Piece *kingsKnight = board[this->boardIndex('G', y)];
        Piece *queen = board[this->boardIndex('D', y)];
        Piece *queensBishop = board[this->boardIndex('C', y)];
        Piece *queensKnight = board[this->boardIndex('B', y)];
        Piece *kingsRook = board[this->boardIndex('H', y)];
        Piece *queensRook = board[this->boardIndex('A', y)];
        //if white king is on E1
        if (this->getColor() == "white" && y == 1)
        {
            //if kings bishop and knight arent there
            if (kingsKnight->getType() == "none" && kingsBishop->getType() == "none")
            {
                //if kings rook is there and hasnt moved
                if (kingsRook->getColor() == "white" && kingsRook->getType() == "Rook"
                        && !(dynamic_cast<Rook *>(kingsRook)->isMoved()))
                {
                    result.push_back(Coordinate('G', y));
                }

            }
            if (queen->getType() == "none" && queensBishop->getType() == "none" && queensKnight->getType() == "none")
            {
                if (queensRook->getColor() == "white" && queensRook->getType() == "Rook"
                        && !(dynamic_cast<Rook *>(queensRook)->isMoved()))
                {
                    result.push_back(Coordinate('C', y));
                }
            }
        }
        else if (this->getColor() == "black" && y == 8)
        {
            if (kingsKnight->getType() == "none" && kingsBishop->getType() == "none")
            {
                if (kingsRook->getColor() == "black" && kingsRook->getType() == "Rook"
                    && !(dynamic_cast<Rook *>(kingsRook)->isMoved()))
                {
                    result.push_back(Coordinate('G', y));
                }

            }
            if (queen->getType() == "none" && queensBishop->getType() == "none" && queensKnight->getType() == "none")
            {
                if (queensRook->getColor() == "black" && queensRook->getType() == "Rook"
                    && !(dynamic_cast<Rook *>(queensRook)->isMoved()))
                {
                    result.push_back(Coordinate('C', y));
                }
            }
        }
    }
    return result;
}

bool King::isMoved()
{
    return this->hasMoved;
}

void King::movedKing()
{
    this->hasMoved = true;
}

King::~King()
{

}