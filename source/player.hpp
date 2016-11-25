#ifndef PLAYER
#define PLAYER

#include "game_entity.hpp"
#include "Vector2d.h"

/**
   Description of the players state
*/
enum Player_State{moving, attacking, still};

class Player : public Entity{
private:
  int health = 100;
  Vec2 position;
  Vec2 facing = vector2(0,1);
  int height = 50;
  int width  = 20;
  Player_State state = still;

public:
  Player(float x, float y);
  void draw();
  void tick();
  int getHealth();
  BoundingBox *getBounding();
};

#endif
