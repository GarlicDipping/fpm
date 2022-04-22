//
// Created by MinsooKim on 2022-04-20.
//

#ifndef FPM_FPM_UNITY_H
#define FPM_FPM_UNITY_H

#define DLLExport __declspec(dllexport)

#include "fpm/fixed.hpp"  // For fpm::fixed_16_16
#include "fpm/math.hpp"   // For fpm::cos
#include "fpm/ios.hpp"    // For fpm::operator<<
#include <sstream>

using fixed_float = fpm::fixed_16_16;
using fixed_float_base_type = std::int32_t;

extern "C"
{
DLLExport fixed_float_base_type mix(fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport fixed_float_base_type test_add(fixed_float_base_type a_raw, fixed_float_base_type b_raw);
DLLExport fixed_float_base_type test_mult(fixed_float_base_type a_raw, fixed_float_base_type b_raw);
DLLExport fixed_float_base_type test_minus(fixed_float_base_type a_raw, fixed_float_base_type b_raw);
DLLExport fixed_float_base_type test_div(fixed_float_base_type a_raw, fixed_float_base_type b_raw);
DLLExport float to_float(fixed_float_base_type raw);
}

#endif //FPM_FPM_UNITY_H
