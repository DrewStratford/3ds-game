#include <sf2d.h>
#include "player.hpp"

Player::Player(float x, float y){
  position = vector2(x,y);
}

void Player::draw(){
  auto colour = RGBA8(0xFF,0x00,0x00,0xFF);
  
  if(state == Player_State::attacking)
    colour += RGBA8(0xFF,0x00,0x00,0xFF);
  if(state == Player_State::moving)
    colour += RGBA8(0x00,0xFF,0x00,0xFF);
  if(state == Player_State::still)
    colour += RGBA8(0x00,0x00,0xFF,0xFF);
  
  sf2d_draw_rectangle((int)position.x,(int)position.y, width, height, colour);
}

void Player::tick(Screen * screen, u32 held, u32 pressed, u32 released){
  float scale = 2;
  Vec2 dir = vector2(0,0);

  Vec2 old_position = position;

  if(held & KEY_B || pressed & KEY_B)
    scale = 5;
  if(held & KEY_LEFT || pressed & KEY_LEFT)
    dir = vector2(-1,0);
  if(held & KEY_RIGHT || pressed & KEY_RIGHT)
    dir = vector2(1,0);
  if(held & KEY_UP || pressed & KEY_UP)
    dir = vector2(0,-1);
  if(held & KEY_DOWN || pressed & KEY_DOWN)
    dir = vector2(0,1);

  if(dir.x == 0 && dir.y == 0){
    state = Player_State::still;
  } else{
    state = Player_State::moving;
  }
    
  dir = scalar(scale, dir);
  position = add(position,dir);
  //check that we are not in a solid
  if(screen->in_solid(this->getBounding()))
    position = old_position;
}

int Player::getHealth(){
  return health;
}

BoundingBox Player::getBounding(){
  return BoundingBox(position, height, width);
}
