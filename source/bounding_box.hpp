#ifndef BOUNDING_BOX
#define BOUNDING_BOX

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

#endif
