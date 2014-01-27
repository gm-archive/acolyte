// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license which can be found in the LICENSE file.

#ifndef _ACOLYTE_GC_H_
#define _ACOLYTE_GC_H_

#include <stdint.h>

typedef struct superblock superblock_t;

struct superblock {
  superblock_t *next;
  void *base;
};

typedef struct block block_t;

struct block {
  //
};

typedef struct alloc alloc_t;

struct alloc {
  union {
    uint32_t meta;
    struct {
      unsigned link : 29;
      unsigned gen : 2;
      unsigned mark : 1;
    };
  };
};

#endif // _ACOLYTE_GC_H_
