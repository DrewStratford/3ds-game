#include "game_entity.hpp"
#include <vector>

#include "Vector2d.h"

class BoundingBox{
  Vec2 pos; //the top lefthand corner
  int height, width;

public:
  BoundingBox(Vec2 position, int h, int w){
    pos = position;
    height = h; width = w;
  }

  bool contains(Vec2 point){
    int x1 = pos.x, y1 = pos.y, x2 = x1 + width, y2 = y1 + height;
    
    return point.x >= x1 && point.x <= x2 && point.y >= y1 && point.y <= y2;
  }


  std::vector<Vec2> points(){
    auto ps = std::vector<Vec2>();
    ps.push_back(pos); ps.push_back(add(pos,vector2(0,height)));
    ps.push_back(add(pos,vector2(width,0))); ps.push_back(add(pos,vector2(width,height)));
    return ps;
  }
  
  bool intersects(BoundingBox box){
    for(auto p : box.points()){
      if(this->contains(p)){
	return true;
      }
    }
    return false;
  }
};


