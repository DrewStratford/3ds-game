#include <math.h>
#include "Vector2d.h"

/**
   A small file implementing 2d vectors
   and the basic operations on them.
*/


Vec2 add(Vec2 a, Vec2 b){
  Vec2 out;
  out.x = a.x + b.x;
  out.y = a.y + b.y;
  return out;
}

Vec2 minus(Vec2 a, Vec2 b){
  Vec2 out;
  out.x = a.x - b.x;
  out.y = a.y - b.y;
  return out;
}
float dot(Vec2 a, Vec2 b){
  return (a.x * b.x) + (a.y*b.y);
}

Vec2 scalar(float mult, Vec2 a){
  a.x *= mult;
  a.y *= mult;
  return a;
}

Vec2 normalise(Vec2 a){
  float norm = sqrtf((a.x * a.x) + (a.y * a.y));
  a.x = a.x/norm;
  a.y = a.y/norm;
  return a;
}
  
Vec2 reflect(Vec2 a, Vec2 normal){
  Vec2 out;
  float d = dot(a,normal);
  out.x = a.x - 2 * d * normal.x;
  out.y = a.y - 2 * d * normal.y;
  return out;
}

Vec2 vector2(float a, float b){
  Vec2 out;
  out.x  =a;
  out.y = b;
  return out;
}
