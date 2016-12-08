#ifndef SCREEN
#define SCREEN

#include "Square.hpp"
#include "game_entity.hpp"

class Screen {

private:
  // holds the squares in contigous memory
  // accessed by getter to simulate a 2d array
  Square **map;

public:
  Screen();
  Square *get_square(int, int);
  void set_square(Square*, int, int);

  bool in_solid(Entity*);

  void draw();

};
#endif
