#ifndef GAME_ENTITY
#define GAME_ENTITY

#include "screen.hpp"
#include "bounding_box.hpp"

/**
   An interface describing entities in the game eg player, brick
   characterized by being colideable (via bounding box), drawing and ticking.
 */
class Entity{
public:
  virtual BoundingBox getBounding();
  virtual void draw();
  virtual void tick(Screen * screen,u32 kHeld, u32 kPressed, u32 kUp);
  virtual int getHealth();
};

#endif
