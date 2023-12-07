#include "prefixScan.hpp"

#include <assert.h>
#include <cstring>
#include <cstddef>
#include <cstdio>

#define TEST_PASSED() printf("%s PASSED\n", __func__)

void testPrefixScanCPU() {
    constexpr std::size_t size = 3;
    constexpr float input[] = {2.5, 4.5, 6.2};
    constexpr float expected[] = {0.0, 2.5, 7.0};
    float output[3] = {0};

    prefixScanCPU(input, output, size);
    assert(memcmp(expected, output, size) == 0);

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
    assert(memcmp(expected, output, size) == 0);

    TEST_PASSED();
}


int main() {
    testPrefixScanCPU();
    testPrefixScanSimpleGPU();

    return 0;
}