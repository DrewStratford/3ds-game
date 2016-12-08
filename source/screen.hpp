#ifndef SCREEN
#define SCREEN

#include "Square.hpp"

class Screen {

private:
  // holds the squares in contigous memory
  // accessed by getter to simulate a 2d array
  Square **map;

public:
  Screen();
  Square *get_square(int, int);
  void set_square(Square*, int, int);

  void draw();

};
#endif
