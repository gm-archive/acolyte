// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "gtest/gtest.h"

#include "ert/math.hpp"

TEST(ert_floor_test, floor_zero)
{
  EXPECT_EQ(ert::floor(0), 0);
}
