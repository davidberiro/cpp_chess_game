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
#define ZERO 0
#define NINE 9

const std::string BACKGROUND_COLOR_1 = "42m";
const std::string BACKGROUND_COLOR_2 = "46m";
const std::string WHITE = "white";
const std::string BLACK = "black";
const std::string ESC_CODE_PRE = "\33";
const std::string ESC_CODE_SUF = "\33[0m";
const std::string SPACE = " ";


/**
 *
 * @return
 */
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
    this->whiteKing = this->boardArray[this->indexInBoardArray(E_FILE, RANK_1)];
    this->boardArray[this->indexInBoardArray(E_FILE, RANK_8)] = new King(E_FILE, RANK_8, BLACK);
    this->blackKing = this->boardArray[this->indexInBoardArray(E_FILE, RANK_8)];

    //finally creating pawns
    for (char i = A_FILE; i <= H_FILE; i++)
    {
        this->boardArray[this->indexInBoardArray(i, RANK_2)] = new Pawn(i, RANK_2, WHITE);
        this->boardArray[this->indexInBoardArray(i, RANK_7)] = new Pawn(i, RANK_7, BLACK);
    }
    //creating empty pieces on rest of the board
    for (int i = RANK_3; i<= RANK_6; i++)
    {
        for (char j = A_FILE; j <= H_FILE; j++)
        {
            this->boardArray[this->indexInBoardArray(j, i)] = new EmptyPiece(j, i);
        }
    }
}

/**
 *
 * @param board
 * @return
 */
Board::Board(const Board &board)
{
    Coordinate *currentCoordinate;
    char x;
    int y;
    std::string currentColor;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        currentCoordinate = board.boardArray[i]->getLocation();
        x = currentCoordinate->file;
        y = currentCoordinate->rank;
        currentColor = board.boardArray[i]->getColor();
        if (board.boardArray[i]->getType() == "King")
        {
            if (currentColor == WHITE)
            {
                this->boardArray[i] = new King(x, y, WHITE);
                this->whiteKing = this->boardArray[i];
            }
            else
            {
                this->boardArray[i] = new King(x, y, BLACK);
                this->blackKing = this->boardArray[i];
            }
        }
        else if (board.boardArray[i]->getType() == "Queen")
        {
            this->boardArray[i] = new Queen(x, y, currentColor);
        }
        else if (board.boardArray[i]->getType() == "Rook")
        {
            this->boardArray[i] = new Rook(x, y, currentColor);
        }
        else if (board.boardArray[i]->getType() == "Bishop")
        {
            this->boardArray[i] = new Bishop(x, y, currentColor);
        }
        else if (board.boardArray[i]->getType() == "Knight")
        {
            this->boardArray[i] = new Knight(x, y, currentColor);
        }
        else if (board.boardArray[i]->getType() == "Pawn")
        {
            this->boardArray[i] = new Pawn(x, y, currentColor);
        }
        else if (board.boardArray[i]->getType() == "none")
        {
            this->boardArray[i] = new EmptyPiece(x, y);
        }
    }
}

/**
 *
 * @param location
 * @return
 */
int Board::indexInBoardArray(Coordinate location)
{
    return (RANK_8 * (location.rank - 1)) + (int(location.file) % int(A_FILE));
}

/**
 *
 * @param x
 * @param y
 * @return
 */
int Board::indexInBoardArray(char x, int y)
{
    return (RANK_8 * (y - 1)) + (int(x) % int(A_FILE));
}

/**
 *
 * @param userMove
 * @param userColor
 * @return
 */
