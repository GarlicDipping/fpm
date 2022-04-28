//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

#pragma region Arithmatics

FixedPoint add(FixedPoint a_raw, FixedPoint b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
            + fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedPoint multiply(FixedPoint a_raw, FixedPoint b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      * fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedPoint subtract(FixedPoint a_raw, FixedPoint b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      - fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedPoint divide(FixedPoint a_raw, FixedPoint b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      / fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}

#pragma endregion

#pragma region Utilities

fixed_float_base_type fractional_bits()
{
    return fixed_float_fraction_bits;
}

void from_raw(FixedPoint* in, fixed_float_base_type rawVal)
{
    fixed_float val = fixed_float::from_raw_value(rawVal);
    in->rawValue = val.raw_value();
}

void from_int(FixedPoint* in, fixed_float_base_type integer)
{
    fixed_float res {integer};
    in->rawValue = res.raw_value();
}

void mix(FixedPoint* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator)
{
    fixed_float res = fixed_float::mix(integer, numerator, denominator);
    in->rawValue = res.raw_value();
}

float to_float(FixedPoint raw)
{
    return (float)fixed_float::from_raw_value(raw.rawValue);
}

#pragma endregion

#pragma region Mathmatics


void ff_ceil(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::ceil(ffVal);
    in->rawValue = res.raw_value();
}
void ff_floor(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::floor(ffVal);
    in->rawValue = res.raw_value();
}
void ff_trunc(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::trunc(ffVal);
    in->rawValue = res.raw_value();
}
void ff_round(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::round(ffVal);
    in->rawValue = res.raw_value();
}
void ff_abs(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::abs(ffVal);
    in->rawValue = res.raw_value();
}
void ff_fmod(FixedPoint* in, FixedPoint x, FixedPoint y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::fmod(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_remainder(FixedPoint* in, FixedPoint x, FixedPoint y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::remainder(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_copysign(FixedPoint* in, FixedPoint x, FixedPoint y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::copysign(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_modf(FixedPoint* in, FixedPoint val, FixedPoint* iPtr)
{
    fixed_float iVal;
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::modf(ffVal, &iVal);
    in->rawValue = res.raw_value();
    iPtr->rawValue = iVal.raw_value();
}

void ff_pow(FixedPoint* in, FixedPoint base, FixedPoint pow)
{
    auto ffBase = fixed_float::from_raw_value(base.rawValue);
    auto ffPow = fixed_float::from_raw_value(pow.rawValue);
    auto res = fpm::pow(ffBase, ffPow);
    in->rawValue = res.raw_value();
}

void ff_exp(FixedPoint* in, FixedPoint x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::exp(ffX);
    in->rawValue = res.raw_value();
}
void ff_exp2(FixedPoint* in, FixedPoint x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::exp2(ffX);
    in->rawValue = res.raw_value();
}
void ff_log2(FixedPoint* in, FixedPoint x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log2(ffX);
    in->rawValue = res.raw_value();
}
void ff_ln(FixedPoint* in, FixedPoint x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log(ffX);
    in->rawValue = res.raw_value();
}
void ff_log10(FixedPoint* in, FixedPoint x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log10(ffX);
    in->rawValue = res.raw_value();
}

void ff_cbrt(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::cbrt(ffVal);
    in->rawValue = res.raw_value();
}
void ff_sqrt(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::sqrt(ffVal);
    in->rawValue = res.raw_value();
}







#pragma endregion

#pragma region Trigonometrics

void ff_sin(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::sin(ffVal);
    in->rawValue = res.raw_value();
}

void ff_cos(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::cos(ffVal);
    in->rawValue = res.raw_value();
}

void ff_tan(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::tan(ffVal);
    in->rawValue = res.raw_value();
}

void ff_asin(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::asin(ffVal);
    in->rawValue = res.raw_value();
}

void ff_acos(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::acos(ffVal);
    in->rawValue = res.raw_value();
}

void ff_atan(FixedPoint* in, FixedPoint val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::atan(ffVal);
    in->rawValue = res.raw_value();
}

void ff_atan2(FixedPoint* in, FixedPoint y, FixedPoint x)
{
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::atan2(ffY, ffX);
    in->rawValue = res.raw_value();
}

#pragma endregion

#pragma region Predefined variables

void e(FixedPoint* out)
{
    auto e = fixed_float::e();
    out->rawValue = e.raw_value();
}
void pi(FixedPoint* out)
{
    auto pi = fixed_float::pi();
    out->rawValue = pi.raw_value();
}
void half_pi(FixedPoint* out)
{
    auto half_pi = fixed_float::half_pi();
    out->rawValue = half_pi.raw_value();
}
void two_pi(FixedPoint* out)
{
    auto two_pi = fixed_float::two_pi();
    out->rawValue = two_pi.raw_value();
}

#pragma endregion

#pragma region FixedMatrix4x4

void matrix4x4_mult(FixedMatrix4x4* res, FixedMatrix4x4 lhs, FixedMatrix4x4 rhs)
{
    FixedMatrix4x4Native lhsNative {lhs};
    FixedMatrix4x4Native rhsNative {rhs};
    res->m00.rawValue = (lhsNative.m00 * rhsNative.m00 + lhsNative.m01 * rhsNative.m10 + lhsNative.m02 * rhsNative.m20 + lhsNative.m03 * rhsNative.m30).raw_value();
    res->m01.rawValue = (lhsNative.m00 * rhsNative.m01 + lhsNative.m01 * rhsNative.m11 + lhsNative.m02 * rhsNative.m21 + lhsNative.m03 * rhsNative.m31).raw_value();
    res->m02.rawValue = (lhsNative.m00 * rhsNative.m02 + lhsNative.m01 * rhsNative.m12 + lhsNative.m02 * rhsNative.m22 + lhsNative.m03 * rhsNative.m32).raw_value();
    res->m03.rawValue = (lhsNative.m00 * rhsNative.m03 + lhsNative.m01 * rhsNative.m13 + lhsNative.m02 * rhsNative.m23 + lhsNative.m03 * rhsNative.m33).raw_value();

    res->m10.rawValue = (lhsNative.m10 * rhsNative.m00 + lhsNative.m11 * rhsNative.m10 + lhsNative.m12 * rhsNative.m20 + lhsNative.m13 * rhsNative.m30).raw_value();
    res->m11.rawValue = (lhsNative.m10 * rhsNative.m01 + lhsNative.m11 * rhsNative.m11 + lhsNative.m12 * rhsNative.m21 + lhsNative.m13 * rhsNative.m31).raw_value();
    res->m12.rawValue = (lhsNative.m10 * rhsNative.m02 + lhsNative.m11 * rhsNative.m12 + lhsNative.m12 * rhsNative.m22 + lhsNative.m13 * rhsNative.m32).raw_value();
    res->m13.rawValue = (lhsNative.m10 * rhsNative.m03 + lhsNative.m11 * rhsNative.m13 + lhsNative.m12 * rhsNative.m23 + lhsNative.m13 * rhsNative.m33).raw_value();

    res->m20.rawValue = (lhsNative.m20 * rhsNative.m00 + lhsNative.m21 * rhsNative.m10 + lhsNative.m22 * rhsNative.m20 + lhsNative.m23 * rhsNative.m30).raw_value();
    res->m21.rawValue = (lhsNative.m20 * rhsNative.m01 + lhsNative.m21 * rhsNative.m11 + lhsNative.m22 * rhsNative.m21 + lhsNative.m23 * rhsNative.m31).raw_value();
    res->m22.rawValue = (lhsNative.m20 * rhsNative.m02 + lhsNative.m21 * rhsNative.m12 + lhsNative.m22 * rhsNative.m22 + lhsNative.m23 * rhsNative.m32).raw_value();
    res->m23.rawValue = (lhsNative.m20 * rhsNative.m03 + lhsNative.m21 * rhsNative.m13 + lhsNative.m22 * rhsNative.m23 + lhsNative.m23 * rhsNative.m33).raw_value();

    res->m30.rawValue = (lhsNative.m30 * rhsNative.m00 + lhsNative.m31 * rhsNative.m10 + lhsNative.m32 * rhsNative.m20 + lhsNative.m33 * rhsNative.m30).raw_value();
    res->m31.rawValue = (lhsNative.m30 * rhsNative.m01 + lhsNative.m31 * rhsNative.m11 + lhsNative.m32 * rhsNative.m21 + lhsNative.m33 * rhsNative.m31).raw_value();
    res->m32.rawValue = (lhsNative.m30 * rhsNative.m02 + lhsNative.m31 * rhsNative.m12 + lhsNative.m32 * rhsNative.m22 + lhsNative.m33 * rhsNative.m32).raw_value();
    res->m33.rawValue = (lhsNative.m30 * rhsNative.m03 + lhsNative.m31 * rhsNative.m13 + lhsNative.m32 * rhsNative.m23 + lhsNative.m33 * rhsNative.m33).raw_value();
}


#pragma endregion

void test_native(fixed_float* in, fixed_float t)
{
    //테스트 잘 되나?
    *in += t;
}