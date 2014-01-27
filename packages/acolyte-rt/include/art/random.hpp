// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_RANDOM_HPP_
#define ART_RANDOM_HPP_

#include "art/rt.hpp"
#include "art/variant.hpp"

namespace art {
  namespace intern {
    template <int N>
    struct arch_random_t {
      using gen = std::mt19937;
    };
  
    template <>
    struct arch_random_t<8> {
      using gen = std::mt19937_64;
    };
  
    using gen_t = arch_random_t<sizeof(void*)>::gen;
    
    extern gen_t rand_gen;
    extern real_t rand_seed;
    extern std::random_device rand_rd;
  }

  // Random Functions
  exposed real_t random(real_t);
  exposed real_t random_range(real_t, real_t);
  exposed real_t irandom(real_t);
  exposed real_t irandom_range(real_t, real_t);
  exposed real_t random_set_seed(real_t);
  exposed real_t random_get_seed();
  exposed real_t randomize();

  namespace templates {
    template <size_t N>
    variant_t choose_helper(std::array<variant_t, N> & vars) {
      std::uniform_int_distribution<> dis(0, N - 1);
      return vars[dis(intern::rand_gen)];
    }
  }

  template <typename...T>
  variant_t choose(T const & ...args) {
    std::array<variant_t, sizeof...(args)> vars = {{ args... }};
    return templates::choose_helper(vars);
  }
}

#endif // ART_RANDOM_HPP_
