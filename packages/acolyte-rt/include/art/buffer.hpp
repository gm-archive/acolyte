// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_BUFFER_HPP_
#define ART_BUFFER_HPP_

#include "art/rt.hpp"
#include "art/variant.hpp"

namespace art {
  exposed unsigned buffer_fixed   = 0;
  exposed unsigned buffer_grow    = 1;
  exposed unsigned buffer_wrap    = 2;
  exposed unsigned buffer_fast    = 3;
  
  exposed unsigned buffer_u8      = 1;
  exposed unsigned buffer_s8      = 2;
  exposed unsigned buffer_u16     = 3;
  exposed unsigned buffer_s16     = 4;
  exposed unsigned buffer_u32     = 5;
  exposed unsigned buffer_s32     = 6;
  exposed unsigned buffer_f16     = 7;
  exposed unsigned buffer_f32     = 8;
  exposed unsigned buffer_f64     = 9;
  exposed unsigned buffer_bool    = 10;
  exposed unsigned buffer_string  = 11;

  exposed unsigned buffer_seek_start    = 0;
  exposed unsigned buffer_seek_relative = 1;
  exposed unsigned buffer_seek_end      = 2;

  exposed real_t buffer_create(real_t, real_t, real_t);
  exposed real_t buffer_delete(real_t);
  exposed variant_t buffer_read(real_t, real_t);
  exposed real_t buffer_write(real_t, real_t, const variant_t&);
  exposed real_t buffer_fill(real_t, real_t, real_t, const variant_t&, real_t);
  exposed real_t buffer_seek(real_t, real_t, real_t);
  exposed real_t buffer_tell(real_t);
  exposed variant_t buffer_peek(real_t, real_t, real_t);
  exposed real_t buffer_poke(real_t, real_t, real_t, const variant_t&);
  exposed real_t buffer_save(real_t, const string_t&);
  exposed real_t buffer_save_ext(real_t, const string_t&, real_t, real_t);
  exposed real_t buffer_load(const string_t&);
  exposed real_t buffer_load_ext(real_t, const string_t&, real_t);
  exposed real_t buffer_copy(real_t, real_t, real_t, real_t, real_t);
  exposed real_t buffer_get_size(real_t);
  exposed real_t buffer_resize(real_t, real_t);
  exposed real_t buffer_sizeof(real_t);
  exposed string_t buffer_md5(real_t, real_t, real_t);
  exposed string_t buffer_sha1(real_t, real_t, real_t);
  exposed string_t buffer_base64_encode(real_t, real_t, real_t);
  exposed real_t buffer_base64_decode(const string_t&);
}

#endif // ART_BUFFER_HPP_
