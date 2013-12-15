// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "art/math.hpp"

TEST(art_floor_test, floor_whole)
{
  EXPECT_EQ(art::floor(0), 0);
  EXPECT_EQ(art::floor(10), 10);
  EXPECT_EQ(art::floor(100), 100);
}

TEST(art_floor_test, floor_decimal)
{
  EXPECT_EQ(art::floor(3.3), 3);
  EXPECT_EQ(art::floor(4.5), 4);
  EXPECT_EQ(art::floor(5.7), 5);
}

TEST(art_floor_test, floor_negative)
{
  EXPECT_EQ(art::floor(-0), 0);
  EXPECT_EQ(art::floor(-1), -1);
  EXPECT_EQ(art::floor(-1.3), -2);
  EXPECT_EQ(art::floor(-2.5), -3);
  EXPECT_EQ(art::floor(-3.7), -4);
}