int Board::makeMove(std::string userMove, std::string userColor)
{
    std::string opponentColor = WHITE;
    char src_x = userMove.at(0);
    int src_y = int(userMove.at(1) - '0');
    char dest_x = userMove.at(2);
    int dest_y = int(userMove.at(3) - '0');
    bool isLocationLegal = false;
    std::vector<Coordinate> legalDestinations;
    std::vector<Coordinate>::iterator it;
    Piece *pieceToMove = this->boardArray[indexInBoardArray(src_x, src_y)];

    if (userColor == WHITE)
    {
        opponentColor = BLACK;
    }

    //check if user is trying to move something that isnt his..
    if (pieceToMove->getColor() != userColor)
    {
        return 1;
    }

    legalDestinations = pieceToMove->getLegalMovesOnEmptyBoard(this->boardArray);
    for (it = legalDestinations.begin(); it != legalDestinations.end(); ++it)
    {
        //std::cout << "legal move: " << (*it).file << (*it).rank << "\n" << std::flush;
        if ((*it).file == dest_x && (*it).rank == dest_y)
        {
            isLocationLegal = true;
        }
    }
    //if not in legal moves
    if (!isLocationLegal)
    {
        printWithColor("illegal move");
        //std::cout<<"illegal move"<< "\n" <<std::flush;
        return 1;
    }

    //if move leaves users king threatened
    Board tempBoard(*this);
    tempBoard.movePiece(Coordinate(src_x, src_y), Coordinate(dest_x, dest_y));
    if (tempBoard.isPieceThreatened(tempBoard.getKing(userColor)))
    {
        printWithColor("illegal move");
        return 1;
    }

    //now we have to check for castling..
    if (pieceToMove->getType() == "King")
    {
        char newRookFile, oldRookFile;
        int rookRank = src_y;
        //in case of castling kingside
        if (src_x + 2 == dest_x)
        {
            newRookFile = char(src_x + 1);
            oldRookFile = char(src_x + 3);
            tempBoard.movePiece(Coordinate(oldRookFile, rookRank), Coordinate(newRookFile, rookRank));
            if (tempBoard.isPieceThreatened(tempBoard.boardArray[indexInBoardArray(newRookFile, rookRank)]))
            {
                printWithColor("illegal move");
                return 1;
            }
            this->movePiece(Coordinate(oldRookFile, rookRank), Coordinate(newRookFile, rookRank));
        }
        else if (src_x - 2 == dest_x)
        {
            newRookFile = char(src_x - 1);
            oldRookFile = char(src_x - 4);
            tempBoard.movePiece(Coordinate(oldRookFile, rookRank), Coordinate(newRookFile, rookRank));
            if (tempBoard.isPieceThreatened(tempBoard.boardArray[indexInBoardArray(newRookFile, rookRank)]))
            {
                printWithColor("illegal move");
                return 1;
            }
            this->movePiece(Coordinate(oldRookFile, rookRank), Coordinate(newRookFile, rookRank));
        }
    }

    this->movePiece(Coordinate(src_x, src_y), Coordinate(dest_x, dest_y));
    //if opponents king is in check
    if (isPieceThreatened(this->getKing(opponentColor)))
    {
        printWithColor("Check!");
        if (isCheckMate(this->getKing(opponentColor)))
        {
            return 2;
        }
    }
    return 0;
}

/**
 *
 * @param king
 * @return
 */
bool Board::isCheckMate(Piece* king)
{
    std::vector<Coordinate> legalMoves;
    std::string kingColor = king->getColor();
    std::vector<Coordinate>::iterator it;
    Coordinate *src;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (this->boardArray[i]->getColor() != kingColor)
        {
            continue;
        }
        src = this->boardArray[i]->getLocation();
        legalMoves = this->boardArray[i]->getLegalMovesOnEmptyBoard(this->boardArray);
        for (it = legalMoves.begin(); it != legalMoves.end(); ++it)
        {
            Board tempBoard = Board(*this);
            tempBoard.movePiece(Coordinate(src->file, src->rank), *it);
            if (!tempBoard.isPieceThreatened(tempBoard.getKing(kingColor)))
            {
                return false;
            }
        }
    }
    return true;
}

