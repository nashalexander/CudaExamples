#include "prefixScan.hpp"

__global__
void prefixScanSimpleGPUImpl(const float * indata, float * outdata, std::size_t size) {
    int index = threadIdx.x + blockDim.x * blockIdx.x;
    int stride = blockDim.x * gridDim.x;

    for(int iStride = index; iStride < size ; iStride += stride) {
        outdata[iStride] = 0;

        for(int i = 0 ; i < iStride ; i++) {
            outdata[iStride] += indata[i];
        }
    }
}

void prefixScanSimpleGPU(const float * indata, float * outdata, std::size_t size) {
    const std::size_t bytes = size * sizeof(float);
    float * d_indata;
    float * d_outdata;

    cudaMalloc(&d_indata, bytes);
    cudaMalloc(&d_outdata, bytes);
    cudaMemcpy(d_indata, indata, bytes, cudaMemcpyHostToDevice);

    prefixScanSimpleGPUImpl<<<1, 1024>>>(d_indata, d_outdata, size);
    cudaMemcpy(outdata, d_outdata, bytes, cudaMemcpyDeviceToHost);

    cudaFree(d_indata);
    cudaFree(d_outdata);
}
