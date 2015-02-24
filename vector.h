// Author: Mingcheng Chen (linyufly@gmail.com)
// Test GitHub

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>

#include <algorithm>

namespace {

template<typename T>
T square(T value) {
  return value * value;
}

}

template<typename T, int D>
class Vector {
 public:
  Vector() {
  }

  Vector(T x, T y) {
    coordinates_[0] = x;
    coordinates_[1] = y;
  }

  Vector(T x, T y, T z) {
    coordinates_[0] = x;
    coordinates_[1] = y;
    coordinates_[2] = z;
  }

  Vector(T *coordinates) {
    std::copy(coordinates, coordinates + D, coordinates_);
  }

  T get_component(int dimension) const {
    return coordinates_[dimension];
  }

  void set_component(int dimension, const T &value) {
    coordinates_[dimension] = value;
  }

  T norm() const {
    T result = T(0);

    for (int dimension = 0; dimension < D; dimension++) {
      result += square<T>(coordinates_[dimension]);
    }

    return static_cast<T>(sqrt(static_cast<double>(result)));
  }

  T dot(const Vector &other) const {
    T result = T(0);

    for (int dimension = 0; dimension < D; dimension++) {
      result += coordinates_[dimension] * other.coordinates_[dimension];
    }

    return result;
  }

  Vector add(const Vector &other) const {
    Vector result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] =
          coordinates_[dimension] + other.coordinates_[dimension];
    }

    return result;
  }

  Vector subtract(const Vector &other) const {
    Vector result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] =
          coordinates_[dimension] - other.coordinates_[dimension];
    }

    return result;
  }

  Vector scale_up(double lambda) const {
    Vector result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] = coordinates_[dimension] * lambda;
    }

    return result;
  }

  Vector scale_down(double lambda) const {
    Vector result;

    for (int dimension = 0; dimension < D; dimension++) {
      result.coordinates_[dimension] = coordinates_[dimension] / lambda;
    }

    return result;
  }

 private:
  T coordinates_[D];
};

#endif  // VECTOR_H_ 
