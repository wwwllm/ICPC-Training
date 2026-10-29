---
tags:
  - acm
  - graph
category: 图论
source:
  - "图论/Kruskal重构树.md"
---

# Kruskal重构树

## 模块名称

Kruskal重构树

## 来源

- 图论/Kruskal重构树.md

## 适用场景

图结构上的 Kruskal重构树 模板，适合出现路径、连通性、树、匹配、网络流等关键词时检索。

## 核心思想

Kruskal重构树 的核心是把题目约束转化为稳定可复用的竞赛模型，再用模板化代码快速落地。

## 标准代码模板

### 标准版（推荐）

> 来源：图论/Kruskal重构树.md

# Kruskal 重构树

## 定义
在 Kruskal 算法合并 $u, v$ 所在的连通块时，不直接连边，而是新建一个节点 $node$，令 $node$ 的权值为该边的边权，并让 $u, v$ 所在树的根节点成为 $node$ 的左右儿子。最终形成一棵拥有 $2n-1$ 个节点的二叉树（原图连通情况下）。

**性质：**
1. 是一棵大根堆（如果是最小生成树重构）。
2. 原图中 $u, v$ 路径上最大边权的最小值，等于重构树中 $LCA(u, v)$ 的点权。
3. 叶子节点均为原图节点，非叶子节点均为原图的边。

### 实现
采用 `struct` 封装，包含并查集初始化与重构树构建过程。

### 代码

```cpp
struct DSU
{
    vector<int> dsu;
    DSU(int n)
    {
        dsu.assign(n, 0);
        iota(dsu.begin(), dsu.end(), 0);
    }
    int find(int x)
    {
        return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
    }
};
struct KruTree
{
    int n, cur;
    vector<array<int, 3>> e;
    vector<vector<int>> g;
    vector<int> val;
    vector<vector<int>> fa;
    vector<int> dep;
    DSU dsu;
    KruTree(int n) : n(n), cur(n), e(), g(2 * n + 1, vector<int>{}), val(2 * n + 1), fa(2 * n + 1, vector<int>(31)), dep(2 * n + 1), dsu(2 * n + 1) { dep[0] = -1; };
    void add(int u, int v, int w)
    {
        e.pb({w, u, v});
    }
    void work()
    {
        sort(e.begin(), e.end());
        for (auto [w, u, v] : e)
        {
            int fu = dsu.find(u), fv = dsu.find(v);
            if (fu == fv)
                continue;
            cur++;
            dsu.dsu[fu] = dsu.dsu[fv] = cur;
            val[cur] = w;
            g[cur].pb(fu);
            g[cur].pb(fv);
        }
        for (int i = 1; i <= cur; i++)
        {
            if (dsu.find(i) == i)
                DFS(i, 0);
        }
    }
    void DFS(int u, int f)
    {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 1; i <= 30; i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            DFS(v, u);
        }
    }
    int lca(int u, int v)
    {
        if (dsu.find(u) != dsu.find(v))
            return -1;
        if (dep[u] > dep[v])
            swap(u, v);
        int d = dep[v] - dep[u];
        for (int i = 0; i <= 30; i++)
        {
            if (d >> i & 1)
                v = fa[v][i];
        }
        if (u == v)
            return val[u];
        for (int i = 30; i >= 0; i--)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return val[fa[u][0]];
    }
};
```

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
