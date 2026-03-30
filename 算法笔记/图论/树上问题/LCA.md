---
tags:
  - 树
Time: 2026-03-19
---

# 最近公共祖先 (LCA)

## 朴素实现 (Naive)
通过跳指针直到两点相遇。适用于单次查询或树高较小的情况。

### 代码

```cpp
struct LCA {
    int n;
    vector<int> d;
    vector<int> p;
    vector<vector<int>> adj;
    LCA(int n) : n(n), d(n + 1), p(n + 1), adj(n + 1) {}
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;
        p[u] = fa;
        for (int v : adj[u]) {
            if (v != fa) dfs(v, u);
        }
    }
    int query(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        while (d[u] > d[v]) u = p[u];
        while (u != v) u = p[u], v = p[v];
        return u;
    }
};
```
### 例题链接

[LuoGu P3379](https://www.luogu.com.cn/problem/P3379) (仅作逻辑验证，大数据量下会超时)

---

## 倍增实现 (Binary Lifting)

利用 $2^k$ 跳跃优化查找过程，预处理 $O(n \log n)$，单次查询 $O(\log n)$。

## 代码

C++

```cpp
struct LCA {
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;

    LCA(int n) : n(n), l(__lg(n) + 1), d(n + 1), f(n + 1, vector<int>(l, 0)), adj(n + 1) {}

    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int rt = 1) {
        dfs(rt, 0);
    }

    void dfs(int u, int fa) {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != fa) dfs(v, u);
        }
    }

    int query(int u, int v) {
        if (d[u] < d[v]) swap(u, v);
        for (int i = l - 1; i >= 0; i--) {
            if (d[f[u][i]] >= d[v]) u = f[u][i];
        }
        if (u == v) return u;
        for (int i = l - 1; i >= 0; i--) {
            if (f[u][i] != f[v][i]) {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    int dist(int u, int v) {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }
};
```

## 例题链接

[LuoGu P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379)