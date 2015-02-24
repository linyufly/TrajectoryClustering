// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef TRAJECTORY_SIMILARITY_H
#define TRAJECTORY_SIMILARITY_H

#include "vector.h"

#include "math.h"

#include <vector>

class TrajectorySimilarity {
 public:
  template<int D>
  static Vector<double, D> get_direction(
      const Vector<double, D> &last_location,
      const Vector<double, D> &curr_location,
      const Vector<double, D> &next_location) {
    double half_length_1 = curr_location.subtract(last_location).norm();
    double half_length_2 = curr_location.subtract(next_location).norm();

    double x[] = {0.0, half_length_1, half_length_1 + half_length_2};

    Vector<double, D> direction;

    for (int component = 0; component < D; component++) {
      double y[] = {last_location.get_component(component),
                 curr_location.get_component(component),
                 next_location.get_component(component)};

      double c[3];
      Math::fit_quadratic(x, y, c);

      direction.set_component(component, c[1] + 2 * half_length_1 * c[2]);
    }

    return direction.scale_down(direction.norm());
  }
};

#endif  // TRAJECTORY_SIMILARITY_H
