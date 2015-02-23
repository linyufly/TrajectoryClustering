// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>

namespace {

template<typename T>
T square(T value) {
  return value * value;
}

}

template<typename T, int D>
class Vector {
 public:
  T norm() const {
    T result = T(0);

    for (int dimension = 0; dimension < D; dimension++) {
      result += square<T>(coordinates_[dimension]);
    }

    return static_cast<T>(sqrt(static_cast<double>(result)));
  }

  T dot(const Vector<T, D> &other) {
    T result = T(0);

    for (int dimension = 0; dimension < D; dimension++) {
      result += coordinates_[dimension] * other.coordinates_[dimension];
    }

    return result;
  }

  Vector<T, D> add(const Vector<T, D> &other) {
    Vector<T, D> result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] =
          coordinates_[dimension] + other.coordinates_[dimension];
    }

    return result;
  }

  Vector<T, D> subtract(const Vector<T, D> &other) {
    Vector<T, D> result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] =
          coordinates_[dimension] - other.coordinates_[dimension];
    }

    return result;
  }

  Vector<T, D> scale_up(double lambda) {
    Vector<T, D> result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] = coordinates_[dimension] * lambda;
    }

    return result;
  }

  Vector<T, D> scale_down(double lambda) {
    Vector<T, D> result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] = coordinates_[dimension] / lambda;
    }

    return result;
  }

 private:
  T coordinates_[D];
};

#endif  // VECTOR_H_ 
