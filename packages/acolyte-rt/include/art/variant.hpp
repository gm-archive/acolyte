// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_VARIANT_HPP_
#define ART_VARIANT_HPP_

#include "art/real.hpp"
#include "art/string.hpp"

namespace art {
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

  real_t is_real(const variant_t&);
  real_t is_string(const variant_t&);
}

#endif // ART_VARIANT_HPP_
