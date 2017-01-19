//
// Created by davidberiro on 1/17/17.
//
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Coordinate.h"
#include "EmptyPiece.h"

#ifndef EX2_BOARD_H
#define EX2_BOARD_H
#define BOARD_SIZE 64

class Board
{
public:
    /**
     * creates starting board
     * @return
     */
    Board();

    Board(const Board &board);

    int movePiece(std::string command);

    void printBoard();

    void printBoardLocation(const char file, const int rank, std::string color);

    std::vector<Coordinate> getPieceLocations(std::string color);

    int makeMove(std::string userMove, std::string userColor);

    Piece* getKing(std::string kingColor);

    bool isPieceThreatened(Piece *defender);

    bool isInVector(std::vector<Coordinate> myVector, Coordinate *myCoordinate);

    void movePiece(Coordinate location, Coordinate destination);

    void printWithColor(std::string message);

    bool isCheckMate(Piece *king);

    ~Board();

private:
    // how boardArray represents the chess board
    // 8
    // 7
    // 6
    // 5
    // 4
    // 3 (...........so on)
    // 2 (8...........15)
    // 1 (0...........7) <-- array indexes relation to board location
    //  A B C D E F G H
    Piece *boardArray[BOARD_SIZE];
    Piece *whiteKing;
    Piece *blackKing;
    int indexInBoardArray(Coordinate location);
    int indexInBoardArray(char x, int y);
};


#endif //EX2_BOARD_H