// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_STRING_HPP_
#define ART_STRING_HPP_

#include "art/real.hpp"

#include <string>

namespace art {
  typedef std::u32string string_t;

  string_t ansi_char(real_t);
  string_t chr(real_t val);
  real_t ord(string_t str);
}

#endif // ART_STRING_HPP_
