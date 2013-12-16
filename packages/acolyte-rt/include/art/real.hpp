// Copyright (c) 2013 Acolyte Strike Force. All rights reserved.
// Use of this source code is governed by a BSD3-style license that can be found in the LICENSE file.

#ifndef ART_REAL_HPP_
#define ART_REAL_HPP_

#include <array>
#include <numeric>
#include <functional>
#include <algorithm>
#include <random>

namespace art {
  typedef double real_t;
  extern const real_t pi;
  
  namespace internal {
    extern real_t epsilon;
  }

  real_t math_set_epsilon(real_t);

  // Trigonometric Functions
  real_t arccos(real_t);
  real_t arcsin(real_t);
  real_t arctan(real_t);
  real_t arctan2(real_t, real_t);
  real_t sin(real_t);
  real_t tan(real_t);
  real_t cos(real_t);
  real_t degtorad(real_t);
  real_t radtodeg(real_t);
  real_t lengthdir_x(real_t, real_t);
  real_t lengthdir_y(real_t, real_t);
  
  // Rounding Functions
  real_t round(real_t);
  real_t floor(real_t);
  real_t frac(real_t);
  real_t abs(real_t);
  real_t sign(real_t);
  real_t ceil(real_t);
  real_t lerp(real_t, real_t, real_t);
  real_t clamp(real_t, real_t, real_t);

  // Miscellaneous Functions
  real_t exp(real_t);
  real_t ln(real_t);
  real_t power(real_t, real_t);
  real_t sqr(real_t);
  real_t sqrt(real_t);
  real_t log2(real_t);
  real_t log10(real_t);
  real_t logn(real_t, real_t);
  
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
