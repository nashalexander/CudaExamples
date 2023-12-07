#ifndef PREFIX_SCAN_HPP
#define PREFIX_SCAN_HPP

void prefixScanCPU(const float * indata, float * outdata, size_t size);
void prefixScanSimpleGPU(const float * indata, float * outdata, size_t size);

#endif