// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_REAL_HPP_
#define ART_REAL_HPP_

#include "art/rt.hpp"

#include <array>
#include <numeric>
#include <functional>
#include <algorithm>
#include <random>

namespace art {
  typedef double real_t;
  exposed const real_t gml_pi;
  
  namespace intern {
    extern real_t epsilon;
  }

  exposed real_t gml_math_set_epsilon(real_t);

  // Trigonometric Functions
  exposed real_t gml_arccos(real_t);
  exposed real_t gml_arcsin(real_t);
  exposed real_t gml_arctan(real_t);
  exposed real_t gml_arctan2(real_t, real_t);
  exposed real_t gml_sin(real_t);
  exposed real_t gml_tan(real_t);
  exposed real_t gml_cos(real_t);
  exposed real_t gml_degtorad(real_t);
  exposed real_t gml_radtodeg(real_t);
  exposed real_t gml_lengthdir_x(real_t, real_t);
  exposed real_t gml_lengthdir_y(real_t, real_t);
  
  // Rounding Functions
  exposed real_t gml_round(real_t);
  exposed real_t gml_floor(real_t);
  exposed real_t gml_frac(real_t);
  exposed real_t gml_abs(real_t);
  exposed real_t gml_sign(real_t);
  exposed real_t gml_ceil(real_t);
  exposed real_t gml_lerp(real_t, real_t, real_t);
  exposed real_t gml_clamp(real_t, real_t, real_t);

  // Miscellaneous Functions
  exposed real_t gml_exp(real_t);
  exposed real_t gml_ln(real_t);
  exposed real_t gml_power(real_t, real_t);
  exposed real_t gml_sqr(real_t);
  exposed real_t gml_sqrt(real_t);
  exposed real_t gml_log2(real_t);
  exposed real_t gml_log10(real_t);
  exposed real_t gml_logn(real_t, real_t);
  
  namespace templates {
    template <size_t N>
    real_t median_helper(std::array<real_t, N> & vars) {
      const unsigned n = N / 2;
      std::sort(vars.begin(), vars.end());
      if (N & 1) {
        return vars[n];
      }
      return (vars[n] + vars[n + 1]) * 0.5;
    }
    
    template <size_t N>
    real_t max_helper(std::array<real_t, N> & vars) {
      return std::max_element(vars.begin(), vars.end());
    }
    
    template <size_t N>
    real_t min_helper(std::array<real_t, N> & vars) {
      return std::min_element(vars.begin(), vars.end());
    }
    
    template <size_t N>
    real_t mean_helper(std::array<real_t, N> & vars) {
      return std::accumulate(vars.begin(), vars.end(), 0, std::plus<real_t>()) * (1 / vars.size());
    }
  }
  
  template <typename...T>
  real_t median(T const & ... args) {
    std::array<real_t, sizeof...(args)> vars = {args...};
    return templates::median_helper(vars);
  }
  
  template <typename...T>
  real_t max(T const & ... args) {
    std::array<real_t, sizeof...(args)> vars = {args...};
    return templates::max_helper(vars);
  }
  
  template <typename...T>
  real_t min(T const & ... args) {
    std::array<real_t, sizeof...(args)> vars = {args...};
    return templates::min_helper(vars);
  }
  
  template <typename...T>
  real_t mean(T const & ... args) {
    std::array<real_t, sizeof...(args)> vars = {args...};
    return templates::mean_helper(vars);
  }
}

#endif // ART_REAL_HPP_
