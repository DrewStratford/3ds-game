
/**
   A small file implementing 2d vectors
   and the basic operations on them.
*/

typedef struct {
  float x;
  float y;
} Vec2;

Vec2 add(Vec2 a, Vec2 b); 
Vec2 minus(Vec2 a, Vec2 b);
float dot(Vec2 a, Vec2 b); 
Vec2 scalar(float mult, Vec2 a); 
Vec2 normalise(Vec2 a); 
Vec2 reflect(Vec2 a, Vec2 normal); 
Vec2 vector2(float a, float b);
