---
tags:
  - acm
  - math
category: 数论
source:
  - "数论/快速傅里叶变换（FFT）.md"
---

# 快速傅里叶变换（FFT）

## 模块名称

快速傅里叶变换（FFT）

## 来源

- 数论/快速傅里叶变换（FFT）.md

## 适用场景

实数/复数域卷积、多项式乘法。

## 核心思想

分治利用单位根把点值表达快速变换，乘法在点值域逐点相乘。

## 标准代码模板

### 标准版（推荐）

> 来源：数论/快速傅里叶变换（FFT）.md

# 快速傅里叶变换 (FFT)

## 介绍
快速傅里叶变换 (FFT) 是一种高效计算离散傅里叶变换 (DFT) 及其逆变换 (IDFT) 的算法。它利用单位复数根的对称性与周期性，通过分治策略将多项式从**系数表示法**转换为**点值表示法**，从而将原本 $O(N^2)$ 的多项式乘法复杂度降低到 $O(N \log N)$。

## 功能
* **多项式乘法**：高效计算两个高次多项式的乘积（线性卷积）。
* **大整数乘法**：将高精度大整数视为多项式进行快速相乘。
* **字符串匹配**：通过构造多项式，处理带有通配符（模糊匹配）的字符串模式匹配问题。

---

## 迭代法实现

### 代码

```cpp
const double pi = acos(-1.0);
using Complex = complex<double>;
struct FFT
{
    vector<int> a, b;
    FFT(vector<int> &a, vector<int> &b) : a(a), b(b) {};
    vector<int> mul()
    {
        int n = 1;
        int tot = a.size() + b.size() - 1;
        while (n < tot)
        {
            n <<= 1;
        }
        vector<Complex> fa(n), fb(n);
        for (int i = 0; i < a.size(); i++)
        {
            fa[i] = a[i];
        }
        for (int i = 0; i < b.size(); i++)
        {
            fb[i] = b[i];
        }
        dft(fa);
        dft(fb);
        for (int i = 0; i < n; i++)
        {
            fa[i] *= fb[i];
        }
        idft(fa);
        vector<int> c(tot);
        for (int i = 0; i < c.size(); i++)
        {
            c[i] = round(fa[i].real());
        }
        return c;
    }
    void dft(vector<Complex> &a)
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
            Complex wn(cos(pi / k), sin(pi / k));
            for (int i = 0; i < n; i += 2 * k)
            {
                Complex w(1, 0);
                for (int j = 0; j < k; j++)
                {
                    Complex u = a[i + j], v = a[i + j + k] * w;
                    a[i + j] = u + v;
                    a[i + j + k] = u - v;
                    w *= wn;
                }
            }
        }
    }
    void idft(vector<Complex> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        for (int i = 0; i < n; i++)
        {
            a[i] /= n;
        }
    }
};
```

### 例题链接

* [洛谷 P3803 【模板】多项式乘法（FFT）](https://www.luogu.com.cn/problem/P3803)

## 复杂度

O(n log n)，空间 O(n)。

## 常见错误

- 长度要扩到不小于卷积长度的 2 的幂。
- 浮点四舍五入和精度误差要处理。

## 相关联知识

[[快速数论变换（NTT）]]
[[普通生成函数]]
