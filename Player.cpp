#include "Player.hpp"

Player::Player(int color)
{
}

Player::~Player()
{
}

std::vector<Piece> Player::getPieces()
{
    return this->mPieces;
}

int Player::getColor()
{
    return this->mColor;
}

int Player::getScore()
{
    return this->mScore;
}

void Player::setScore(int score)
{
    this->mScore = score;
}
