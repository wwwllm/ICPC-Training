---
tags:
  - acm
  - graph
category: 图论
source:
  - "图论/网络流/Dinic.md"
---

# Dinic

## 模块名称

Dinic

## 来源

- 图论/网络流/Dinic.md

## 适用场景

图结构上的 Dinic 模板，适合出现路径、连通性、树、匹配、网络流等关键词时检索。

## 核心思想

Dinic 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：图论/网络流/Dinic.md

# Dinic 算法

Dinic 算法用于求解网络流中的**最大流问题**。它通过在分层图（Level Graph）上多次寻找增广路来优化效率，引入了**当前弧优化**和**多路增广**。

**时间复杂度**：一般图为 $O(V^2 E)$，在二分图中为 $O(E\sqrt{V})$。

## 实现

基于分层图优化的 Dinic 算法。

### 代码

```cpp
struct Flow
{
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    const int inf = 1e18;
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow() {};
    Flow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        cur.assign(n, 0);
        h.assign(n, -1);
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
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto p : g[u])
            {
                auto [v, c] = e[p];
                if (c > 0 && h[v] == -1)
                {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    int dfs(int u, int t, int f)
    {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < g[u].size(); i++)
        {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1)
            {
                int nf = dfs(v, t, min(r, c));
                e[j].cap -= nf;
                e[j ^ 1].cap += nf;
                r -= nf;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    int flow(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
    vector<bool> minCut()
    {
        vector<bool> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    struct Edge
    {
        int from;
        int to;
        int cap;
        int flow;
    };
    vector<Edge> edges()
    {
        vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2)
        {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```
### 例题链接
 [Luogu P3376 【模板】最大流](https://www.luogu.com.cn/problem/P3376)

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
