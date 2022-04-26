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
using fixed_float = fpm::fixed<fixed_float_base_type, std::int64_t, 16>; //Q16.16

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
DLLExport void from_int(FixedFloat* in, fixed_float_base_type integer);
DLLExport void mix(FixedFloat* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport float to_float(FixedFloat raw);

//Mathmatics

DLLExport void ff_pow(FixedFloat* in, FixedFloat base, FixedFloat pow);
DLLExport void ff_sqrt(FixedFloat* in, FixedFloat val);
DLLExport void ff_sin(FixedFloat* in, FixedFloat val);
DLLExport void ff_cos(FixedFloat* in, FixedFloat val);
DLLExport void ff_tan(FixedFloat* in, FixedFloat val);
DLLExport void ff_asin(FixedFloat* in, FixedFloat val);
DLLExport void ff_acos(FixedFloat* in, FixedFloat val);
DLLExport void ff_atan(FixedFloat* in, FixedFloat val);

//NEED CACHING ON C# STRUCT INITIALIZATION!
DLLExport void e(FixedFloat* out);
DLLExport void pi(FixedFloat* out);
DLLExport void half_pi(FixedFloat* out);
DLLExport void two_pi(FixedFloat* out);
}

#endif //FPM_FPM_UNITY_H
