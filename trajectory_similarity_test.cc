// Author: Mingcheng Chen (linyufly@gmail.com)

#include "trajectory_similarity.h"

#include <cstdio>

typedef Vector<double, 2> Vector2D;
typedef Vector<double, 3> Vector3D;

void get_direction_test() {
  printf("get_direction_test {\n");

  // Should be parallel to (1.0, 1.0, 1.0)
  Vector3D direction = TrajectorySimilarity::get_direction(
      Vector3D(1.0, 2.0, 3.0),
      Vector3D(2.0, 3.0, 4.0),
      Vector3D(3.0, 4.0, 5.0));

  printf("direction = (%lf, %lf, %lf)\n",
         direction.get_component(0),
         direction.get_component(1),
         direction.get_component(2));

  // Should be parallel to (1.0, 1.0, 0.0)
  direction = TrajectorySimilarity::get_direction(
      Vector3D(1.0, 2.0, 3.0),
      Vector3D(1.5, 2.5, 5.0),
      Vector3D(2.0, 3.0, 3.0));

  printf("direction = (%lf, %lf, %lf)\n",
         direction.get_component(0),
         direction.get_component(1),
         direction.get_component(2));

  // Should be parallel to (1.0, 1.0)
  Vector2D direction_2d = TrajectorySimilarity::get_direction(
    Vector2D(0.0, 0.0),
    Vector2D(0.0, 1.0),
    Vector2D(1.0, 1.0));

  printf("direction_2d = (%lf, %lf)\n",
          direction_2d.get_component(0),
          direction_2d.get_component(1));

  // x should be slightly smaller than y.
  direction_2d = TrajectorySimilarity::get_direction(
    Vector2D(0.0, 0.0),
    Vector2D(0.0, 0.9),
    Vector2D(1.0, 1.0));

  printf("direction_2d = (%lf, %lf)\n",
          direction_2d.get_component(0),
          direction_2d.get_component(1));


  printf("} get_direction_test\n");
  printf("\n");
}

int main() {
  get_direction_test();

  return 0;
}

