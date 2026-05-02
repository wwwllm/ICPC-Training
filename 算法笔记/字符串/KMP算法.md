---
tags:
  - 字符串
Time: 2026-04-07
---

# KMP 算法

## 实现 (结构体封装版)

KMP 算法用于在主串中快速查找模式串。其核心在于利用已匹配的信息，通过 `next` 数组（失配函数）跳过不必要的比较。

### 代码

```cpp
vector<int> kmp(string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
```
```