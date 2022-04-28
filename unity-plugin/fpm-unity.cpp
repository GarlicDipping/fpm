//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

#pragma region Arithmatics

void add(fixed_float* in, fixed_float a_raw, fixed_float b_raw)
{
    in->set_raw_value((a_raw + b_raw).raw_value());
}
void multiply(fixed_float* in, fixed_float a_raw, fixed_float b_raw)
{
    in->set_raw_value((a_raw * b_raw).raw_value());
}
void subtract(fixed_float* in, fixed_float a_raw, fixed_float b_raw)
{
    in->set_raw_value((a_raw - b_raw).raw_value());
}
void divide(fixed_float* in, fixed_float a_raw, fixed_float b_raw)
{
    in->set_raw_value((a_raw / b_raw).raw_value());
}

#pragma endregion

#pragma region Utilities

fixed_float_base_type fractional_bits()
{
    return fixed_float_fraction_bits;
}

void from_raw(fixed_float* in, fixed_float_base_type rawVal)
{
    in->set_raw_value(rawVal);
}

void from_int(fixed_float* in, fixed_float_base_type integer)
{
    fixed_float res {integer};
    in->set_raw_value(res.raw_value());
}

void mix(fixed_float* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator)
{
    fixed_float res = fixed_float::mix(integer, numerator, denominator);
    in->set_raw_value(res.raw_value());
}

float to_float(fixed_float raw)
{
    return (float)raw;
}

#pragma endregion

#pragma region Mathmatics


void ff_ceil(fixed_float* in, fixed_float val)
{
    auto res = fpm::ceil(val);
    in->set_raw_value(res.raw_value());
}
void ff_floor(fixed_float* in, fixed_float val)
{
    auto res = fpm::floor(val);
    in->set_raw_value(res.raw_value());
}
void ff_trunc(fixed_float* in, fixed_float val)
{
    auto res = fpm::trunc(val);
    in->set_raw_value(res.raw_value());
}
void ff_round(fixed_float* in, fixed_float val)
{
    auto res = fpm::round(val);
    in->set_raw_value(res.raw_value());
}
void ff_abs(fixed_float* in, fixed_float val)
{
    auto res = fpm::abs(val);
    in->set_raw_value(res.raw_value());
}
void ff_fmod(fixed_float* in, fixed_float x, fixed_float y)
{
    auto res = fpm::fmod(x, y);
    in->set_raw_value(res.raw_value());
}
void ff_remainder(fixed_float* in, fixed_float x, fixed_float y)
{
    auto res = fpm::remainder(x, y);
    in->set_raw_value(res.raw_value());
}
void ff_copysign(fixed_float* in, fixed_float x, fixed_float y)
{
    auto res = fpm::copysign(x, y);
    in->set_raw_value(res.raw_value());
}
void ff_modf(fixed_float* in, fixed_float val, fixed_float* iPtr)
{
    auto res = fpm::modf(val, iPtr);
    in->set_raw_value(res.raw_value());
}

void ff_pow(fixed_float* in, fixed_float base, fixed_float pow)
{
    auto res = fpm::pow(base, pow);
    in->set_raw_value(res.raw_value());
}

void ff_exp(fixed_float* in, fixed_float x)
{
    auto res = fpm::exp(x);
    in->set_raw_value(res.raw_value());
}
void ff_exp2(fixed_float* in, fixed_float x)
{
    auto res = fpm::exp2(x);
    in->set_raw_value(res.raw_value());
}
void ff_log2(fixed_float* in, fixed_float x)
{
    auto res = fpm::log2(x);
    in->set_raw_value(res.raw_value());
}
void ff_ln(fixed_float* in, fixed_float x)
{
    auto res = fpm::log(x);
    in->set_raw_value(res.raw_value());
}
void ff_log10(fixed_float* in, fixed_float x)
{
    auto res = fpm::log10(x);
    in->set_raw_value(res.raw_value());
}

void ff_cbrt(fixed_float* in, fixed_float val)
{
    auto res = fpm::cbrt(val);
    in->set_raw_value(res.raw_value());
}
void ff_sqrt(fixed_float* in, fixed_float val)
{
    auto res = fpm::sqrt(val);
    in->set_raw_value(res.raw_value());
}
#pragma endregion

#pragma region Trigonometrics

void ff_sin(fixed_float* in, fixed_float val)
{
    auto res = fpm::sin(val);
    in->set_raw_value(res.raw_value());
}

void ff_cos(fixed_float* in, fixed_float val)
{
    auto res = fpm::cos(val);
    in->set_raw_value(res.raw_value());
}

void ff_tan(fixed_float* in, fixed_float val)
{
    auto res = fpm::tan(val);
    in->set_raw_value(res.raw_value());
}

