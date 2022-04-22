//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

fixed_float_base_type mix(fixed_float_base_type integer, fixed_float_base_type numerator, fixed_float_base_type denominator)
{
    fixed_float res = fixed_float::mix(integer, numerator, denominator);
    return res.raw_value();
}
fixed_float_base_type test_add(fixed_float_base_type a_raw, fixed_float_base_type b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw) + fixed_float ::from_raw_value(b_raw);
    return res.raw_value();
}
fixed_float_base_type test_mult(fixed_float_base_type a_raw, fixed_float_base_type b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw) * fixed_float ::from_raw_value(b_raw);
    return res.raw_value();
}
fixed_float_base_type test_minus(fixed_float_base_type a_raw, fixed_float_base_type b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw) - fixed_float ::from_raw_value(b_raw);
    return res.raw_value();
}
fixed_float_base_type test_div(fixed_float_base_type a_raw, fixed_float_base_type b_raw)
{
    fixed_float res = fixed_float::from_raw_value(a_raw) / fixed_float ::from_raw_value(b_raw);
    return res.raw_value();
}

float to_float(fixed_float_base_type raw)
{
    return (float)fixed_float::from_raw_value(raw);
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int substract(int num1, int num2)
{
    return num1 - num2;
}

int divide(int num1, int num2)
{
    return num1 / num2;
}