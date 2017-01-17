//
// Created by davidberiro on 1/17/17.
//

#include "Board.h"
#define RANK_1 1
#define RANK_2 2
#define RANK_3 3
#define RANK_4 4
#define RANK_5 5
#define RANK_6 6
#define RANK_7 7
#define RANK_8 8
#define A_FILE 'A'
#define B_FILE 'B'
#define C_FILE 'C'
#define D_FILE 'D'
#define E_FILE 'E'
#define F_FILE 'F'
#define G_FILE 'G'
#define H_FILE 'H'
#define SPACE ' '
#define ZERO 0
#define NINE 9

const std::string WHITE = "white";
const std::string BLACK = "black";

Board::Board()
{
    //creating rooks
    this->boardArray[this->indexInBoardArray(A_FILE, RANK_1)] = new Rook(A_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(A_FILE, RANK_8)] = new Rook(A_FILE, RANK_8, BLACK);
    this->boardArray[this->indexInBoardArray(H_FILE, RANK_1)] = new Rook(H_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(H_FILE, RANK_8)] = new Rook(H_FILE, RANK_8, BLACK);
    //creating knights
    this->boardArray[this->indexInBoardArray(B_FILE, RANK_1)] = new Knight(B_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(B_FILE, RANK_8)] = new Knight(B_FILE, RANK_8, BLACK);
    this->boardArray[this->indexInBoardArray(G_FILE, RANK_1)] = new Knight(G_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(G_FILE, RANK_8)] = new Knight(G_FILE, RANK_8, BLACK);
    //creating bishops
    this->boardArray[this->indexInBoardArray(C_FILE, RANK_1)] = new Bishop(C_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(C_FILE, RANK_8)] = new Bishop(C_FILE, RANK_8, BLACK);
    this->boardArray[this->indexInBoardArray(F_FILE, RANK_1)] = new Bishop(F_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(F_FILE, RANK_8)] = new Bishop(F_FILE, RANK_8, BLACK);
    //creating queens
    this->boardArray[this->indexInBoardArray(D_FILE, RANK_1)] = new Queen(D_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(D_FILE, RANK_8)] = new Queen(D_FILE, RANK_8, BLACK);
    //creating kings
    this->boardArray[this->indexInBoardArray(E_FILE, RANK_1)] = new King(E_FILE, RANK_1, WHITE);
    this->boardArray[this->indexInBoardArray(E_FILE, RANK_8)] = new King(E_FILE, RANK_8, BLACK);
    //finally creating pawns
    for (char i = A_FILE; i <= H_FILE; i++)
    {
        this->boardArray[this->indexInBoardArray(i, RANK_2)] = new Pawn(i, RANK_2, WHITE);
        this->boardArray[this->indexInBoardArray(i, RANK_7)] = new Pawn(i, RANK_7, BLACK);
    }
}

int Board::indexInBoardArray(Coordinate location)
{
    return (BOARD_SIZE * (location.rank - 1)) + (int(location.file) % int(A_FILE));
}

int Board::indexInBoardArray(char x, int y)
{
    return (BOARD_SIZE * (y - 1)) + (int(x) % int(A_FILE));
}

void Board::printBoard()
{
    for (int i = NINE; i >= ZERO; i--)
    {
        if (i == ZERO || i == NINE)
        {
            std::cout << SPACE << SPACE;
        }
        else
        {
            std::cout << i << SPACE;
        }
        for (char j = A_FILE; j <= H_FILE; j++)
        {
            if (i == NINE)
            {
                if (j == H_FILE)
                {
                    std::cout << j << std::endl << std::endl;
                }
                else
                {
                    std::cout << j;
                }
            }
            else if (i == ZERO)
            {
                if (j == A_FILE)
                {
                    std::cout << std::endl << "  " << j;
                }
                else
                {
                    std::cout << j;
                }
            }
            else
            {

            }

        }
    }

}
