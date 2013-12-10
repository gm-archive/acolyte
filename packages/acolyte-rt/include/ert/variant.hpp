// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ERT_VARIANT_HPP_
#define ERT_VARIANT_HPP_

#include "ert/real.hpp"
#include "ert/string.hpp"

namespace ert {
  struct variant {
    variant() = default;
    variant(real_t);
    variant(string_t);
    variant(variant const &) = default;
    variant(variant &&);

    variant& operator=(variant const &) = default;
    variant& operator=(variant &&);
    
    bool operator<(variant const &) const;
    bool operator<=(variant const &) const;
    bool operator>(variant const &) const;
    bool operator>=(variant const &) const;

    operator real_t() const;
    operator string_t() const;
    operator bool() const;
    
    enum type_t {
      vt_uninit = 0,
      vt_real,
      vt_string
    } type = vt_uninit;
    
    real_t real;
    string_t string;
  };
  
  typedef variant variant_t;
}

#endif // ERT_VARIANT_HPP_
