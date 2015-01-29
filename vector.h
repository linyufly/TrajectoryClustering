// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
 public:
  double norm() = 0;
  double dot(const Vector &) = 0;
  Vector add(const Vector &) = 0;
  Vector subtract(const Vector &) = 0;
  Vector scale_up(double lambda) = 0;
  Vector scale_down(double lambda) = 0;
};

#endif  // VECTOR_H_ 
