#pragma once
#include <vector>

// 朴素实现：C = A * B，三者均为 N×N 行优先连续存储
void matmul_naive(const std::vector<float>& A,
                  const std::vector<float>& B,
                  std::vector<float>& C, int N);

// 正确性校验：逐元素比较
bool verify(const std::vector<float>& a,
            const std::vector<float>& b, float eps = 1e-3f);
