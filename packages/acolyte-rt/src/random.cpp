// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#include "art/random.hpp"

namespace art {
  namespace internal {
    gen_t rand_gen;
    real_t rand_seed = std::hash<unsigned>()(internal::rand_gen.default_seed);
    std::random_device rand_rd;
  }

  real_t random(real_t ub) {
    std::uniform_real_distribution<real_t> dis(0, ub);
    return dis(internal::rand_gen);
  }

  real_t random_range(real_t lb, real_t ub) {
    std::uniform_real_distribution<real_t> dis(lb, ub);
    return dis(internal::rand_gen);
  }

  real_t irandom(real_t ub) {
    std::uniform_real_distribution<real_t> dis(0, ub);
    return std::floor(dis(internal::rand_gen));
  }

  real_t irandom_range(real_t lb, real_t ub) {
    std::uniform_real_distribution<real_t> dis(lb, ub);
    return std::floor(dis(internal::rand_gen));
  }

  real_t random_set_seed(real_t seed) {
    internal::rand_seed = seed;
    internal::rand_gen.seed(std::hash<real_t>()(seed));
    return 0;
  }

  real_t random_get_seed() {
    return internal::rand_seed;
  }

  real_t randomize() {
    random_set_seed(internal::rand_rd());
    return 0;
  }
}
