---
tags:
  - 字符串
Time: 2026-06-06T15:08:00
---

# 定义

扩展 KMP（在国外常被称为 Z 函数）用于在线性时间内求解：
1. 字符串 $S$ 的所有后缀与 $S$ 本身的最长公共前缀（LCP）长度。
2. 文本串 $T$ 的所有后缀与模式串 $S$ 的最长公共前缀（LCP）长度。

## 实现

常用于单串性质的分析，时间复杂度为 $O(n)$。

### 代码

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://www.luogu.com.cn/problem/P5410
vector<int> Z(string &s)
{
     int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++)
    {
        z[i] = max(0LL, min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > j + z[j])
            j = i;
    }
    return z;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    auto z = Z(b);
    vector<int> e(n);
    for (int i = 0, j = 0; i < n; i++)
    {
        e[i] = max(0LL, min(j + e[j] - i, z[i - j]));
        while (i + e[i] < n && e[i] < m && a[i + e[i]] == b[e[i]])
            e[i]++;
        if (i + e[i] > j + e[j])
            j = i;
    }
    int valz = 0;
    for (int i = 0; i < m; i++)
    {
        valz ^= (i + 1) * (z[i] + 1);
    }
    int vale = 0;
    for (int i = 0; i < n; i++)
    {
        vale ^= (i + 1) * (e[i] + 1);
    }
    cout << valz << '\n'
         << vale << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```

### 例题链接

[洛谷 P5410 【模板】扩展 KMP/exKMP（Z 函数）](https://www.luogu.com.cn/problem/P5410)

