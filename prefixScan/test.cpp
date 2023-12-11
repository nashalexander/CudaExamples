#include "prefixScan.hpp"

#include <assert.h>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <cmath>

#define TEST_PASSED() printf("%s PASSED\n", __func__)

constexpr float FLOAT_PRECISION = 1e-5;

void testPrefixScanCPU() {
    constexpr std::size_t size = 5;
    constexpr float input[] = {2.5, 4.5, 6.2, 2.7, 1.9};
    constexpr float expected[] = {0.0, 2.5, 7.0, 13.2, 15.9};
    float output[size] = {0};

    prefixScanCPU(input, output, size);
    for(int i = 0; i < size ; i++) {
        assert(std::fabs(expected[i] - output[i]) < FLOAT_PRECISION);
    }

    TEST_PASSED();
}

// Assumes prefixScanCPU has been tested first and is valid
void testPrefixScanSimpleGPU() {
    constexpr std::size_t size = 10000;
    float input[size];
    float expected[size];
    float output[size] = {0};

    // initialize input and expected
    for(int i = 0; i < size ; i++) {
        input[i] = 1;
    }
    prefixScanCPU(input, expected, size);

    prefixScanSimpleGPU(input, output, size);
    for(int i = 0; i < size ; i++) {
        assert(std::fabs(expected[i] - output[i]) < FLOAT_PRECISION);
    }

    TEST_PASSED();
}


int main() {
    testPrefixScanCPU();
    testPrefixScanSimpleGPU();

    return 0;
}
