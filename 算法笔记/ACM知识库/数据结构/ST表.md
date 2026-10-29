---
tags:
  - acm
  - ds
category: 数据结构
source:
  - "数据结构/ST表.md"
---

# ST表

## 模块名称

ST表

## 来源

- 数据结构/ST表.md

## 适用场景

需要维护动态信息、支持查询/修改/合并/回滚的数据结构题。

## 核心思想

ST表 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：数据结构/ST表.md

# ST 表

## 定义

ST 表用于在不可修改的序列上查询区间最小值。数组采用 0 下标，`query(l, r)` 查询非空半开区间 `[l, r)`；预处理时间和空间复杂度均为 $O(n\log n)$，单次查询时间复杂度为 $O(1)$。

## 实现

`st[k][i]` 维护区间 $[i,i+2^k)$ 的最小值。查询时令 $k=\lfloor\log_2(r-l)\rfloor$，合并分别贴近左右端点的两个长度为 $2^k$ 的区间；由于最小值运算满足幂等性，两个区间重叠不会影响答案。

### 代码

```cpp
struct ST
{
    int n, K;
    vector<vector<int>> st;
    vector<int> lg;
    ST() {}
    ST(int n)
    {
        vector<int> a(n, inf);
        init(a);
    }
    ST(vector<int> &a)
    {
        init(a);
    }
    void init(vector<int> &a)
    {
        n = a.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i >> 1] + 1;
        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            st[0][i] = a[i];
        }
        for (int k = 1; k < K; k++)
        {
            for (int i = 0; i + (1LL << k) <= n; i++)
            {
                st[k][i] = min(st[k - 1][i],
                               st[k - 1][i + (1LL << (k - 1))]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = lg[r - l];
        return min(st[k][l], st[k][r - (1LL << k)]);
    }
};
```

### 例题链接

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[线段树]]
[[并查集]]
[[莫队]]
