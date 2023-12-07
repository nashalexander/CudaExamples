#include "prefixScan.hpp"

__global__
void prefixScanSimpleGPUImpl(const float * indata, float * outdata, size_t size) {
    int index = threadIdx.x + blockDim.x * blockIdx.x;

    if(index == 0) {
        outdata[index] = 0;
        return;
    }

    for(int i = 0 ; i < index ; i++) {
        outdata[index] += indata[i];
    }
}

void prefixScanSimpleGPU(const float * indata, float * outdata, size_t size) {
    prefixScanSimpleGPUImpl<<<1024, 1024>>>(indata, outdata, size);
}
