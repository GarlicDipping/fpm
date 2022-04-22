//
// Created by MinsooKim on 2022-04-22.
//
#include "common.hpp"
#include "../unity-plugin/include/fpm-unity.h"

TEST(unity_plugin, mix)
{
    auto half = mix(0, 5, 10);
    auto half_orig = fixed_float(0.5);
    EXPECT_EQ(half, half_orig.raw_value());

    auto tenhalf = mix(10, 5, 10);
    auto tenhalf_orig = fixed_float(10.5);

    EXPECT_EQ(tenhalf, tenhalf_orig.raw_value());
}

TEST(unity_plugin, to_float)
{
    auto half = mix(0, 5, 10);
    auto tenhalf = mix(10, 5, 10);
    auto tenpointone = mix(10, 1, 10);

//    std::cout << to_float(half) << std::endl;
//    std::cout << to_float(tenhalf) << std::endl;
//    std::cout << to_float(tenpointone) << std::endl;

    EXPECT_EQ(to_float(half), 0.5);
    EXPECT_EQ(to_float(tenhalf), 10.5);
    EXPECT_EQ(to_float(tenpointone), 10.1);
}