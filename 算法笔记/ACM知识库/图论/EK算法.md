---
tags:
  - acm
  - graph
category: 图论
source:
  - "图论/网络流/EK算法.md"
---

# EK算法

## 模块名称

EK算法

## 来源

- 图论/网络流/EK算法.md

## 适用场景

图结构上的 EK算法 模板，适合出现路径、连通性、树、匹配、网络流等关键词时检索。

## 核心思想

EK算法 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：图论/网络流/EK算法.md

# Edmonds-Karp (EK) 算法

Edmonds-Karp 算法通过不断在残量网络中寻找增广路（使用 BFS）来增加流量，直到不存在增广路为止。其时间复杂度为 $O(VE^2)$。

## 实现

### 代码

```cpp
const int inf = 1e18;
struct EK
{
    int n;
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> pre, pre_e;

    EK() {};
    EK(int n) : n(n) { init(n); };
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        pre.assign(n, 0);
        pre_e.assign(n, 0);
    }
    void add(int u, int v, int c)
    {
        g[u].push_back(e.size());
        e.push_back({v, c});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    bool bfs(int s, int t)
    {
        vector<int> vis(n);
        queue<int> q;
        q.push(s);
        pre[s] = -1;
        pre_e[s] = -1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto p : g[u])
            {
                auto [v, c] = e[p];
                if (vis[v] || c <= 0)
                    continue;
                vis[v] = 1;
                pre[v] = u;
                pre_e[v] = p;
                q.push(v);
                if (v == t)
                    return 1;
            }
        }
        return 0;
    }
    int flow(int s, int t)
    {
        int res = 0;
        while (bfs(s, t))
        {
            int f = inf;
            for (int v = t; v != s; v = pre[v])
            {
                int p = pre_e[v];
                f = min(f, e[p].cap);
            }
            for (int v = t; v != s; v = pre[v])
            {
                int p = pre_e[v];
                e[p].cap -= f;
                e[p ^ 1].cap += f;
            }
            res += f;
        }
        return res;
    }
};
```
### 例题链接

 [Luogu P3376 【模板】网络最大流](https://www.luogu.com.cn/problem/P3376)

## 复杂度

见原模板说明；若模板未标注，比赛中应按主循环/递归深度重新估算。

## 常见错误

- 确认下标从 0 还是 1 开始。
- 确认数组大小、INF、取模和 long long。
- 提交前用最小样例、边界样例和随机数据各测一次。

## 相关联知识

[[Dijkstra 算法]]
[[LCA]]
[[最小生成树]]
