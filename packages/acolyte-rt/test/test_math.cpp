// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "art/math.hpp"

#define EPSILON 0.000000000000001

using art::real_t;
using art::pi;

TEST(art_degtorad_tests, degtorad_unit_circle)
{
  const real_t N = 360;
  unsigned eps = 0;
  real_t rad = 2 * -pi;
  for (real_t deg = -360; deg < 360; deg += 360 / N) {
    ASSERT_NEAR(rad, art::degtorad(deg), EPSILON * ++eps);
    rad += 2 * pi / N;
  }
}

TEST(art_radtodeg_tests, radtodeg_unit_circle)
{
  const real_t N = 2 * pi;
  unsigned eps = 0;
  real_t deg = -360;
  for (real_t rad = 2 * -pi; rad < 2 * pi; rad += 2 * pi / N) {
    ASSERT_NEAR(deg, art::radtodeg(rad), EPSILON * ++eps);
    deg += 360 / N;
  }
}

TEST(lengthdir_x_tests, lengthdir_x_direction)
{
  ASSERT_NEAR(0, art::lengthdir_x(1, -270), EPSILON);
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, -225));
  EXPECT_DOUBLE_EQ(-1, art::lengthdir_x(1, -180));
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, -135));
  ASSERT_NEAR(0, art::lengthdir_x(1, -90), EPSILON);
  EXPECT_DOUBLE_EQ(std::sqrt(2) / 2, art::lengthdir_x(1, -45));
  EXPECT_DOUBLE_EQ(1, art::lengthdir_x(1, 0));
  EXPECT_DOUBLE_EQ(std::sqrt(2) / 2, art::lengthdir_x(1, 45));
  ASSERT_NEAR(0, art::lengthdir_x(1, 90), EPSILON);
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, 135));
  EXPECT_DOUBLE_EQ(-1, art::lengthdir_x(1, 180));
  EXPECT_DOUBLE_EQ(-std::sqrt(2) / 2, art::lengthdir_x(1, 225));
  ASSERT_NEAR(0, art::lengthdir_x(1, 270), EPSILON);
}

TEST(art_floor_tests, floor_whole)
{
  EXPECT_DOUBLE_EQ(0, art::floor(0));
  EXPECT_DOUBLE_EQ(10, art::floor(10));
  EXPECT_DOUBLE_EQ(100, art::floor(100));
}

TEST(art_floor_tests, floor_decimal)
{
  EXPECT_DOUBLE_EQ(3, art::floor(3.3));
  EXPECT_DOUBLE_EQ(4, art::floor(4.5));
  EXPECT_DOUBLE_EQ(5, art::floor(5.7));
}

TEST(art_floor_tests, floor_negative)
{
  EXPECT_DOUBLE_EQ(0, art::floor(-0));
  EXPECT_DOUBLE_EQ(-1, art::floor(-1));
  EXPECT_DOUBLE_EQ(-2, art::floor(-1.3));
  EXPECT_DOUBLE_EQ(-3, art::floor(-2.5));
  EXPECT_DOUBLE_EQ(-4, art::floor(-3.7));
}
