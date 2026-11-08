#include "matmul.h"

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <random>
#include <string>
#include <vector>

using Clock = std::chrono::high_resolution_clock;

// 返回中位数耗时（毫秒）
template <typename Fn>
double bench(Fn&& fn, int warmup, int iters) {
    for (int i = 0; i < warmup; ++i) fn();
    std::vector<double> t;
    t.reserve(iters);
    for (int i = 0; i < iters; ++i) {
        auto t0 = Clock::now();
        fn();
        auto t1 = Clock::now();
        t.push_back(std::chrono::duration<double, std::milli>(t1 - t0).count());
    }
    std::sort(t.begin(), t.end());
    return t[t.size() / 2];
}

int main(int argc, char** argv) {
    std::vector<int> sizes;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) sizes.push_back(std::atoi(argv[i]));
    } else {
        sizes = {256, 512, 1024};
    }

    std::printf("%-6s %12s %12s %10s\n", "N", "median_ms", "GFLOPS", "check");
    std::printf("----------------------------------------------\n");

    for (int N : sizes) {
        const size_t n = static_cast<size_t>(N) * N;
        std::vector<float> A(n), B(n), C(n, 0.f), ref(n, 0.f);

        std::mt19937 rng(42);
        std::uniform_real_distribution<float> dist(0.f, 1.f);
        for (auto& x : A) x = dist(rng);
        for (auto& x : B) x = dist(rng);

        // 参考结果，用于校验后续优化版本
        matmul_naive(A, B, ref, N);

        double ms = bench([&] { matmul_naive(A, B, C, N); }, 1, 5);
        double gflops = 2.0 * N * N * N / (ms * 1e6);

        std::printf("%-6d %12.2f %12.3f %10s\n", N, ms, gflops,
                    verify(C, ref) ? "OK" : "FAIL");
    }
    return 0;
}
