// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "art/math.hpp"

TEST(ert_floor_test, floor_whole)
{
  EXPECT_EQ(ert::floor(0), 0);
  EXPECT_EQ(ert::floor(10), 10);
  EXPECT_EQ(ert::floor(100), 100);
}

TEST(ert_floor_test, floor_decimal)
{
  EXPECT_EQ(ert::floor(3.3), 3);
  EXPECT_EQ(ert::floor(4.5), 4);
  EXPECT_EQ(ert::floor(5.7), 5);
}

TEST(ert_floor_test, floor_negative)
{
  EXPECT_EQ(ert::floor(-0), 0);
  EXPECT_EQ(ert::floor(-1), -1);
  EXPECT_EQ(ert::floor(-1.3), -2);
  EXPECT_EQ(ert::floor(-2.5), -3);
  EXPECT_EQ(ert::floor(-3.7), -4);
}
