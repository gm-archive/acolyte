// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/real.hpp"
#include "art/math.hpp"
#include "art/vector.hpp"

#include <cmath>

namespace art {
  namespace internal {
    real_t point_direction_rad(real_t x1, real_t y1, real_t x2, real_t y2) {
      return std::atan2(y1 - y2, x2 - x1) + 2 * pi * (y2 > y1);
    }
    
    real_t vector_direction_rad(real_t x, real_t y) {
      return std::atan2(-y, x) + 2 * pi * (y > 0);
    }
    
    real_t vector_length(real_t x, real_t y) {
      return std::sqrt(x * x + y * y);
    }
    
    real_t vector_length_3d(real_t x, real_t y, real_t z) {
      return std::sqrt(x * x + y * y + z * z);
    }
  }
  
  real_t point_direction(real_t x1, real_t y1, real_t x2, real_t y2) {
    return radtodeg(internal::point_direction_rad(x1, y1, x2, y2));
  }

  real_t point_distance(real_t x1, real_t y1, real_t x2, real_t y2) {
    return internal::vector_length(x2 - x1, y2 - y1);
  }

  real_t point_distance_3d(real_t x1, real_t y1, real_t z1, real_t x2, real_t y2, real_t z2) {
    return internal::vector_length_3d(x2 - x1, y2 - y1, z2 - z1);
  }

  real_t dot_product(real_t x1, real_t y1, real_t x2, real_t y2) {
    return x1 * x2 + y1 * y2;
  }

  real_t dot_product_3d(real_t x1, real_t y1, real_t z1, real_t x2, real_t y2, real_t z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
  }

  real_t dot_product_normalised(real_t x1, real_t y1, real_t x2, real_t y2) {
    return (x1 * x2 + y1 * y2) / internal::vector_length(x2 - x1, y2 - y1);
  }

  real_t dot_product_normalised_3d(real_t x1, real_t y1, real_t z1, real_t x2, real_t y2, real_t z2) {
    return (x1 * x2 + y1 * y2 + z1 * z2) / internal::vector_length_3d(x2 - x1, y2 - y1, z2 - z1);
  }
}
