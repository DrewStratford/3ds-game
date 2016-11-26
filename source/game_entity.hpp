#ifndef GAME_ENTITY
#define GAME_ENTITY

#include "Vector2d.h"
#include <vector>
#include <3ds.h>

class BoundingBox{
  Vec2 pos; //the top lefthand corner
  int height, width;
public:
  BoundingBox(Vec2 position, int h, int w);
  bool contains(Vec2 point);
  std::vector<Vec2> points();
  bool intersects(BoundingBox box);
};

/**
   An interface describing entities in the game eg player, brick
   characterized by being colideable (via bounding box), drawing and ticking.
 */
class Entity{
public:
  virtual BoundingBox *getBounding();
  virtual void draw();
  virtual void tick(u32 kHeld, u32 kPressed, u32 kUp);
  virtual int getHealth();
};

#endif
