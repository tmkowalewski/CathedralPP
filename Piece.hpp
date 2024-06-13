#ifndef PIECE_HPP

#include <array>
#include <stdexcept>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define TAVERN 0
#define STABLE 1
#define INN 2
#define BRIDGE 3
#define SQUARE 4
#define ABBEY 5
#define MANOR 6
#define TOWER 7
#define INFIRMARY 8
#define CASTLE 9
#define ACADEMY 10

#define LIGHT 0
#define DARK 1

#define CW 1
#define CCW -1

class Piece
{
  private:
    int mPrimeX;  // the x location prime square of the piece
    int mPrimeY;  // the y location prime square of the piece
    int mOffsetX; // prime x location relative to top left of footprint
    int mOffsetY; // prime y location relative to top left of footprint
    int mOrientation;
    bool mPlaced;
    int mColor;
    int mBuildingType;
    int mValue;
    std::array<std::array<int, 3>, 3> mFootprint;

  public:
    Piece(int buildingType, int color);
    ~Piece();

    int getPrimeX();
    int getPrimeY();
    int getOrientation();
    int getColor();
    int getBuildingType();
    int getValue();
    std::array<std::array<int, 3>, 3> getFootprint();
    void rotate(int direction);
};

#endif // PIECE_HPP
