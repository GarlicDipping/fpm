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

struct FixedVec4
{
    fixed_float x;
    fixed_float y;
    fixed_float z;
    fixed_float w;
};

struct FixedVec3
{
    fixed_float x;
    fixed_float y;
    fixed_float z;
};

struct FixedVec2
{
    fixed_float x;
    fixed_float y;
};

struct FixedQuaternion
{
    fixed_float x;
    fixed_float y;
    fixed_float z;
    fixed_float w;
};

extern "C"
{

DLLExport void add(fixed_float* in, fixed_float a_raw, fixed_float b_raw);
DLLExport void multiply(fixed_float* in, fixed_float a_raw, fixed_float b_raw);
DLLExport void subtract(fixed_float* in, fixed_float a_raw, fixed_float b_raw);
DLLExport void divide(fixed_float* in, fixed_float a_raw, fixed_float b_raw);

//Utilities
DLLExport void from_int(fixed_float* in, fixed_float_base_type integer);
DLLExport void from_raw(fixed_float* in, fixed_float_base_type rawVal);
DLLExport void mix(fixed_float* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator);
DLLExport float to_float(fixed_float raw);

//trigonometrics

DLLExport void ff_sin(fixed_float* in, fixed_float val);
DLLExport void ff_cos(fixed_float* in, fixed_float val);
DLLExport void ff_tan(fixed_float* in, fixed_float val);
DLLExport void ff_asin(fixed_float* in, fixed_float val);
DLLExport void ff_acos(fixed_float* in, fixed_float val);
DLLExport void ff_atan(fixed_float* in, fixed_float val);
DLLExport void ff_atan2(fixed_float* in, fixed_float y, fixed_float x);

//Mathmatics

DLLExport void ff_ceil(fixed_float* in, fixed_float val);
DLLExport void ff_floor(fixed_float* in, fixed_float val);
DLLExport void ff_trunc(fixed_float* in, fixed_float val);
DLLExport void ff_round(fixed_float* in, fixed_float val);
DLLExport void ff_abs(fixed_float* in, fixed_float val);
DLLExport void ff_fmod(fixed_float* in, fixed_float x, fixed_float y);
DLLExport void ff_remainder(fixed_float* in, fixed_float x, fixed_float y);
DLLExport void ff_copysign(fixed_float* in, fixed_float x, fixed_float y);
DLLExport void ff_modf(fixed_float* in, fixed_float val, fixed_float* iPtr);

DLLExport void ff_pow(fixed_float* in, fixed_float base, fixed_float pow);
DLLExport void ff_exp(fixed_float* in, fixed_float x);
DLLExport void ff_exp2(fixed_float* in, fixed_float x);
DLLExport void ff_log2(fixed_float* in, fixed_float x);
DLLExport void ff_ln(fixed_float* in, fixed_float x);
DLLExport void ff_log10(fixed_float* in, fixed_float x);

DLLExport void ff_cbrt(fixed_float* in, fixed_float val);
DLLExport void ff_sqrt(fixed_float* in, fixed_float val);


//NEED CACHING ON C# STRUCT INITIALIZATION!
DLLExport fixed_float_base_type fractional_bits();
DLLExport void e(fixed_float* out);
DLLExport void pi(fixed_float* out);
DLLExport void half_pi(fixed_float* out);
DLLExport void two_pi(fixed_float* out);

#pragma region Matrix4x4

DLLExport void matrix4x4_mult(FixedMatrix4x4* res, FixedMatrix4x4 lhs, FixedMatrix4x4 rhs);
DLLExport void matrix4x4_mult_vec4(FixedVec4* res, FixedMatrix4x4 lhs, FixedVec4 vector);
// Transforms a position by this matrix, with a perspective divide. (generic)
DLLExport void matrix4x4_mult_point(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 point);
// Transforms a position by this matrix, without a perspective divide. (fast)
DLLExport void matrix4x4_mult_point3x4(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 point);
// Transforms a direction by this matrix.
DLLExport void matrix4x4_mult_vec3(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 vector);
// Creates a scaling matrix.
DLLExport void matrix4x4_scale(FixedMatrix4x4* res, FixedVec3 vector);
// Creates a translation matrix.
DLLExport void matrix4x4_translate(FixedMatrix4x4* res, FixedVec3 vector);
// Creates a rotation matrix. Note: Assumes unit quaternion
DLLExport void matrix4x4_rotate(FixedMatrix4x4* res, FixedQuaternion q);

#pragma endregion

}

#endif //FPM_FPM_UNITY_H
