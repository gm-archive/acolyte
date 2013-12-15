// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_VECTOR_HPP_
#define ART_VECTOR_HPP_

#include "art/real.hpp"

namespace art {
  namespace internal {
    real_t point_direction_rad(real_t x1, real_t y1, real_t x2, real_t y2);
    real_t vector_direction_rad(real_t x, real_t y);
    real_t vector_length(real_t x, real_t y);
    real_t vector_length_3d(real_t x, real_t y, real_t z);
  }
  
  // Vector Functions
  real_t point_direction(real_t, real_t, real_t, real_t);
  real_t point_distance(real_t, real_t, real_t, real_t);
  real_t point_distance_3d(real_t, real_t, real_t, real_t, real_t, real_t);
  real_t dot_product(real_t, real_t, real_t, real_t);
  real_t dot_product_3d(real_t, real_t, real_t, real_t, real_t, real_t);
  real_t dot_product_normalised(real_t, real_t, real_t, real_t);
  real_t dot_product_normalised_3d(real_t, real_t, real_t, real_t, real_t, real_t);
}

#endif // ART_VECTOR_HPP_
