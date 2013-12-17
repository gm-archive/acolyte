// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/string.hpp"

namespace art {
  string_t ansi_char(real_t val) {
    return {{static_cast<string_t::value_type>(val)}};
  }

  string_t chr(real_t val) {
    return {{static_cast<string_t::value_type>(val)}};
  }
}
