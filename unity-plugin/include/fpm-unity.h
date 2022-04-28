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

struct FixedPoint
{
    fixed_float_base_type rawValue;
};

struct FixedMatrix4x4
{
    // memory layout:
    //
    //                row no (=vertical)
    //               |  0   1   2   3
    //            ---+----------------
    //            0  | m00 m10 m20 m30
    // column no  1  | m01 m11 m21 m31
    // (=horiz)   2  | m02 m12 m22 m32
    //            3  | m03 m13 m23 m33

    FixedPoint m00;
    FixedPoint m10;
    FixedPoint m20;
    FixedPoint m30;

    FixedPoint m01;
    FixedPoint m11;
    FixedPoint m21;
    FixedPoint m31;

    FixedPoint m02;
    FixedPoint m12;
    FixedPoint m22;
    FixedPoint m32;

    FixedPoint m03;
    FixedPoint m13;
    FixedPoint m23;
    FixedPoint m33;
};

struct FixedMatrix4x4Native
{
    public: FixedMatrix4x4Native(FixedMatrix4x4 from)
    {
        m00 = fixed_float::from_raw_value(from.m00.rawValue);
        m10 = fixed_float::from_raw_value(from.m10.rawValue);
        m20 = fixed_float::from_raw_value(from.m20.rawValue);
        m30 = fixed_float::from_raw_value(from.m30.rawValue);

        m01 = fixed_float::from_raw_value(from.m01.rawValue);
        m11 = fixed_float::from_raw_value(from.m11.rawValue);
        m21 = fixed_float::from_raw_value(from.m21.rawValue);
        m31 = fixed_float::from_raw_value(from.m31.rawValue);

        m02 = fixed_float::from_raw_value(from.m02.rawValue);
        m12 = fixed_float::from_raw_value(from.m12.rawValue);
        m22 = fixed_float::from_raw_value(from.m22.rawValue);
        m32 = fixed_float::from_raw_value(from.m32.rawValue);

        m03 = fixed_float::from_raw_value(from.m03.rawValue);
        m13 = fixed_float::from_raw_value(from.m13.rawValue);
        m23 = fixed_float::from_raw_value(from.m23.rawValue);
        m33 = fixed_float::from_raw_value(from.m33.rawValue);
    }

    fixed_float m00;
    fixed_float m10;
    fixed_float m20;
    fixed_float m30;

    fixed_float m01;
    fixed_float m11;
    fixed_float m21;
    fixed_float m31;

    fixed_float m02;
    fixed_float m12;
    fixed_float m22;
    fixed_float m32;

    fixed_float m03;
    fixed_float m13;
    fixed_float m23;
    fixed_float m33;
};


extern "C"
{

DLLExport FixedPoint add(FixedPoint a_raw, FixedPoint b_raw);
DLLExport FixedPoint multiply(FixedPoint a_raw, FixedPoint b_raw);
DLLExport FixedPoint subtract(FixedPoint a_raw, FixedPoint b_raw);
DLLExport FixedPoint divide(FixedPoint a_raw, FixedPoint b_raw);

//Utilities
DLLExport void from_int(FixedPoint* in, fixed_float_base_type integer);
DLLExport void from_raw(FixedPoint* in, fixed_float_base_type rawVal);
DLLExport void mix(FixedPoint* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport float to_float(FixedPoint raw);

//trigonometrics

DLLExport void ff_sin(FixedPoint* in, FixedPoint val);
DLLExport void ff_cos(FixedPoint* in, FixedPoint val);
DLLExport void ff_tan(FixedPoint* in, FixedPoint val);
DLLExport void ff_asin(FixedPoint* in, FixedPoint val);
DLLExport void ff_acos(FixedPoint* in, FixedPoint val);
DLLExport void ff_atan(FixedPoint* in, FixedPoint val);
DLLExport void ff_atan2(FixedPoint* in, FixedPoint y, FixedPoint x);

//Mathmatics

DLLExport void ff_ceil(FixedPoint* in, FixedPoint val);
DLLExport void ff_floor(FixedPoint* in, FixedPoint val);
DLLExport void ff_trunc(FixedPoint* in, FixedPoint val);
DLLExport void ff_round(FixedPoint* in, FixedPoint val);
DLLExport void ff_abs(FixedPoint* in, FixedPoint val);
DLLExport void ff_fmod(FixedPoint* in, FixedPoint x, FixedPoint y);
DLLExport void ff_remainder(FixedPoint* in, FixedPoint x, FixedPoint y);
DLLExport void ff_copysign(FixedPoint* in, FixedPoint x, FixedPoint y);
DLLExport void ff_modf(FixedPoint* in, FixedPoint val, FixedPoint* iPtr);

DLLExport void ff_pow(FixedPoint* in, FixedPoint base, FixedPoint pow);
DLLExport void ff_exp(FixedPoint* in, FixedPoint x);
DLLExport void ff_exp2(FixedPoint* in, FixedPoint x);
DLLExport void ff_log2(FixedPoint* in, FixedPoint x);
DLLExport void ff_ln(FixedPoint* in, FixedPoint x);
DLLExport void ff_log10(FixedPoint* in, FixedPoint x);

DLLExport void ff_cbrt(FixedPoint* in, FixedPoint val);
DLLExport void ff_sqrt(FixedPoint* in, FixedPoint val);


//NEED CACHING ON C# STRUCT INITIALIZATION!
DLLExport fixed_float_base_type fractional_bits();
DLLExport void e(FixedPoint* out);
DLLExport void pi(FixedPoint* out);
DLLExport void half_pi(FixedPoint* out);
DLLExport void two_pi(FixedPoint* out);

#pragma region Matrix4x4

DLLExport void matrix4x4_mult(FixedMatrix4x4* res, FixedMatrix4x4 lhs, FixedMatrix4x4 rhs);

#pragma endregion

DLLExport void test_native(fixed_float* in, fixed_float f);

}

#endif //FPM_FPM_UNITY_H
