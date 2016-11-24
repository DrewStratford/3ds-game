class BoundingBox;

/**
   An interface describing entities in the game eg player, brick
   characterized by being colideable (via bounding box), drawing and ticking.
 */
class Entity{
public:
  //virtual BoundingBox &getBounding();
  virtual void draw();
  virtual void tick();
};
