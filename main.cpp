#include <stdio.h>

#include "Game.cpp"

int main(int argc, char **argv)
{
    Game *game = new Game();
    game->start();
    return 0;
}
