---
tags:
  - acm
  - math
category: 数论
source:
  - "数论/快速数论变换（NTT）.md"
---

# 快速数论变换（NTT）

## 模块名称

快速数论变换（NTT）

## 来源

- 数论/快速数论变换（NTT）.md

## 适用场景

模意义下整数卷积、多项式乘法。

## 核心思想

在有原根的模数下用数论单位根替代复数单位根。

## 标准代码模板

### 标准版（推荐）

> 来源：数论/快速数论变换（NTT）.md

# 定义

**NTT (Number Theoretic Transform, 快速数论变换)** 是在数论值域（通常基于大质数模数）下的快速傅里叶变换（FFT）。它利用**原根**替代了复数域中的单位根，从而完美解决了 FFT 带来的浮点数精度误差问题。

## 实现

以下为模数 $P = 998244353$（原根 $G = 3$）下的通用 NTT 结构体封装实现。

### 代码

```cpp
namespace NTT
{
    const int mod = 998244353, g = 3;
    int exp(int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = a * ans % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    void dft(vector<int> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            int wn = exp(g, (mod - 1) / (2 * k));
            for (int i = 0; i < n; i += 2 * k)
            {
                int w = 1;
                for (int j = 0; j < k; j++)
                {
                    int u = a[i + j], v = a[i + j + k] * w % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + k] = (u - v + mod) % mod;
                    (w *= wn) %= mod;
                }
            }
        }
    }
    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int inv = exp(n, mod - 2);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= inv) %= mod;
        }
    }
    vector<int> mul(vector<int> a, vector<int> b)
    {
        int tot = a.size() + b.size() - 1;
        int n = 1;
        while (n < tot)
        {
            n <<= 1;
        }
        a.resize(n), b.resize(n);
        dft(a), dft(b);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= b[i]) %= mod;
        }
        idft(a);
        a.resize(tot);
        return a;
    }
};
```
### 例题链接

- [Luogu P3803 【模板】多项式乘法（FFT/NTT）](https://www.luogu.com.cn/problem/P3803)

## 复杂度

O(n log n)，空间 O(n)。

## 常见错误

- 模数必须支持所需长度的原根。
- 逆变换后要乘 inv(n)。

## 相关联知识

[[快速傅里叶变换（FFT）]]
[[普通生成函数]]
