#include "prefixScan.hpp"

#include <assert.h>
#include <cstring>

void testPrefixScanCPU() {
    constexpr size_t size = 3;
    constexpr float input[] = {2.5, 4.5, 6.2};
    constexpr float expected[] = {0.0, 2.5, 7.0};
    float output[3] = {0};

    prefixScanCPU(input, output, size);
    assert(memcmp(expected, output, size) == 0);
}

// Assumes prefixScanCPU has been tested first and is valid
void testPrefixScanSimpleGPU() {
    constexpr size_t size = 10000;
    float input[size];
    float expected[size];
    float output[size] = {0};

    // initialize input and expected
    memset(input, 1, size);
    prefixScanCPU(input, expected, size);

    prefixScanSimpleGPU(input, output, size);
    assert(memcmp(expected, output, size) == 0);
}


int main() {
    testPrefixScanCPU();

    return 0;
}