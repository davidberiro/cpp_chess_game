//
// Created by davidberiro on 1/18/17.
//
#include "GameRunner.h"

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

    std::cout << "Enter white player name:" << std::endl;
    std::cin >> whitePlayer;
    std::cout << "Enter black player name:" << std::endl;
    std::cin >> blackPlayer;

    this->board->printBoard();

    while(true)
    {
        std::string playerMove;
        if (whiteToMove)
        {
            currentColor = "white";
            std::cout << whitePlayer << ": please enter your move:" << std::endl;
            std::cin >> playerMove;
        }
        else{
            currentColor = "black";
            std::cout << blackPlayer << ": please enter your move:" << std::endl;
            std::cin >> playerMove;
        }
//        if (!legalCommand(playerMove))
//        {
//            continue;
//        }
        this->board->makeMove(playerMove, currentColor);
        this->board->printBoard();

        if (whiteToMove)
        {
            whiteToMove = false;
        }
        else
        {
            whiteToMove = true;
        }
        return;
    }
}

bool GameRunner::legalCommand(std::string cmd)
{
    return (cmd.length() == 4
    && cmd.at(0) >= 'A' && cmd.at(0) <= 'H'
    && cmd.at(2) >= 'A' && cmd.at(2) <= 'H'
            && cmd.at(1) >= 1 && cmd.at(1) <= 8
            && cmd.at(3) >= 1 && cmd.at(3) <=8);
}

GameRunner::~GameRunner()
{

}

