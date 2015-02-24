// Author: Mingcheng Chen (linyufly@gmail.com)

#include "vector.h"

#include <cstdio>

typedef Vector<double, 2> Vector2D;
typedef Vector<double, 3> Vector3D;

void constructor_test() {
  printf("constructor_test {\n");

  Vector2D vec_2d(2.0, 3.0);
  Vector3D vec_3d(4.0, 5.0, 6.0);

  printf("%lf %lf\n", vec_2d.get_component(0), vec_2d.get_component(1));
  printf("%lf %lf %lf\n",
         vec_3d.get_component(0), vec_3d.get_component(1),
         vec_3d.get_component(2));

  double coord[] = {1.0, 2.0, 3.0, 4.0};
  Vector<double, 4> vec_4d(coord);

  printf("%lf %lf %lf %lf\n",
         vec_4d.get_component(0), vec_4d.get_component(1),
         vec_4d.get_component(2), vec_4d.get_component(3));

  printf("} constructor_test\n");
  printf("\n");
}

void norm_test() {
  printf("norm_test {\n");

  Vector2D vec_2d(3.0, 4.0);

  printf("norm = %lf\n", vec_2d.norm());

  printf("} norm_test\n");
  printf("\n");
}

void dot_test() {
  printf("dot_test {\n");

  Vector3D vec_1(1.0, 2.0, 3.0);
  Vector3D vec_2(1.0, -3.0, 2.0);

  printf("dot = %lf\n", vec_1.dot(vec_2));

  printf("} dot_test\n");
  printf("\n");
}

void add_test() {
  printf("add_test {\n");

  Vector2D vec_1(1.0, 2.0);
  Vector2D vec_2(4.0, 5.0);
  Vector2D vec_3 = vec_1.add(vec_2);

  printf("sum = (%lf, %lf)\n", vec_3.get_component(0), vec_3.get_component(1));

  printf("} add_test\n");
  printf("\n");
}

void subtract_test() {
  printf("subtract_test {\n");

  Vector3D vec_1(1.0, 2.0, 3.0);
  Vector3D vec_2(4.0, 5.0, 6.0);
  Vector3D vec_3 = vec_1.subtract(vec_2);

  printf("remaining = (%lf, %lf, %lf)\n",
         vec_3.get_component(0), vec_3.get_component(1),
         vec_3.get_component(2));

  printf("} subtract_test\n");
  printf("\n");
}

void scale_up_test() {
  printf("scale_up_test {\n");

  Vector2D vec_1(1.0, 2.0);
  Vector2D vec_2 = vec_1.scale_up(2.0);

  printf("result = (%lf, %lf)\n",
         vec_2.get_component(0), vec_2.get_component(1));

  printf("} scale_up_test\n");
  printf("\n");
}

void scale_down_test() {
  printf("scale_down_test {\n");

  Vector2D vec_1(2.0, 4.0);
  Vector2D vec_2 = vec_1.scale_down(2.0);

  printf("result = (%lf, %lf)\n",
         vec_2.get_component(0), vec_2.get_component(1));

  printf("} scale_down_test\n");
  printf("\n");
}

int main() {
  constructor_test();
  norm_test();
  dot_test();
  add_test();
  subtract_test();
  scale_up_test();
  scale_down_test();

  return 0;
}

