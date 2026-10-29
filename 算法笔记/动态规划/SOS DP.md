---
tags:
  - 动态规划
  - 状态压缩
Time: 2026-08-21
---

# SOS DP

## 定义

SOS DP（Sum Over Subsets DP）用于同时求出每个集合的所有子集或超集的权值和，本质是布尔格上的高维前缀和。设状态由 `n` 位二进制掩码表示，可将枚举每个状态全部子集的 $O(3^n)$ 优化为 $O(n2^n)$。

## 实现

子集求和维护

$$
g[S] = \sum_{T \subseteq S} f[T]
$$

即求每个集合的所有子集权值和。

初始令 `g = f`，依次枚举每一位 `bit`。当集合 `mask` 含有该位时，将未选择该位的状态 `mask ^ (1 << bit)` 合并到 `mask`。超集求和方向相反：当 `mask` 不含当前位时，将包含该位的状态合并到 `mask`。

掩码从 `0` 开始，输入数组长度必须恰好为 $2^n$。模板中的类型 `T` 需要支持加法；若答案可能超过类型范围，应改用模数类、`long long` 或 `__int128`。

### 代码

```cpp

struct SOSDP
{
    vector<int> sum(vector<int> &a, int n)
    {
        int size = 1 << n;
        for (int bit = 0; bit < n; bit++)
        {
            for (int mask = 0; mask < size; mask++)
            {
                if (mask >> bit & 1)
                    a[mask] += f[mask ^ (1LL << bit)];
            }
        }
    }
};
```

时间复杂度为 $O(n2^n)$，额外空间复杂度为 $O(1)$；返回结果所占空间为 $O(2^n)$。

### 例题链接
