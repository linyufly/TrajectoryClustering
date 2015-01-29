// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef VECTOR_2D_H_
#define VECTOR_2D_H_

class Vector2D {
 public:
  Vector2D(double x, double y) : x_(x), y_(y) {}

  Vector2D(double *position) {
    x_ = position[0];
    y_ = position[1];
  }

  Vector2D(const Vector2D &other) {
    x_ = other.x_;
    y_ = other.y_;
  }

  Vector2D 

 private:
  double x_, y_;
};

#endif  // VECTOR_2D_H_
