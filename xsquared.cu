#include <iostream>

__global__
void square(float *arr, int size) {
    int index = threadIdx.x + blockDim.x * blockIdx.x;

    if(index < size) {
        arr[index] = (float)(index * index);
    }
}

int main() {
    constexpr int size = 10;
    float arr[size] = {0};
    float *d_arr;

    cudaMalloc(&d_arr, size * sizeof(float));
    square<<<1, size>>>(d_arr, size);
    cudaMemcpy(arr, d_arr, size * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_arr);

    for(int i = 0 ; i < size ; i++) {
        std::cout << arr[i] << ";";
    }
    std::cout << std::endl;

    return 0;
}