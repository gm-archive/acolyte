// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/real.hpp"
#include "art/string.hpp"
#include "art/variant.hpp"

#include <iostream>
#include <algorithm>
#include <functional>

namespace art {
  namespace {
    void assert_init(const variant_t& var) {
      if (var.type == variant::vt_uninit) {
        std::cerr << "error: attempted to access uninitialized variable" << std::endl;
        std::abort();
      }
    }
    
    void assert_real(const variant_t& var) {
      if (var.type != variant::vt_real) {
        std::cerr << "error: variable is not of type real" << std::endl;
        std::abort();
      }
    }
    
    void assert_string(const variant_t& var) {
      if (var.type != variant::vt_string) {
        std::cerr << "error: variable is not of type string" << std::endl;
        std::abort();
      }
    }
  }
  
  variant::variant(real_t val)
    : type(vt_real), real(val) {
  }
  
  variant::variant(string_t val)
    : type(vt_string), string(std::move(val)) {
  }

  variant::variant(variant && rhs)
    : type(rhs.type), real(rhs.real), string(std::move(rhs.string)) {
  }
  
  variant::operator real_t() const {
    assert_init(*this);
    assert_real(*this);
    return this->real;
  }
  
  variant::operator string_t() const {
    assert_init(*this);
    assert_string(*this);
    return this->string;
  }

  variant& variant::operator=(variant && rhs) {
    assert_init(rhs);
    this->type = rhs.type;
    this->real = rhs.real;
    this->string = std::move(rhs.string);
    return *this;
  }
  
  bool variant::operator <(const variant& rhs) const {
    assert_init(*this);
    if (this->type == variant::vt_real) {
      return this->real < static_cast<real_t>(rhs);
    }
    return std::lexicographical_compare(this->string.begin(), this->string.end(),
      rhs.string.begin(), rhs.string.end(), std::less<char>());
  }
  
  bool variant::operator <=(const variant& rhs) const {
    assert_init(*this);
    if (this->type == variant::vt_real) {
      return this->real <= static_cast<real_t>(rhs);
    }
    return std::lexicographical_compare(this->string.begin(), this->string.end(),
      rhs.string.begin(), rhs.string.end(), std::less_equal<char>());
  }
  
  bool variant::operator >(const variant& rhs) const {
    assert_init(*this);
    if (this->type == variant::vt_real) {
      return this->real > static_cast<real_t>(rhs);
    }
    return std::lexicographical_compare(rhs.string.begin(), rhs.string.end(),
      this->string.begin(), this->string.end(), std::greater<char>());
  }
  
  bool variant::operator >=(const variant& rhs) const {
    assert_init(*this);
    if (this->type == variant::vt_real) {
      return this->real >= static_cast<real_t>(rhs);
    }
    return std::lexicographical_compare(rhs.string.begin(), rhs.string.end(),
      this->string.begin(), this->string.end(), std::greater_equal<char>());
  }
}
