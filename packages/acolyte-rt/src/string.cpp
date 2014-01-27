// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/string.hpp"

#include <cstdint>

namespace art {
  string_t ansi_char(real_t val) {
    return {{static_cast<string_t::value_type>(val)}};
  }

  string_t chr(real_t val) {
    return {{static_cast<string_t::value_type>(val)}};
  }

  real_t ord(string_t str) {
    return static_cast<real_t>(str[0]);
  }

  exposed real_t gml_string_byte_at(string_t str, real_t n) {
    return 1;
    //return static_cast<real_t>(str[std::max(0, std::min(str.length()]);
  }

  exposed real_t gml_string_byte_length(string_t);
  exposed string_t gml_string_char_at(string_t, real_t);
  exposed string_t gml_string_copy(string_t, real_t, real_t);
  exposed real_t gml_string_count(string_t, string_t);
}
