#include "Piece.hpp"

Piece::Piece(int buildingType, int color)
{
    this->mPrimeX = -1;
    this->mPrimeY = -1;
    this->mOrientation = NORTH;
    this->mPlaced = false;
    this->mBuildingType = buildingType;
    this->mColor = color;

    // initialize piece footprint
    switch (this->mBuildingType)
    {

    case TAVERN:

        this->mValue = 1;

        this->mFootprint[0] = {1, 0, 0};
        this->mFootprint[1] = {0, 0, 0};
        this->mFootprint[2] = {0, 0, 0};

        this->mOffsetX = 0;
        this->mOffsetY = 0;

        break;

    case STABLE:

        this->mValue = 2;

        this->mFootprint[0] = {1, 0, 0};
        this->mFootprint[1] = {1, 0, 0};
        this->mFootprint[2] = {0, 0, 0};

        this->mOffsetX = 0;
        this->mOffsetY = 0;

        break;

    case INN:

        this->mValue = 3;

        this->mFootprint[0] = {1, 0, 0};
        this->mFootprint[1] = {1, 1, 0};
        this->mFootprint[2] = {0, 0, 0};

        this->mOffsetX = 0;
        this->mOffsetY = 0;

        break;

    case BRIDGE:

        this->mValue = 3;

        this->mFootprint[0] = {1, 0, 0};
        this->mFootprint[1] = {1, 0, 0};
        this->mFootprint[2] = {1, 0, 0};

        this->mOffsetX = 0;
        this->mOffsetY = 0;

        break;

    case SQUARE:

        this->mValue = 4;

        this->mFootprint[0] = {1, 1, 0};
        this->mFootprint[1] = {1, 1, 0};
        this->mFootprint[2] = {0, 0, 0};

        this->mOffsetX = 0;
        this->mOffsetY = 0;

        break;

    case ABBEY:

        this->mValue = 4;

        if (this->mColor == LIGHT)
        {
            this->mFootprint[0] = {1, 0, 0};
            this->mFootprint[1] = {1, 1, 0};
            this->mFootprint[2] = {0, 1, 0};

            this->mOffsetX = 0;
            this->mOffsetY = 0;
        }
        else
        {
            this->mFootprint[0] = {0, 1, 0};
            this->mFootprint[1] = {1, 1, 0};
            this->mFootprint[2] = {1, 0, 0};

            this->mOffsetX = 1;
            this->mOffsetY = 0;
        }

        break;

    case MANOR:

        this->mValue = 3;

        this->mFootprint[0] = {0, 1, 0};
        this->mFootprint[1] = {1, 1, 1};
        this->mFootprint[2] = {0, 0, 0};

        this->mOffsetX = 1;
        this->mOffsetY = 0;

        break;

    case TOWER:

        this->mValue = 5;

        this->mFootprint[0] = {0, 0, 1};
        this->mFootprint[1] = {0, 1, 1};
        this->mFootprint[2] = {1, 1, 0};

        this->mOffsetX = 2;
        this->mOffsetY = 0;

        break;

    case INFIRMARY:

        this->mValue = 5;

        this->mFootprint[0] = {0, 1, 0};
        this->mFootprint[1] = {1, 1, 1};
        this->mFootprint[2] = {0, 1, 0};

        this->mOffsetX = 1;
        this->mOffsetY = 1;

        break;

    case CASTLE:

        this->mValue = 5;

        this->mFootprint[0] = {1, 1, 0};
        this->mFootprint[1] = {1, 0, 0};
        this->mFootprint[2] = {1, 1, 0};

        this->mOffsetX = 1;
        this->mOffsetY = 0;

        break;

    case ACADEMY:

        this->mValue = 5;

        if (this->mColor == LIGHT)
        {
            this->mFootprint[0] = {0, 1, 0};
            this->mFootprint[1] = {1, 1, 0};
            this->mFootprint[2] = {0, 1, 1};
        }
        else
        {
            this->mFootprint[0] = {0, 1, 0};
            this->mFootprint[1] = {0, 1, 1};
            this->mFootprint[2] = {1, 1, 0};
        }

        this->mOffsetX = 1;
        this->mOffsetY = 0;

        break;

    default:

        throw std::invalid_argument("Invalid building type.");

        break;
    }
}

Piece::~Piece()
{
}

int Piece::getPrimeX()
{
    return this->mPrimeX;
}

int Piece::getPrimeY()
{
    return this->mPrimeY;
}

int Piece::getOrientation()
{
    return this->mOrientation;
}

int Piece::getColor()
{
    return this->mColor;
}

int Piece::getBuildingType()
{
    return this->mBuildingType;
}

int Piece::getValue()
{
    return this->mValue;
}

std::array<std::array<int, 3>, 3> Piece::getFootprint()
{
    return this->mFootprint;
}

void Piece::rotate(int direction)
{
    // PrimeFootprint is a temporary array that will hold the rotated prime location
    std::array<std::array<int, 3>, 3> PrimeFootprint;

    PrimeFootprint[0] = {0, 0, 0};
    PrimeFootprint[1] = {0, 0, 0};
    PrimeFootprint[2] = {0, 0, 0};

    // Use the offset to set the prime location of the piece
    PrimeFootprint[this->mOffsetY][this->mOffsetX] = 1;

    if (direction == CW) // clockwise
    {
        this->mOrientation = (this->mOrientation + 1) % 4;

        // taking the transpose and then reversing the rows rotates the matrix 90 degrees clockwise
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < i; j++)
            {
                std::swap(this->mFootprint[i][j], this->mFootprint[j][i]);
                std::swap(PrimeFootprint[i][j], PrimeFootprint[j][i]);
            }
        }

        for (int i = 0; i < 3; i++)
        {
            std::reverse(this->mFootprint[i].begin(), this->mFootprint[i].end());
            std::reverse(PrimeFootprint[i].begin(), PrimeFootprint[i].end());
        }
    }
    else if (direction == CCW) // counterclockwise
    {
        this->mOrientation = (this->mOrientation - 1) % 4;

        // reversing the rows and then taking the transpose rotates the matrix 90 degrees
        // counterclockwise
        for (int i = 0; i < 3; i++)
        {
            std::reverse(this->mFootprint[i].begin(), this->mFootprint[i].end());
            std::reverse(PrimeFootprint[i].begin(), PrimeFootprint[i].end());
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < i; j++)
            {
                std::swap(this->mFootprint[i][j], this->mFootprint[j][i]);
                std::swap(PrimeFootprint[i][j], PrimeFootprint[j][i]);
            }
        }
    }
    else
    {
        throw std::invalid_argument("Invalid rotation direction.");
    }

    // Use the prime location to set the new offset
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (PrimeFootprint[y][x] == 1)
            {
                this->mOffsetX = y;
                this->mOffsetY = x;
            }
        }
    }
}
