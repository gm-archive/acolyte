// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_PROPERTY_HPP_
#define ART_PROPERTY_HPP_

#include <functional>

namespace art {
  template <typename C, typename T, T (C::*getter)()>
  struct property_ro {
    property_ro(C *ptr)
      : owner(ptr) {
    }
    property_ro(property_ro&& other)
      : owner(other.owner) {
    }
    property_ro(const property_ro&) = delete;
    property_ro& operator=(const property_ro&) = delete;
    property_ro& operator=(property_ro&&) = delete;
    
    operator T() {
      return (this->owner->*getter)();
    }
    
  private:
    C* const owner;
  };
  
  template <typename C, typename T, T (C::*getter)(), void (C::*setter)(T)>
  struct property {
    property(C *ptr)
      : owner(ptr) {
    }
    property(property&& other)
      : owner(other.owner) {
    }
    property(const property&) = delete;
    property& operator=(const property&) = delete;
    property& operator=(property&&) = delete;
    
    const T& operator=(const T& val) {
      (this->owner->*setter)(val);
      return val;
    }
    
    T&& operator=(T&& val) {
      (this->owner->*setter)(std::move(val));
      return (this->owner->*getter)();
    }
    
    operator T() {
      return (this->owner->*getter)();
    }
    
  private:
    C* const owner;
  };
}

#endif // ART_PROPERTY_HPP_
