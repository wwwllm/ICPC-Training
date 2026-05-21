#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
struct HLD
{
    int n, root;
    vector<int> top, son, siz, dep, dfn, rnk, fa;
    vector<vector<int>> g;
    int cur;
    HLD(int n, int root) : n(n), root(root)
    {
        init();
    }
    void init()
    {
        g.assign(n, {});
        top.assign(n, 0);
        fa.assign(n, 0);
        son.assign(n, -1);
        rnk.assign(n, 0);
        dep.assign(n, 0);
        dfn.assign(n, 0);
        siz.assign(n, 0);
        dep[root] = 0;
        cur = 0;
    }
    void add(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void dfs1(int u, int f)
    {
        fa[u] = f, dep[u] = (f == -1 ? -1 : dep[f]) + 1, siz[u] = 1;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
    void dfs2(int u, int ftop)
    {
        dfn[u] = cur, rnk[cur] = u, top[u] = ftop;
        cur++;
        if (son[u] != -1)
            dfs2(son[u], ftop);
        for (auto v : g[u])
        {
            if (v == son[u] || v == fa[u])
                continue;
            dfs2(v, v);
        }
    }
    void work()
    {
        dfs1(root, -1);
        dfs2(root, root);
    }
    int lca(int u, int v)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] > dep[top[v]])
                u = fa[top[u]];
            else
                v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }
    vector<array<int, 2>> path(int u, int v, bool edge = 0)
    {
        vector<array<int, 2>> res;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            res.push_back({dfn[top[u]], dfn[u]});
            u = fa[top[u]];
        }
        if (u == v && edge)
            return res;
        if (dep[u] > dep[v])
            swap(u, v);
        res.push_back({dfn[u] + (edge ? 1 : 0), dfn[v]});
        return res;
    }
    array<int, 2> subtree(int u, bool edge = 0) const
    {
        return {dfn[u] + (edge ? 1 : 0), dfn[u] + siz[u] - 1};
    }
};
const int inf = 1e9;
struct Info
{
    int sum;
    Info() : sum() {};
    Info(int value) : sum(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = (sum + other.sum) % mod;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
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
    HLD g(n + 1, 1);
    vector<int> f(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> f[i];
        g.add(f[i], i);
    }
    g.work();
    auto &adj = g.g;
    int sum = 0;
    vector<int> dp0(n + 1);
    vector<int> dp1(n + 1);
    auto dfs1 = [&](auto &self, int u) -> void
    {
        dp0[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f[u])
                continue;
            self(self, v);
            (dp0[u] *= (dp0[v] + 1)) %= mod;
        }
        (sum += dp0[u]) %= mod;
        vector<int> pre, suf;
        for (auto v : adj[u])
        {
            if (v == f[u])
                continue;
            pre.push_back((dp0[v] + 1) % mod);
            suf.push_back((dp0[v] + 1) % mod);
        }
        for (int i = 1; i < (int)pre.size(); i++)
        {
            (pre[i] *= pre[i - 1]) %= mod;
        }
        for (int i = (int)suf.size() - 2; i >= 0; i--)
        {
            (suf[i] *= suf[i + 1]) %= mod;
        }
        int p = 0;
        for (auto v : adj[u])
        {
            if (v == f[u])
                continue;
            dp1[v] = 1;
            if (p > 0)
                (dp1[v] *= pre[p - 1]) %= mod;
            if (p < (int)suf.size() - 1)
                (dp1[v] *= suf[p + 1]) %= mod;
            p++;
        }
    };
    auto dfs2 = [&](auto &&self, int u) -> void
    {
        for (auto v : adj[u])
        {
            if (v == f[u])
                continue;
            (dp1[v] *= dp1[u] + 1) %= mod;
            self(self, v);
        }
    };
    dfs1(dfs1, 1), dfs2(dfs2, 1);
    SegTree t(n + 1);
    auto &dfn = g.dfn;
    for (int i = 1; i <= n; i++)
    {
        t.modify(dfn[i], dp0[i]);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int lca = g.lca(u, v);
        int ans = 0;
        auto path = g.path(u, v);
        for (auto [l, r] : path)
        {
            (ans += t.query(l, r + 1).sum) %= mod;
        }
        (ans += dp0[lca] * dp1[lca] % mod) %= mod;
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}