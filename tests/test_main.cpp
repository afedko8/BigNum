#include <gtest/gtest.h>
#include "bignum.h"
#include <string>
#include <cstdint>
#include <stdexcept>


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}