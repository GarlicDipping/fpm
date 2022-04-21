//
// Created by MinsooKim on 2022-04-20.
//

#include "include/fpm-unity.h"

fpm::fixed_16_16 test()
{
    fpm::fixed_16_16 x {0.5};
    return x;
}

fpm::fixed_16_16 test_add(fpm::fixed_16_16 a, fpm::fixed_16_16 b)
{
    return a + b;
}

fpm::fixed_16_16 test_mult(fpm::fixed_16_16 a, fpm::fixed_16_16 b)
{
    return a * b;
}

fpm::fixed_16_16 test_minus(fpm::fixed_16_16 a, fpm::fixed_16_16 b)
{
    return a - b;
}

fpm::fixed_16_16 test_div(fpm::fixed_16_16 a, fpm::fixed_16_16 b)
{
    return a / b;
}

int test_rawvalue(fpm::fixed_16_16 a)
{
    return a.raw_value();
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