#include "Board.hpp"

Board::Board()
{
    // initialize grid
    for (int i = 0; i < this->x_size; i++)
    {
        for (int j = 0; j < this->y_size; j++)
        {
            this->grid[i][j].color = -1;
            this->grid[i][j].occupied = false;
        }
    }
}

Board::~Board()
{
}

int Board::getXSize()
{
    return this->x_size;
}

int Board::getYSize()
{
    return this->y_size;
}
