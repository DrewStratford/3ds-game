#ifndef squares
#define squares


class Square {
public:
  virtual void draw(int, int);
  virtual void tick();
  virtual bool is_solid();
};

#endif
