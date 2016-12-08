#include <sf2d.h>

#include "screen.hpp"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 240

// approx 10 * 6 tiles on the top screen
#define TILE_SIZE 16
#define VERT_TILES 15
#define HORI_TILES 25

/*
  Some simple tile classes to test
*/
class Wall : public Square{
public:
  void tick(){}
  bool is_solid(){return true;}
  void draw(int x, int y){
    auto colour = RGBA8(0xF4,0xA4,0x60,0xFF);
    sf2d_draw_rectangle(x, y, TILE_SIZE, TILE_SIZE, colour);
  }
  
};

class Floor : public Square{
public:
  void tick(){}
  bool is_solid(){return false;}
  void draw(int x, int y){
    auto colour = RGBA8(0x99,0x99,0x99,0xFF);
    sf2d_draw_rectangle(x, y, TILE_SIZE, TILE_SIZE, colour);
  }
};
/**
   Converts coordinates to contigous map.
   Use this as apposed to by hand to avoid
   confusion.
*/
int convert_coords(int x, int y){
  return (y * HORI_TILES) + x;
}

Screen::Screen(){
  //make some featherweight references of tiles
  //(Should make some manager so that these can be destroyed easily)
  Square *wall = new Wall();
  Square *floor = new Floor();
  map = new Square*[HORI_TILES * VERT_TILES];

  //init all squares to floors
  for(int i = 0; i < HORI_TILES * VERT_TILES; ++i){
    map[i] = floor;
  }
  // set top wall
  for(int i = 0; i < HORI_TILES; ++i){
    map[i] = wall;
  }

  //draw diag
  int x = 0;
  int y = 0;
  while(x + (y * HORI_TILES) < HORI_TILES * VERT_TILES){
    map[x + (y * HORI_TILES)] = wall;
    ++x;
    ++y;
  }
}


void Screen::set_square(Square *square,int x, int y){
  map[convert_coords(x, y)] = square;
} 


Square *Screen::get_square(int x, int y){
  return map[convert_coords(x, y)];
}

/**
   Iterates through the map and draws the squares
*/
void Screen::draw(){
  for(int y = 0; y < VERT_TILES; y++){
    for(int x = 0; x < HORI_TILES; x++){
      map[convert_coords(x,y)]->draw(x * TILE_SIZE, y * TILE_SIZE);
    }
  }
}

/** 
    returns true whenever @entity is inside a 
    piece of terrain that is considered solid.
*/
bool Screen::in_solid(Entity * entity){
  BoundingBox bounds = entity->getBounding();
  /*
    iterate through the points in the bounding box
    to check if they are in a solid square
  */
  for(auto vec : bounds.points()){
    // find tile we're in using modulo
    int x = (int)vec.x % TILE_SIZE;
    int y = (int)vec.y % TILE_SIZE;
    Square * square = get_square(x,y);
    if(square->is_solid()){
      return true;
    }
  }
    
  return false;
}
