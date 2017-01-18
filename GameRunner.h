//
// Created by davidberiro on 1/18/17.
//
#include "Board.h"

#ifndef EX2_GAMERUNNER_H
#define EX2_GAMERUNNER_H

class GameRunner
{
public:
    void startGame();
    GameRunner();
    ~GameRunner();
    bool legalCommand(std::string cmd);


private:
    Board *board;
    bool whiteToMove = true;
};

#endif //EX2_GAMERUNNER_H
