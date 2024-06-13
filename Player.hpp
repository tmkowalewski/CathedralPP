#ifndef PLAYER_HPP

#include "Piece.hpp"
#include <vector>

#define LIGHT 0
#define DARK 1

class Player
{
  private:
    std::vector<Piece> mPieces;
    int mColor;
    int mScore;
    int mColor;

  public:
    Player(int color);
    ~Player();

    std::vector<Piece> getPieces();
    int getColor();
    int getScore();
    void setScore(int score);
};

#endif // PLAYER_HPP