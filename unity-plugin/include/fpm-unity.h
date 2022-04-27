//
// Created by MinsooKim on 2022-04-20.
//

#ifndef FPM_FPM_UNITY_H
#define FPM_FPM_UNITY_H

#define DLLExport __declspec(dllexport)

#include "fpm/fixed.hpp"  // For fpm::fixed_16_16
#include "fpm/math.hpp"   // For fpm::cos
#include "fpm/ios.hpp"    // For fpm::operator<<

const int fixed_float_fraction_bits = 16;
using fixed_float_base_type = std::int32_t;
using fixed_float = fpm::fixed<fixed_float_base_type, std::int64_t, fixed_float_fraction_bits>; //Q16.16

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

//Utilities
DLLExport void from_int(FixedFloat* in, fixed_float_base_type integer);
DLLExport void from_raw(FixedFloat* in, fixed_float_base_type rawVal);
DLLExport void mix(FixedFloat* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport float to_float(FixedFloat raw);

//trigonometrics

DLLExport void ff_sin(FixedFloat* in, FixedFloat val);
DLLExport void ff_cos(FixedFloat* in, FixedFloat val);
DLLExport void ff_tan(FixedFloat* in, FixedFloat val);
DLLExport void ff_asin(FixedFloat* in, FixedFloat val);
DLLExport void ff_acos(FixedFloat* in, FixedFloat val);
DLLExport void ff_atan(FixedFloat* in, FixedFloat val);
DLLExport void ff_atan2(FixedFloat* in, FixedFloat y, FixedFloat x);

//Mathmatics

DLLExport void ff_ceil(FixedFloat* in, FixedFloat val);
DLLExport void ff_floor(FixedFloat* in, FixedFloat val);
DLLExport void ff_trunc(FixedFloat* in, FixedFloat val);
DLLExport void ff_round(FixedFloat* in, FixedFloat val);
DLLExport void ff_abs(FixedFloat* in, FixedFloat val);
DLLExport void ff_fmod(FixedFloat* in, FixedFloat x, FixedFloat y);
DLLExport void ff_remainder(FixedFloat* in, FixedFloat x, FixedFloat y);
DLLExport void ff_copysign(FixedFloat* in, FixedFloat x, FixedFloat y);
DLLExport void ff_modf(FixedFloat* in, FixedFloat val, FixedFloat* iPtr);

DLLExport void ff_pow(FixedFloat* in, FixedFloat base, FixedFloat pow);
DLLExport void ff_exp(FixedFloat* in, FixedFloat x);
DLLExport void ff_exp2(FixedFloat* in, FixedFloat x);
DLLExport void ff_log2(FixedFloat* in, FixedFloat x);
DLLExport void ff_ln(FixedFloat* in, FixedFloat x);
DLLExport void ff_log10(FixedFloat* in, FixedFloat x);

DLLExport void ff_cbrt(FixedFloat* in, FixedFloat val);
DLLExport void ff_sqrt(FixedFloat* in, FixedFloat val);


//NEED CACHING ON C# STRUCT INITIALIZATION!
DLLExport fixed_float_base_type fractional_bits();
DLLExport void e(FixedFloat* out);
DLLExport void pi(FixedFloat* out);
DLLExport void half_pi(FixedFloat* out);
DLLExport void two_pi(FixedFloat* out);
}

#endif //FPM_FPM_UNITY_H
