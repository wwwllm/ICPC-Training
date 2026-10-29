---
tags:
  - 数据结构
  - 静态区间查询
Time: 2026-08-11
---

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

