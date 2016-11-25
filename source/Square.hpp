#ifndef squares
#define squares

#include "game_entity.hpp"

class Square {
public:
	virtual BoundingBox getBounding();
  	virtual void draw();
  	virtual void tick();
};

#endif