void ff_asin(fixed_float* in, fixed_float val)
{
    auto res = fpm::asin(val);
    in->set_raw_value(res.raw_value());
}

void ff_acos(fixed_float* in, fixed_float val)
{
    auto res = fpm::acos(val);
    in->set_raw_value(res.raw_value());
}

void ff_atan(fixed_float* in, fixed_float val)
{
    auto res = fpm::atan(val);
    in->set_raw_value(res.raw_value());
}

void ff_atan2(fixed_float* in, fixed_float y, fixed_float x)
{
    auto res = fpm::atan2(y, x);
    in->set_raw_value(res.raw_value());
}

#pragma endregion

#pragma region Predefined variables

void e(fixed_float* out)
{
    auto e = fixed_float::e();
    out->set_raw_value(e.raw_value());
}
void pi(fixed_float* out)
{
    auto pi = fixed_float::pi();
    out->set_raw_value(pi.raw_value());
}
void half_pi(fixed_float* out)
{
    auto half_pi = fixed_float::half_pi();
    out->set_raw_value(half_pi.raw_value());
}
void two_pi(fixed_float* out)
{
    auto two_pi = fixed_float::two_pi();
    out->set_raw_value(two_pi.raw_value());
}

#pragma endregion

#pragma region FixedMatrix4x4

void matrix4x4_mult(FixedMatrix4x4* res, FixedMatrix4x4 lhs, FixedMatrix4x4 rhs)
{
    res->m00 = (lhs.m00 * rhs.m00 + lhs.m01 * rhs.m10 + lhs.m02 * rhs.m20 + lhs.m03 * rhs.m30);
    res->m01 = (lhs.m00 * rhs.m01 + lhs.m01 * rhs.m11 + lhs.m02 * rhs.m21 + lhs.m03 * rhs.m31);
    res->m02 = (lhs.m00 * rhs.m02 + lhs.m01 * rhs.m12 + lhs.m02 * rhs.m22 + lhs.m03 * rhs.m32);
    res->m03 = (lhs.m00 * rhs.m03 + lhs.m01 * rhs.m13 + lhs.m02 * rhs.m23 + lhs.m03 * rhs.m33);

    res->m10 = (lhs.m10 * rhs.m00 + lhs.m11 * rhs.m10 + lhs.m12 * rhs.m20 + lhs.m13 * rhs.m30);
    res->m11 = (lhs.m10 * rhs.m01 + lhs.m11 * rhs.m11 + lhs.m12 * rhs.m21 + lhs.m13 * rhs.m31);
    res->m12 = (lhs.m10 * rhs.m02 + lhs.m11 * rhs.m12 + lhs.m12 * rhs.m22 + lhs.m13 * rhs.m32);
    res->m13 = (lhs.m10 * rhs.m03 + lhs.m11 * rhs.m13 + lhs.m12 * rhs.m23 + lhs.m13 * rhs.m33);

    res->m20 = (lhs.m20 * rhs.m00 + lhs.m21 * rhs.m10 + lhs.m22 * rhs.m20 + lhs.m23 * rhs.m30);
    res->m21 = (lhs.m20 * rhs.m01 + lhs.m21 * rhs.m11 + lhs.m22 * rhs.m21 + lhs.m23 * rhs.m31);
    res->m22 = (lhs.m20 * rhs.m02 + lhs.m21 * rhs.m12 + lhs.m22 * rhs.m22 + lhs.m23 * rhs.m32);
    res->m23 = (lhs.m20 * rhs.m03 + lhs.m21 * rhs.m13 + lhs.m22 * rhs.m23 + lhs.m23 * rhs.m33);

    res->m30 = (lhs.m30 * rhs.m00 + lhs.m31 * rhs.m10 + lhs.m32 * rhs.m20 + lhs.m33 * rhs.m30);
    res->m31 = (lhs.m30 * rhs.m01 + lhs.m31 * rhs.m11 + lhs.m32 * rhs.m21 + lhs.m33 * rhs.m31);
    res->m32 = (lhs.m30 * rhs.m02 + lhs.m31 * rhs.m12 + lhs.m32 * rhs.m22 + lhs.m33 * rhs.m32);
    res->m33 = (lhs.m30 * rhs.m03 + lhs.m31 * rhs.m13 + lhs.m32 * rhs.m23 + lhs.m33 * rhs.m33);
}

