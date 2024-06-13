#ifndef GAME_HPP

#include "Board.hpp"
#include "Piece.hpp"
#include "Player.hpp"

#define LIGHT 0
#define DARK 1

class Game
{
  private:
    Board *mBoard;
    int mTurnCount;

  public:
    Game();
    ~Game();

    int getTurnCount();

    void start();
    bool isValidPlacement(int targetX, int targetY, Piece piece);
};

#endif // GAME_HPP