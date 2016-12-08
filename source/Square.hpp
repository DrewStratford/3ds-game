#ifndef squares
#define squares

#include "game_entity.hpp"

class Square {
public:
  virtual void draw(int, int);
  virtual void tick();
  virtual bool is_solid();
};

#endif
