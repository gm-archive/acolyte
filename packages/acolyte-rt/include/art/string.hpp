// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_STRING_HPP_
#define ART_STRING_HPP_

#include "art/rt.hpp"
#include "art/real.hpp"
#include "utf8.h"

#include <string>

namespace art {
  typedef std::string string_t;

  string_t ansi_char(real_t);
  string_t chr(real_t val);
  real_t ord(string_t str);

  exposed real_t gml_string_byte_at(string_t, real_t);
  exposed real_t gml_string_byte_length(string_t);
  exposed string_t gml_string_char_at(string_t, real_t);
  exposed string_t gml_string_copy(string_t, real_t, real_t);
  exposed real_t gml_string_count(string_t, string_t);
}

#endif // ART_STRING_HPP_
