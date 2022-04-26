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

void pow(FixedFloat* in, FixedFloat base, FixedFloat pow)
{
    auto ffBase = fixed_float::from_raw_value(base.rawValue);
    auto ffPow = fixed_float::from_raw_value(pow.rawValue);
    auto res = fpm::pow(ffBase, ffPow);
    in->rawValue = res.raw_value();
}