void matrix4x4_mult_vec4(FixedVec4* res, FixedMatrix4x4 lhs, FixedVec4 vector)
{
    res->x = lhs.m00 * vector.x + lhs.m01 * vector.y + lhs.m02 * vector.z + lhs.m03 * vector.w;
    res->y = lhs.m10 * vector.x + lhs.m11 * vector.y + lhs.m12 * vector.z + lhs.m13 * vector.w;
    res->z = lhs.m20 * vector.x + lhs.m21 * vector.y + lhs.m22 * vector.z + lhs.m23 * vector.w;
    res->w = lhs.m30 * vector.x + lhs.m31 * vector.y + lhs.m32 * vector.z + lhs.m33 * vector.w;
}

// Transforms a position by this matrix, with a perspective divide. (generic)
void matrix4x4_mult_point(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 point)
{
    fixed_float w;
    auto x = lhs.m00 * point.x + lhs.m01 * point.y + lhs.m02 * point.z + lhs.m03;
    auto y = lhs.m10 * point.x + lhs.m11 * point.y + lhs.m12 * point.z + lhs.m13;
    auto z = lhs.m20 * point.x + lhs.m21 * point.y + lhs.m22 * point.z + lhs.m23;
    w = lhs.m30 * point.x + lhs.m31 * point.y + lhs.m32 * point.z + lhs.m33;

    w = 1 / w;
    x *= w;
    y *= w;
    z *= w;
    res->x = x;
    res->y = y;
    res->z = z;
}
// Transforms a position by this matrix, without a perspective divide. (fast)
void matrix4x4_mult_point3x4(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 point)
{
    res->x = lhs.m00 * point.x + lhs.m01 * point.y + lhs.m02 * point.z + lhs.m03;
    res->y = lhs.m10 * point.x + lhs.m11 * point.y + lhs.m12 * point.z + lhs.m13;
    res->z = lhs.m20 * point.x + lhs.m21 * point.y + lhs.m22 * point.z + lhs.m23;
}

// Transforms a direction by this matrix.
void matrix4x4_mult_vec3(FixedVec3* res, FixedMatrix4x4 lhs, FixedVec3 vector)
{
    res->x = lhs.m00 * vector.x + lhs.m01 * vector.y + lhs.m02 * vector.z;
    res->y = lhs.m10 * vector.x + lhs.m11 * vector.y + lhs.m12 * vector.z;
    res->z = lhs.m20 * vector.x + lhs.m21 * vector.y + lhs.m22 * vector.z;
}

// Creates a scaling matrix.
void matrix4x4_scale(FixedMatrix4x4* res, FixedVec3 vector)
{
    auto zero = fixed_float::zero();
    auto one = fixed_float::one();
    res->m00 = vector.x; res->m01 = zero; res->m02 = zero; res->m03 = zero;
    res->m10 = zero; res->m11 = vector.y; res->m12 = zero; res->m13 = zero;
    res->m20 = zero; res->m21 = zero; res->m22 = vector.z; res->m23 = zero;
    res->m30 = zero; res->m31 = zero; res->m32 = zero; res->m33 = one;
}

// Creates a translation matrix.
void matrix4x4_translate(FixedMatrix4x4* res, FixedVec3 vector)
{
    auto zero = fixed_float::zero();
    auto one = fixed_float::one();
    res->m00 = one; res->m01 = zero; res->m02 = zero; res->m03 = vector.x;
    res->m10 = zero; res->m11 = one; res->m12 = zero; res->m13 = vector.y;
    res->m20 = zero; res->m21 = zero; res->m22 = one; res->m23 = vector.z;
    res->m30 = zero; res->m31 = zero; res->m32 = zero; res->m33 = one;
}
// Creates a rotation matrix. Note: Assumes unit quaternion
void matrix4x4_rotate(FixedMatrix4x4* res, FixedQuaternion q)
{
    auto zero = fixed_float::zero();
    auto one = fixed_float::one();
    
    auto num1 = q.x * 2;
    auto num2 = q.y * 2;
    auto num3 = q.z * 2;
    auto num4 = q.x * num1;
    auto num5 = q.y * num2;
    auto num6 = q.z * num3;
    auto num7 = q.x * num2;
    auto num8 = q.x * num3;
    auto num9 = q.y * num3;
    auto num10 = q.w * num1;
    auto num11 = q.w * num2;
    auto num12 = q.w * num3;
    res->m00 = (one - (num5 + num6));
    res->m10 = num7 + num12;
    res->m20 = num8 - num11;
    res->m30 = zero;
    res->m01 = num7 - num12;
    res->m11 = (one - ( num4 + num6));
    res->m21 = num9 + num10;
    res->m31 = zero;
    res->m02 = num8 + num11;
    res->m12 = num9 - num10;
    res->m22 = (one - ( num4 + num5));
    res->m32 = zero;
    res->m03 = zero;
    res->m13 = zero;
    res->m23 = zero;
    res->m33 = one;
}

#pragma endregion