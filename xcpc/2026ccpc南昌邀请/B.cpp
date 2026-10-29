#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Info
{
    int max;
    Info() : max(-inf) {};
    Info(int value) : max(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.max = std::max(max, other.max);
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree() {};
    SegTree(int _n) : n(_n), info(4 * _n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<SegTree> T(n + 1);
    vector<int> dp1(n + 1), dp2(n + 1), h(n + 1);
    vector<int> pos(n + 1);
    vector g(n + 1, vector<int>(20, 0)), fa(n + 1, vector<int>(20));
    vector<int> dep(n + 1), dis(n + 1);
    dep[0] = -1;
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        int s = adj[u].size();
        fa[u][0] = f;
        for (int i = 1; i < 20; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        T[u] = SegTree(s);
        for (auto [v, w] : adj[u])
        {
            if (v == f)
                continue;
            dep[v] = dep[u] + 1;
            dis[v] = dis[u] + w;
            self(self, v, u);
            dp1[u] = max(dp1[u], dp1[v] + w);
        }
        for (int i = 0; i < s; i++)
        {
            auto [v, w] = adj[u][i];
            if (v == f)
                continue;
            pos[v] = i;
            T[u].modify(i, dp1[v] + w);
        }
        for (int i = 0; i < s; i++)
        {
            auto [v, w] = adj[u][i];
            if (v == f)
                continue;
            int l = i == 0 ? 0 : T[u].query(0, i).max,
                r = i == s - 1 ? 0 : T[u].query(i + 1, s).max;
            dp2[v] = max(dp2[v], max(l, r));
        }
    };
    dfs1(dfs1, 1, 0);
    auto dfs2 = [&](auto self, int u, int f) -> void
    {
        g[u][0] = dp2[u];
        for (int i = 1; i < 20; i++)
        {
            g[u][i] = max(g[u][i - 1], g[fa[u][i - 1]][i - 1]);
        }
        for (auto [v, w] : adj[u])
        {
            if (v == f)
                continue;
            h[v] = max(h[v], w + max(h[u], dp2[v]));
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    auto lca = [&](int u, int v) -> int
    {
        if (dep[u] < dep[v])
            swap(u, v);
        for (int i = 19; i >= 0; i--)
        {
            if (dep[fa[u][i]] >= dep[v])
                u = fa[u][i];
        }
        if (u == v)
            return u;
        for (int i = 19; i >= 0; i--)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i], v = fa[v][i];
            }
        }
        return fa[u][0];
    };
    auto dist = [&](int u, int v) -> int
    { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; };
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int d = dist(u, v);
        int LCA = lca(u, v);
        int x = u, y = v;
        int len = 0;
        for (int i = 19; i >= 0; i--)
        {
            if (dep[fa[u][i]] > dep[LCA])
            {
                len = max(len, g[u][i]);
                u = fa[u][i];
            }
            if (dep[fa[v][i]] > dep[LCA])
            {
                len = max(len, g[v][i]);
                v = fa[v][i];
            }
        }
        int s = adj[LCA].size();
        if (u != LCA)
        {
            u = pos[u];
            len = max(len, dp1[x]);
        }
        else
        {
            u = s;
        }
        if (v != LCA)
        {
            v = pos[v];
            len = max(len, dp1[y]);
        }
        else
        {
            v = s;
        }
        if (u > v)
            swap(u, v);
        len = max({len, T[LCA].query(0, u).max, T[LCA].query(v + 1, s).max, T[LCA].query(u + 1, v).max, h[LCA]});
        cout << len * 2 + d << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}