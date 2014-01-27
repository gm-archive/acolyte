// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_RT_HPP_
#define ART_RT_HPP_

#include <cstdint>

#ifndef exposed
#define exposed extern "C"
#endif

typedef double real_t;

struct vbox;
typedef vbox vbox_t;

struct vbox_alloc {
  struct header {
    uint16_t allocated;
    uint16_t count;
  };
  union {
    vbox_t vbox_data[];
    uint8_t char_data[];
  };
};

typedef vbox_alloc vbox_alloc_t;

struct vbox {
  union {
    vbox_alloc *alloc_ptr;
    real_t *real_ptr;
    struct {
      bool is_string : 1;
      bool is_array : 1;
      bool is_locked : 1;
    };
  };

  bool is_string();
  bool is_real();
  bool is_array();
  bool is_locked();

  void lock();
  vbox_t ref(vbox_t other);
  vbox_t copy(vbox_t other);
};

typedef vbox vbox_t;

#endif // ART_RT_HPP_
