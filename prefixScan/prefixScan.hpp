#ifndef PREFIX_SCAN_HPP
#define PREFIX_SCAN_HPP

#include <cstddef>

void prefixScanCPU(const float * indata, float * outdata, std::size_t size);
void prefixScanSimpleGPU(const float * indata, float * outdata, std::size_t size);

#endif