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

void Player::tick(){
}

int Player::getHealth(){
  return health;
}

BoundingBox *Player::getBounding(){
  return NULL;
}
