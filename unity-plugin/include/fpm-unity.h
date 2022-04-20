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
DLLExport int add(int num1, int num2);
DLLExport int multiply(int num1, int num2);
DLLExport int substract(int num1, int num2);
DLLExport int divide(int num1, int num2);
}

#endif //FPM_FPM_UNITY_H
