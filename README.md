# perf-lab

性能工程实验仓库。目标：把「代码能跑」变成「代码跑得快，且我能证明为什么快」。

## 实验协议

- 编译器：`g++ -O3 -march=native`（**所有版本必须使用相同选项**，否则加速比无意义）
- 计时：warmup + 重复 5 次取中位数
- 绑核：`taskset` 固定在 P 核（混合架构 CPU 不绑核，数字波动可达 30%）
- 规模：256 / 512 / 1024

## 环境

```
CPU: Intel Core Ultra 5 125H (4P + 8E + 2LPE, 18 threads)
RAM: 15.5 GB
OS : Windows 11 + WSL2 / Ubuntu 24.04.3 LTS
编译器: g++ 13.3.0, -O3 -march=native
```

## 如何复现

```bash
cmake -B build -G Ninja
cmake --build build
taskset -c 0 ./build/perf_lab 256 512 1024
```

## 进度

| 版本 | 说明 | 相对加速比 |
|---|---|---|
| v0 | 朴素三重循环 i-j-k | 1.0×（基线） |
| v1 | 循环交换 i-k-j | 待做 |
| v2 | 分块（blocking） | 待做 |
| v3 | 分块 + 循环展开 | 待做 |

## 目录

- `src/` 源码
- `include/` 头文件
- `data/` 原始数据（CSV）
- `docs/` 图表与报告
- `LOG.md` 每周记录
