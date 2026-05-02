#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Info
{
    int max;
    int u;
    Info() : max(-inf), u(0) {};
    Info(int value, int u) : max(value), u(u) {};
    Info operator+(const Info &other) const
    {
        Info res;
        if (max < other.max)
        {
            res = other;
        }
        else
            res = *this;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * n) {};
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
    void modify(int x, int v, int u)
    {
        modify(1, 0, n, x, Info(v, u));
    }
};
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
    vector<int> dfn;
    vector<int> rk;
    vector<array<int, 2>> q;
    DSU dsu;
    KruTree(int n) : n(n), cur(n), dfn(n + 1), rk(n + 1), e(), g(2 * n + 1, vector<int>{}), val(2 * n + 1), fa(2 * n + 1, vector<int>(31)), dep(2 * n + 1), dsu(2 * n + 1), q(2 * n + 1) { dep[0] = -1; };
    void add(int u, int v, int w)
    {
        e.push_back({w, u, v});
    }
    void work()
    {
        ranges::sort(e);
        for (auto [w, u, v] : e)
        {
            int fu = dsu.find(u), fv = dsu.find(v);
            if (fu == fv)
                continue;
            cur++;
            dsu.dsu[fu] = dsu.dsu[fv] = cur;
            val[cur] = w;
            g[cur].push_back(fu);
            g[cur].push_back(fv);
        }
        int p = 0;
        auto dfs = [&](auto &&self, int u, int f) -> void
        {
            if (u <= n)
            {
                dfn[u] = ++p;
                rk[p] = u;
            }
            for (auto v : g[u])
            {
                if (v == f)
                    continue;
                self(self, v, u);
            }
        };
        for (int i = 1; i <= cur; i++)
        {
            if (dsu.find(i) == i)
                dfs(dfs, i, 0);
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
        if (u <= n)
        {
            q[u][0] = q[u][1] = dfn[u];
        }
        else
        {
            q[u][0] = inf;
            q[u][1] = 0;
        }
        for (int i = 1; i <= 30; i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            DFS(v, u);
            q[u][0] = min(q[u][0], q[v][0]);
            q[u][1] = max(q[u][1], q[v][1]);
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
    int jump(int u, int lim)
    {
        for (int i = 30; i >= 0; i--)
        {
            if (fa[u][i] && val[fa[u][i]] <= lim)
                u = fa[u][i];
        }
        return u;
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    KruTree adj(n);
    vector<array<int, 3>> e(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v, 0};
    }
    vector<array<int, 2>> Q(q);
    for (int i = 0; i < q; i++)
    {
        int op, idx;
        cin >> op >> idx;
        Q[i] = {op, idx};
        if (op == 2)
        {
            e[idx][2] = -1;
        }
    }
    int p = 0;
    for (int i = 1; i <= m; i++)
    {
        if (e[i][2] != -1)
            e[i][2] = ++p;
    }
    for (int i = q - 1; i >= 0; i--)
    {
        auto [op, pos] = Q[i];
        if (op == 2)
            e[pos][2] = ++p;
    }
    for (auto [u, v, w] : e)
        adj.add(u, v, w);
    adj.work();
    SegTree t(n + 1);
    auto &rk = adj.rk;
    for (int i = 1; i <= n; i++)
    {
        int v = a[rk[i]];
        t.modify(i, v, i);
    }
    int lim = p;
    for (int i = 0; i < q; i++)
    {
        auto [op, pos] = Q[i];
        if (op == 1)
        {
            int rt = adj.jump(pos, lim);
            auto [l, r] = adj.q[rt];
            auto [val, u] = t.query(l, r + 1);
            cout << val << '\n';
            t.modify(u, 0, u);
        }
        else
            lim--;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}