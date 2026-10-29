---
tags:
  - acm
  - string
category: 字符串
source:
  - "字符串/AC自动机.md"
---

# AC自动机

## 模块名称

AC自动机

## 来源

- 字符串/AC自动机.md

## 适用场景

多模式串匹配、敏感词统计、模式串出现次数。

## 核心思想

Trie 上补 fail 指针，失配时跳到最长可匹配后缀；统计贡献可沿 fail 树汇总。

## 标准代码模板

### 标准版（推荐）

> 来源：字符串/AC自动机.md

# AC 自动机 

## 定义
AC 自动机的拓扑排序优化版本。在标准 AC 自动机中，如果每次文本串匹配到一个节点都暴力向上跳 `fail` 指针更新答案，会被特殊构造的数据（如全 `a` 串）卡成 $O(|S| \times \text{模式串总长})$。拓扑排序优化通过只在匹配时给当前节点打上标记，最后根据 `fail` 树的拓扑序统一向上合并贡献，将时间复杂度严格保证为 $O(|S| + \sum|T|)$。

## 实现

### 代码

```cpp
struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), nxt{} {};
    };
    vector<Node> t;
    AC()
    {
        init();
    }
    void init()
    {
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }
    int insert(string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int u = c - 'a';
            if (next(p, u) == 0)
            {
                t[p].nxt[u] = newNode();
                t[next(p,u)].len = t[p].len + 1;
            }
            p =next(p,u);
        }
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (next(x, i) == 0)
                {
                    t[x].nxt[i] = next(link(x),i);
                }
                else
                {
                    t[next(x,i)].link = next(link(x),i);
                    q.push(next(x,i));
                }
            }
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
};
```
### 例题链接

[Luogu P5357 【模板】AC 自动机（二次加强版）](https://www.luogu.com.cn/problem/P5357)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        int cnt;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), nxt{}, cnt(0) {};
    };
    vector<Node> t;
    vector<int> ind;
    AC()
    {
        init();
    }
    void init()
    {
        ind.assign(2, 0);
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        ind.emplace_back(0);
        return t.size() - 1;
    }
    int insert(string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int u = c - 'a';
            if (next(p, u) == 0)
            {
                t[p].nxt[u] = newNode();
                t[next(p, u)].len = t[p].len + 1;
            }
            p = next(p, u);
        }
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (next(x, i) == 0)
                {
                    t[x].nxt[i] = next(link(x), i);
                }
                else
                {
                    ind[next(link(x), i)]++;
                    t[next(x, i)].link = next(link(x), i);
                    q.push(next(x, i));
                }
            }
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
    void match(const string &s)
    {
        int p = 1;
        for (auto c : s)
        {
            p = next(p, c - 'a');
            t[p].cnt++;
        }
    }
    void topu()
    {
        queue<int> q;
        for (int i = 1; i < t.size(); i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            int v = link(u);
            t[v].cnt += t[u].cnt;
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
};
signed main()
{
    int n;
    cin >> n;
    vector<int> pos(n);
    AC ac;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pos[i] = ac.insert(s);
    }
    ac.work();
    string t;
    cin >> t;
    ac.match(t);
    ac.topu();
    for (int i = 0; i < n; i++)
        cout << ac.t[pos[i]].cnt << '\n';
    return 0;
}
```

## 复杂度

建树 O(模式串总长 * 字符集) 或 O(总长)，匹配 O(文本长)。

## 常见错误

- fail 转移要补全，否则匹配时会掉到 0。
- 多模式计数要处理重复模式和 fail 树贡献。

## 相关联知识

[[Trie树]]
[[KMP算法]]
[[后缀自动机]]
