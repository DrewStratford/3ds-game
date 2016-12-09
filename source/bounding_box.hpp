#ifndef BOUNDING_BOX
#define BOUNDING_BOX

#include "Vector2d.h"
#include <vector>
#include <3ds.h>

class BoundingBox{
  Vec2 pos; //the top lefthand corner
  float height, width;
public:
  BoundingBox(Vec2 position, float h, float w);
  bool contains(Vec2 point);
  std::vector<Vec2> points();
  bool intersects(BoundingBox box);
};

#endif
