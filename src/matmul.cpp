#include "matmul.h"
#include <cmath>

// 朴素三重循环：i-j-k 顺序
// 注意：最内层对 B 的访问跨行（stride = N），cache 极不友好
// 这正是后面要做循环交换 / 分块的动机
void matmul_naive(const std::vector<float>& A,
                  const std::vector<float>& B,
                  std::vector<float>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            float sum = 0.f;
            for (int k = 0; k < N; ++k) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

bool verify(const std::vector<float>& a,
            const std::vector<float>& b, float eps) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::fabs(a[i] - b[i]) > eps) return false;
    }
    return true;
}
