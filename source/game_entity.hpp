#ifndef game_entity
#define game_entity

#include "Vector2d.h"
#include <vector>

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
  virtual void tick();
};

#endif