/**
 *
 * @param myVector
 * @param myCoordinate
 * @return
 */
bool Board::isInVector(std::vector<Coordinate> myVector, Coordinate *myCoordinate)
{
    for (std::vector<Coordinate>::iterator it = myVector.begin(); it != myVector.end(); it++)
    {
        if ((*it).rank == myCoordinate->rank && (*it).file == myCoordinate->file)
        {
            return true;
        }
    }
    return false;
}

/**
 *
 * @param location
 * @param destination
 */
void Board::movePiece(Coordinate location, Coordinate destination)
{
    int destinationIndex = indexInBoardArray(destination);
    int locationIndex = indexInBoardArray(location);
    delete this->boardArray[destinationIndex];
    this->boardArray[destinationIndex] = nullptr;
    std::string pieceType = this->boardArray[locationIndex]->getType();
    //checking if pawn reaches 1st/8th rank to promote to queen
    if (pieceType == "Pawn")
    {
        if (destination.rank == RANK_8 || destination.rank == RANK_1)
        {
            std::string pawnColor = this->boardArray[locationIndex]->getColor();
            char file = destination.file;
            int rank = destination.rank;
            this->boardArray[destinationIndex] = new Queen(file, rank, pawnColor);
            this->boardArray[locationIndex] = new EmptyPiece(location.file, location.rank);
            return;
        }
    }
    this->boardArray[destinationIndex] = this->boardArray[locationIndex];
    this->boardArray[destinationIndex]->setLocation(new Coordinate(destination.file, destination.rank));
    this->boardArray[locationIndex] = new EmptyPiece(location.file, location.rank);
    return;
}

/**
 *
 * @param defender
 * @return
 */
bool Board::isPieceThreatened(Piece *defender)
{
    std::string opponentsColor = WHITE;
    if (defender->getColor() == WHITE)
    {
        opponentsColor = BLACK;
    }
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        Piece *currentPiece = this->boardArray[i];
        if (currentPiece->getColor() != opponentsColor)
        {
            continue;
        }
        std::vector<Coordinate> attackVector = currentPiece->getLegalMovesOnEmptyBoard(this->boardArray);
        if (isInVector(attackVector, defender->getLocation()))
        {
            return true;
        }
    }
    return false;
}

Piece* Board::getKing(std::string kingColor)
{
    if (kingColor == WHITE)
    {
        return this->whiteKing;
    }
    return this->blackKing;
}

void Board::printBoard()
{
    std::string curColor;
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
                if ((i + j) % 2)
                {
                    curColor = BACKGROUND_COLOR_2;
                }
                else
                {
                    curColor = BACKGROUND_COLOR_1;
                }
                printBoardLocation(j, i, curColor);
                if (j == H_FILE)
                {
                    std::cout << " " << i << "\n";
                }
            }
        }
    }
    std::cout << std::endl << std::endl;
}

void Board::printBoardLocation(const char file, const int rank, std::string backGroundColor)
{
    int index = indexInBoardArray(file, rank);
    std::string pieceCode = this->boardArray[index]->getPieceCode();
    std::string colorCode = this->boardArray[index]->getPieceColorCode();
    std::cout << ESC_CODE_PRE << colorCode << backGroundColor << pieceCode << ESC_CODE_SUF;
}

std::vector<Coordinate> Board::getPieceLocations(std::string color)
{
    Coordinate* pieceCoordinate;
    std::vector<Coordinate> result;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (this->boardArray[i]->getColor() == color)
        {
            pieceCoordinate = this->boardArray[i]->getLocation();
            result.push_back(Coordinate(pieceCoordinate->file, pieceCoordinate->rank));
        }
    }
    return result;
}

void Board::printWithColor(std::string message)
{
    std::cout << "\33[37;41m" << message << "\33[0m\n";
}


Board::~Board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        delete (this->boardArray[i]);
        this->boardArray[i] = nullptr;
    }
}

