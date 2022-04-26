//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

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

//Mathmatics

void ff_pow(FixedFloat* in, FixedFloat base, FixedFloat pow)
{
    auto ffBase = fixed_float::from_raw_value(base.rawValue);
    auto ffPow = fixed_float::from_raw_value(pow.rawValue);
    auto res = fpm::pow(ffBase, ffPow);
    in->rawValue = res.raw_value();
}

void ff_sqrt(FixedFloat* in, FixedFloat val)
{
    auto ffVal = fixed_float::from_raw_value(val.rawValue);
    auto res = fpm::sqrt(ffVal);
    in->rawValue = res.raw_value();
}

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