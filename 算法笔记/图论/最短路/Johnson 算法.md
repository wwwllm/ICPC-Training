---
tags:
  - 最短路算法
Time: 2026-05-12T20:04:00
---

# Johnson 全源最短路径算法

## 定义
Johnson 算法用于求解带负权边（但无负环）的有向图全源最短路径。它通过给每个节点赋予一个势能值 $h(u)$，将原边权 $w(u, v)$ 重塑为非负边权 $\hat{w}(u, v) = w(u, v) + h(u) - h(v)$，从而允许对每个源点调用 Dijkstra 算法。

### 实现 (Structure-based)

#### 代码
```cpp
struct johnson
{
    const int inf = 1e9;
    struct _edge
    {
        int to;
        int val;
        _edge(int to, int val) : to(to), val(val) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g, D;
    vector<int> h;
    johnson(int n) : n(n)
    {
        init(n + 1);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        D.assign(n, vector<int>(n, inf));
    }
    void add(int u, int v, int w)
    {
        g[u].pb(e.size());
        e.pb({v, w});
    }
    int spfa()
    {
        for (int i = 1; i <= n; i++)
        {
            add(0, i, 0);
        }
        queue<int> q;
        h.assign(n + 1, inf);
        vector<int> vis(n + 1);
        vector<int> cnt(n + 1);
        h[0] = 0;
        vis[0] = 1;
        q.push(0);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            for (int idx : g[u])
            {
                auto [v, w] = e[idx];
                if (h[v] > h[u] + w)
                {
                    h[v] = h[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] > n)
                        return 0;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
        return 1;
    }
    void dij(int s)
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<int> dis(n + 1, inf);
        dis[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d)
                continue;
            for (auto idx : g[u])
            {
                auto [v, w] = e[idx];
                if (dis[v] > d + h[u] - h[v] + w)
                {
                    dis[v] = d + h[u] - h[v] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] > inf / 2)
                D[s][i] = inf;
            else
                D[s][i] = dis[i] - h[s] + h[i];
        }
    }
    bool work()
    {
        if (!spfa())
            return 0;
        for (int i = 1; i <= n; i++)
        {
            dij(i);
        }
        return 1;
    }
    int query(int s, int t)
    {
        return D[s][t];
    }
};
```
### 例题链接

- [Luogu P5905 【模板】Johnson 全源最短路](https://www.luogu.com.cn/problem/P5905)