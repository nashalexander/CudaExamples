//
// Implementations of algorithms described here:
// https://developer.nvidia.com/gpugems/gpugems3/part-vi-gpu-computing/chapter-39-parallel-prefix-sum-scan-cuda
//

// The prefix scan algorithm is a parallel computation technique used to efficiently compute a
// running sum of a sequence of values in an array. It involves a parallel reduction phase followed
// by a scan phase, resulting in an array where each element represents the sum of all preceding
// elements in the original array.

#include "prefixScan.hpp"

// Single threaded implementation
void prefixScanCPU(const float * indata, float * outdata, size_t size) {
    outdata[0] = 0;
    for(int i = 1 ; i < size ; i++) {
        outdata[i] = 0;
        for(int j = 0 ; j < i ; j++) {
            outdata[i] += indata[j];
        }
    }
}