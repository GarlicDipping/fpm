//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

#pragma region Arithmatics

FixedFloat add(FixedFloat a_raw, FixedFloat b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
            + fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedFloat multiply(FixedFloat a_raw, FixedFloat b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      * fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedFloat subtract(FixedFloat a_raw, FixedFloat b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      - fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}
FixedFloat divide(FixedFloat a_raw, FixedFloat b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw.rawValue)
                      / fixed_float ::from_raw_value(b_raw.rawValue);
    a_raw.rawValue = res.raw_value();
    return a_raw;
}

#pragma endregion

#pragma region Utilities

void from_int(FixedFloat* in, fixed_float_base_type integer)
{
    fixed_float res {integer};
    in->rawValue = res.raw_value();
}

void mix(FixedFloat* in, fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator)
{
    fixed_float res = fixed_float::mix(integer, numerator, denominator);
    in->rawValue = res.raw_value();
}

float to_float(FixedFloat raw)
{
    return (float)fixed_float::from_raw_value(raw.rawValue);
}

#pragma endregion

#pragma region Mathmatics


void ff_ceil(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::ceil(ffVal);
    in->rawValue = res.raw_value();
}
void ff_floor(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::floor(ffVal);
    in->rawValue = res.raw_value();
}
void ff_trunc(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::trunc(ffVal);
    in->rawValue = res.raw_value();
}
void ff_round(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::round(ffVal);
    in->rawValue = res.raw_value();
}
void ff_abs(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::abs(ffVal);
    in->rawValue = res.raw_value();
}
void ff_fmod(FixedFloat* in, FixedFloat x, FixedFloat y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::fmod(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_remainder(FixedFloat* in, FixedFloat x, FixedFloat y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::remainder(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_copysign(FixedFloat* in, FixedFloat x, FixedFloat y)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto res = fpm::copysign(ffX, ffY);
    in->rawValue = res.raw_value();
}
void ff_modf(FixedFloat* in, FixedFloat val, FixedFloat* iPtr)
{
    fixed_float iVal;
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::modf(ffVal, &iVal);
    in->rawValue = res.raw_value();
    iPtr->rawValue = iVal.raw_value();
}

void ff_pow(FixedFloat* in, FixedFloat base, FixedFloat pow)
{
    auto ffBase = fixed_float::from_raw_value(base.rawValue);
    auto ffPow = fixed_float::from_raw_value(pow.rawValue);
    auto res = fpm::pow(ffBase, ffPow);
    in->rawValue = res.raw_value();
}

void ff_exp(FixedFloat* in, FixedFloat x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::exp(ffX);
    in->rawValue = res.raw_value();
}
void ff_exp2(FixedFloat* in, FixedFloat x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::exp2(ffX);
    in->rawValue = res.raw_value();
}
void ff_log2(FixedFloat* in, FixedFloat x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log2(ffX);
    in->rawValue = res.raw_value();
}
void ff_ln(FixedFloat* in, FixedFloat x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log(ffX);
    in->rawValue = res.raw_value();
}
void ff_log10(FixedFloat* in, FixedFloat x)
{
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::log10(ffX);
    in->rawValue = res.raw_value();
}

void ff_cbrt(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::cbrt(ffVal);
    in->rawValue = res.raw_value();
}
void ff_sqrt(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::sqrt(ffVal);
    in->rawValue = res.raw_value();
}







#pragma endregion

#pragma region Trigonometrics

void ff_sin(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::sin(ffVal);
    in->rawValue = res.raw_value();
}

void ff_cos(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::cos(ffVal);
    in->rawValue = res.raw_value();
}

void ff_tan(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::tan(ffVal);
    in->rawValue = res.raw_value();
}

void ff_asin(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::asin(ffVal);
    in->rawValue = res.raw_value();
}

void ff_acos(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::acos(ffVal);
    in->rawValue = res.raw_value();
}

void ff_atan(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::atan(ffVal);
    in->rawValue = res.raw_value();
}

void ff_atan2(FixedFloat* in, FixedFloat y, FixedFloat x)
{
    auto ffY = fixed_float::from_raw_value(y.rawValue);
    auto ffX = fixed_float::from_raw_value(x.rawValue);
    auto res = fpm::atan2(ffY, ffX);
    in->rawValue = res.raw_value();
}

#pragma endregion

#pragma region Predefined variables

void e(FixedFloat* out)
{
    auto e = fixed_float::e();
    out->rawValue = e.raw_value();
}
void pi(FixedFloat* out)
{
    auto pi = fixed_float::pi();
    out->rawValue = pi.raw_value();
}
void half_pi(FixedFloat* out)
{
    auto half_pi = fixed_float::half_pi();
    out->rawValue = half_pi.raw_value();
}
void two_pi(FixedFloat* out)
{
    auto two_pi = fixed_float::two_pi();
    out->rawValue = two_pi.raw_value();
}

#pragma endregion