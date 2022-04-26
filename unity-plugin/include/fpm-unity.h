//
// Created by MinsooKim on 2022-04-20.
//

#ifndef FPM_FPM_UNITY_H
#define FPM_FPM_UNITY_H

#define DLLExport __declspec(dllexport)

#include "fpm/fixed.hpp"  // For fpm::fixed_16_16
#include "fpm/math.hpp"   // For fpm::cos
#include "fpm/ios.hpp"    // For fpm::operator<<

using fixed_float_base_type = std::int32_t;
using fixed_float = fpm::fixed<fixed_float_base_type, std::int64_t, 12>; //Q20.12

extern "C"
{
    struct FixedFloat
    {
        fixed_float_base_type rawValue;
    };

DLLExport FixedFloat add(FixedFloat a_raw, FixedFloat b_raw);
DLLExport FixedFloat multiply(FixedFloat a_raw, FixedFloat b_raw);
DLLExport FixedFloat subtract(FixedFloat a_raw, FixedFloat b_raw);
DLLExport FixedFloat divide(FixedFloat a_raw, FixedFloat b_raw);
DLLExport void mix(FixedFloat* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport float to_float(FixedFloat raw);
}

#endif //FPM_FPM_UNITY_H
