#ifndef SCREEN
#define SCREEN

#include "Square.hpp"
#include "bounding_box.hpp"

class Screen {

private:
  // holds the squares in contigous memory
  // accessed by getter to simulate a 2d array
  Square **map;
  /* 
     stores square assets which makes it easier
     to destroy (will need to check that it is not
     null)
     
     TO CONSIDER: make this a map?
  */
  Square **assets;
  

public:
  Screen();
  Square *get_square(int, int);
  void set_square(Square*, int, int);

  bool in_solid(BoundingBox);

  void draw();

};
#endif
