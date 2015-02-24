// Author: Mingcheng Chen (linyufly@gmail.com)

#include "math.h"

#include <cstdio>

void fit_quadratic_test() {
  printf("fit_quadratic_test {\n");

  double x[] = {1.0, 10.0, 17.0};
  double y[] = {30.12, 42.55, 71.64};

  double coefficients[3];

  Math::fit_quadratic(x, y, coefficients);

  printf("y = %lf + %lf x + %lf x^2\n",
         coefficients[0], coefficients[1], coefficients[2]);

  for (int case_id = 0; case_id < 3; case_id++) {
    double curr_y = coefficients[0] + coefficients[1] * x[case_id]
                    + coefficients[2] * Math::square(x[case_id]);
    printf("x, y, curr_y = %lf, %lf, %lf\n", x[case_id], y[case_id], curr_y);
  }

  printf("} fit_quadratic_test\n");
  printf("\n");
}

void gaussian_test() {
  printf("gaussian_test {\n");

  double a = 1.0, b = 0.0, c = 1.0;
  printf("g(0.0) = %lf\n", Math::gaussian(0.0, a, b, c));
  printf("g(-1.0) = %lf\n", Math::gaussian(-1.0, a, b, c));
  printf("g(1.0) = %lf\n", Math::gaussian(1.0, a, b, c));
  printf("g(2.0) = %lf\n", Math::gaussian(2.0, a, b, c));
  printf("g(3.0) = %lf\n", Math::gaussian(3.0, a, b, c));
  printf("g(3.5) = %lf\n", Math::gaussian(3.5, a, b, c));
  printf("g(4.0) = %lf\n", Math::gaussian(4.0, a, b, c));
  printf("g(5.0) = %lf\n", Math::gaussian(5.0, a, b, c));
  printf("g(6.0) = %.20lf\n", Math::gaussian(6.0, a, b, c));
  printf("g(7.0) = %.20lf\n", Math::gaussian(7.0, a, b, c));
  printf("g(0.5) = %lf\n", Math::gaussian(0.5, a, b, c));

  printf("} gaussian_test\n");
  printf("\n");
}

int main() {
  fit_quadratic_test();
  gaussian_test();

  return 0;
}
