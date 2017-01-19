//
// Created by davidberiro on 1/18/17.
//
#include "GameRunner.h"

const std::string MOVE_REQUEST = ": Please enter your move:";
const std::string 

GameRunner::GameRunner()
{
    this->board = new Board();
    this->startGame();
}

void GameRunner::startGame()
{
    std::string whitePlayer;
    std::string blackPlayer;
    std::string currentColor;
    int moveResult;

    std::cout << "Enter white player name:" << std::endl;
    std::cin >> whitePlayer;
    std::cout << "Enter black player name:" << std::endl;
    std::cin >> blackPlayer;

    this->board->printBoard();

    while(true)
    {
        std::string currentPlayer = whitePlayer;
        std::string playerMove;
        if (whiteToMove)
        {
            currentColor = "white";
            std::cout << whitePlayer << MOVE_REQUEST << std::endl;
            std::cin >> playerMove;
        }
        else{
            currentColor = "black";
            std::cout << blackPlayer << MOVE_REQUEST << std::endl;
            std::cin >> playerMove;
        }
        if (!legalCommand(playerMove))
        {
            this->board->printWithColor("illegal move");
            this->board->printBoard();
            continue;
        }
        moveResult = this->board->makeMove(playerMove, currentColor);
        if (moveResult == 1)
        {
            continue;
        }

        this->board->printBoard();

        if (moveResult == 2)
        {
            if (currentColor == "black")
            {
                currentPlayer = blackPlayer;
            }
            std::cout << currentPlayer << " won!" << std::endl;
            return;
        }
        if (whiteToMove)
        {
            whiteToMove = false;
        }
        else
        {
            whiteToMove = true;
        }
    }
}

bool GameRunner::legalCommand(std::string cmd)
{
    return (cmd.length() == 4
    && cmd.at(0) >= 'A' && cmd.at(0) <= 'H'
    && cmd.at(2) >= 'A' && cmd.at(2) <= 'H'
            && (cmd.at(1) - '0') >= 1 && (cmd.at(1) - '0') <= 8
            && (cmd.at(3) - '0') >= 1 && (cmd.at(3) - '0') <=8);
}

GameRunner::~GameRunner()
{
    delete (this->board);
}

