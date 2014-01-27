// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/rt.hpp"

#include <cstdlib>

bool vbox::is_string() {
  return this->is_string;
}

bool vbox::is_real() {
  return !this->is_string;
}

bool vbox::is_array() {
  return this->is_array;
}

bool vbox::is_locked() {
  return this->is_locked;
}

void vbox::lock() {
  this->is_locked = true;
}

vbox_t vbox::ref(vbox_t other) {
  vbox_t b = other;
  b.lock();
  return b;
}

vbox_t vbox::copy(vbox_t other) {
  vbox_alloc_t *ptr = pagea
}
