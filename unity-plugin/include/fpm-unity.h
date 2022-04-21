//
// Created by MinsooKim on 2022-04-20.
//

#ifndef FPM_FPM_UNITY_H
#define FPM_FPM_UNITY_H

#define DLLExport __declspec(dllexport)

#include "fpm/fixed.hpp"  // For fpm::fixed_16_16
#include "fpm/math.hpp"   // For fpm::cos
#include "fpm/ios.hpp"    // For fpm::operator<<

extern "C"
{
DLLExport fpm::fixed_16_16 test();
DLLExport fpm::fixed_16_16 test_add(fpm::fixed_16_16 a, fpm::fixed_16_16 b);
DLLExport fpm::fixed_16_16 test_mult(fpm::fixed_16_16 a, fpm::fixed_16_16 b);
DLLExport fpm::fixed_16_16 test_minus(fpm::fixed_16_16 a, fpm::fixed_16_16 b);
DLLExport fpm::fixed_16_16 test_div(fpm::fixed_16_16 a, fpm::fixed_16_16 b);
DLLExport int test_rawvalue(fpm::fixed_16_16 a);
DLLExport int add(int num1, int num2);
DLLExport int multiply(int num1, int num2);
DLLExport int substract(int num1, int num2);
DLLExport int divide(int num1, int num2);
}

#endif //FPM_FPM_UNITY_H
