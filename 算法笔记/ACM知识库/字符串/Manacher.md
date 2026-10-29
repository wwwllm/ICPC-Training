---
tags:
  - acm
  - string
category: 字符串
source:
  - "字符串/Manacher.md"
---

# Manacher

## 模块名称

Manacher

## 来源

- 字符串/Manacher.md

## 适用场景

字符串匹配、统计、自动机或子串结构问题。

## 核心思想

Manacher 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：字符串/Manacher.md

# 定义

马拉车算法（Manacher's Algorithm）用于在线性 $O(n)$ 时间复杂度内，求出字符串中以每个字符（或字符间隙）为中心的最长回文子串长度。

## 实现

通过在原字符串的每个字符左右及首尾插入特殊字符（如 `#`），将奇数长度和偶数长度的回文串统一处理为奇数长度。同时在最首尾两端加入不同的边界符（如 `$` 和 `^`）以避免边界越界检查。在匹配过程中，利用前面已经匹配过的回文对称信息来加速当前的匹配。

### 代码

```cpp
struct Manacher
{
    int n;
    string s;
    vector<int> r;
    Manacher(string _s)
    {
        s = '#';
        for (auto c : _s)
        {
            s += c, s += '#';
        }
        n = s.size();
        r.resize(n);
        init();
    }
    void init()
    {
        for (int i = 0, c = 0; i < n; i++)
        {
            if (2 * c - i >= 0 && c + r[c] > i)
            {
                r[i] = min(r[2 * c - i], c + r[c] - i);
            }
            while (i - r[i] >= 0 && i + r[i] < n && s[i - r[i]] == s[i + r[i]])
            {
                r[i]++;
            }
            if (i + r[i] > c + r[c])
                c = i;
        }
    }
    int get_max()
    {
        int res = 0;
        for (int l : r)
        {
            res = max(res, l - 1);
        }
        return res;
    }
    bool check(int x, int y)
    {
        int nl = x * 2 + 1;
        int nr = y * 2 + 1;
        int mid = nl + nr >> 1;
        return r[mid] - 1 >= y - x + 1;
    }
};
```
### 例题链接

- [洛谷 P3805 【模板】manacher 算法](https://www.luogu.com.cn/problem/P3805)

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[KMP算法]]
[[字符串哈希]]
[[Trie树]]
