// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ERT_EVENT_HPP_
#define ERT_EVENT_HPP_

#include "ert/object.hpp"

namespace ert {
  enum event_t {
    // TODO: events from GM:S documentation
    ev_placeholder
  };

  struct event {
    typedef object::id_t metadata_t;
    void (object::*fn)(const metadata_t&);
    metadata_t metadata;
  };
}

#endif // ERT_EVENT_HPP_
