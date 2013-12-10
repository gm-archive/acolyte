// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ERT_BUFFER_HPP_
#define ERT_BUFFER_HPP_

#include "ert/real.hpp"
#include "ert/string.hpp"
#include "ert/variant.hpp"

namespace ert {
  enum {
    buffer_fixed = 0,
    buffer_grow,
    buffer_wrap,
    buffer_fast
  };
  
  enum {
    buffer_u8 = 0,
    buffer_s8,
    buffer_u16,
    buffer_s16,
    buffer_u32,
    buffer_s32,
    buffer_f16,
    buffer_f32,
    buffer_f64,
    buffer_bool,
    buffer_string
  };
  
  enum {
    buffer_seek_start = 0,
    buffer_seek_relative,
    buffer_seek_end
  }

  // Buffer Functions
  real_t buffer_create(real_t, real_t, real_t);
  real_t buffer_delete(real_t);
  variant_t buffer_read(real_t, real_t);
  real_t buffer_write(real_t, real_t, const variant_t&);
  real_t buffer_fill(real_t, real_t, real_t, const variant_t&, real_t);
  real_t buffer_seek(real_t, real_t, real_t);
  real_t buffer_tell(real_t);
  variant_t buffer_peek(real_t, real_t, real_t);
  real_t buffer_poke(real_t, real_t, real_t, const variant_t&);
  real_t buffer_save(real_t, const string_t&);
  real_t buffer_save_ext(real_t, const string_t&, real_t, real_t);
  real_t buffer_load(const string_t&);
  real_t buffer_load_ext(real_t, const string_t&, real_t);
  real_t buffer_copy(real_t, real_t, real_t, real_t, real_t);
  real_t buffer_get_size(real_t);
  real_t buffer_resize(real_t, real_t);
  real_t buffer_sizeof(real_t);
  string_t buffer_md5(real_t, real_t, real_t);
  string_t buffer_sha1(real_t, real_t, real_t);
  string_t buffer_base64_encode(real_t, real_t, real_t);
  real_t buffer_base64_decode(const string_t&);
}

#endif // ERT_BUFFER_HPP_
