---
tags:
  - acm
  - string
category: 字符串
source:
  - "字符串/KMP算法.md"
---

# KMP算法

## 模块名称

KMP算法

## 来源

- 字符串/KMP算法.md

## 适用场景

单模式串匹配、最小循环节、border 相关问题。

## 核心思想

失配时利用已知最长相等前后缀跳转，避免主串指针回退。

## 标准代码模板

### 标准版（推荐）

> 来源：字符串/KMP算法.md

# KMP 算法

## 实现 (结构体封装版)

KMP 算法用于在主串中快速查找模式串。其核心在于利用已匹配的信息，通过 `next` 数组（失配函数）跳过不必要的比较。

### 代码

```cpp
//f:s[0,i)中匹配的长度
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

vector<int> match(string s, string p)
{
    int n = s.size(), m = p.size();
    auto f = kmp(p);
    vector<int> pos;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != p[j])
            j = f[j];

        if (s[i] == p[j])
            j++;

        if (j == m)
        {
            pos.push_back(i - m + 1);
            j = f[j];
        }
    }
    return pos;
}
```

## 复杂度

预处理 O(m)，匹配 O(n)，空间 O(m)。

## 常见错误

- next/f 数组含义和下标要统一。
- 模式串为空或长度 1 时注意边界。

## 相关联知识

[[扩展kmp（Z函数）]]
[[AC自动机]]
[[字符串哈希]]
