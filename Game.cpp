#include "Game.hpp"
#include <stdio.h>

Game::Game()
{
}

Game::~Game()
{
    delete this->mBoard;
}

int Game::getTurnCount()
{
    return this->mTurnCount;
}

void Game::start()
{
    this->mBoard = new Board();

    printf("Board Size: %i x %i\n", this->mBoard->getXSize(), this->mBoard->getYSize());

    printf("Square color, occupied: %i, %s\n", this->mBoard->grid[0][0].color,
           this->mBoard->grid[0][0].occupied ? "true" : "false");
}

bool Game::isValidPlacement(int targetX, int targetY, Piece piece)
{

    return;
}
