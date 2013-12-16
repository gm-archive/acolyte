// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/real.hpp"

namespace art {
  const real_t pi = 3.14159265358979323846;
  
  namespace internal {
    real_t epsilon = 1e-16;
  }

  real_t math_set_epsilon(real_t eps) {
    internal::epsilon = eps;
    return 0;
  }
  
  real_t arccos(real_t x) {
    return std::acos(x);
  }

  real_t arcsin(real_t x) {
    return std::asin(x);
  }

  real_t arctan(real_t x) {
    return std::atan(x);
  }

  real_t arctan2(real_t x, real_t y) {
    return std::atan2(x, y);
  }

  real_t sin(real_t x) {
    return std::sin(x);
  }

  real_t tan(real_t x) {
    return std::tan(x);
  }

  real_t cos(real_t x) {
    return std::cos(x);
  }

  real_t degtorad(real_t d) {
    return pi / 180 * d;
  }

  real_t radtodeg(real_t r) {
    return 180 / pi * r;
  }

  real_t lengthdir_x(real_t len, real_t dir) {
    return len * std::cos(degtorad(dir));
  }

  real_t lengthdir_y(real_t len, real_t dir) {
    return len * std::sin(degtorad(dir));
  }

  real_t round(real_t x) {
    return std::round(x);
  }

  real_t floor(real_t x) {
    return std::floor(x);
  }

  real_t frac(real_t x) {
    double i;
    return std::modf(x, &i);
  }

  real_t abs(real_t x) {
    return std::fabs(x);
  }

  real_t sign(real_t x) {
    return (x > 0) - (x < 0);
  }

  real_t ceil(real_t x) {
    return std::ceil(x);
  }
  
  real_t lerp(real_t lb, real_t ub, real_t amt) {
    return lb + (ub - lb) * amt;
  }
  
  real_t clamp(real_t val, real_t min, real_t max) {
    return val < min ? min : val > max ? max : val;
  }

  real_t exp(real_t x) {
    return std::exp(x);
  }

  real_t ln(real_t x) {
    return std::log(x);
  }

  real_t power(real_t b, real_t e) {
    return std::pow(b, e);
  }

  real_t sqr(real_t x) {
    return x * x;
  }

  real_t sqrt(real_t x) {
    return std::sqrt(x);
  }

  real_t log2(real_t x) {
    return std::log2(x);
  }

  real_t log10(real_t x) {
    return std::log10(x);
  }

  real_t logn(real_t base, real_t val) {
    return std::log(val) / std::log(base);
  }
}
