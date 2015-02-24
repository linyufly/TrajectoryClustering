// Author: Mingcheng Chen (linyufly@gmail.com)

#ifndef MATH_H_
#define MATH_H_

class Math {
 public:
  static double square(double value);

  // Fit a quadratic function
  // y = coefficient[0] + coefficient[1] * x + coefficient[2] * x^2
  static void fit_quadratic(const double x[3], const double y[3],
                            double coefficients[3]);
};

#endif  // MATH_H_
