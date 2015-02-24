// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef TRAJECTORY_SIMILARITY_H
#define TRAJECTORY_SIMILARITY_H

#include "vector.h"

#include "math.h"

#include <vector>

#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

class TrajectorySimilarity {
 public:
  template<int D>
  static Vector<double, D> get_direction(
      const Vector<double, D> &first_location,
      const Vector<double, D> &second_location) {
    Vector<double, D> direction = second_location.subtract(first_location);
    return direction.scale_down(direction.norm());
  }

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

  // direction_1 and direction_2 should have unit length.
  template<int D>
  static double point_similarity(const Vector<double, D> &direction_1,
                                 const Vector<double, D> &direction_2,
                                 double distance, double standard_deviation) {
    return direction_1.dot(direction_2)
           * Math::gaussian(distance, 1.0, 0.0, standard_deviation);
  }

  // directional_similarity(a, b) = how well a is fit in the field of b.
  template<int D>
  static void calculate_directional_similarities(
      const std::vector<std::vector<Vector<double, D> > > &trajectories,
      std::vector<std::vector<double> > *directional_similarity) {
    int num_trajectories = static_cast<int>(trajectories.size());

    directional_similarity->resize(num_trajectories);
    for (int trajectory = 0; trajectory < num_trajectories; trajectory++) {
      (*directional_similarity)[trajectory].resize(num_trajectories);
    }

    for (int curr_traj = 0; curr_traj < num_trajectories; curr_traj++) {
    }
  }
};

#endif  // TRAJECTORY_SIMILARITY_H
