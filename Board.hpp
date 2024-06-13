#ifndef BOARD_HPP

class Board
{
  private:
    static const int x_size = 10;
    static const int y_size = 10;

    struct Cell
    {
        int color;
        bool occupied;
    };

  public:
    Cell grid[x_size][y_size];

    Board();
    ~Board();

    int getXSize();
    int getYSize();
};

#endif // BOARD_HPP