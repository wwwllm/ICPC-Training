#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
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
        e.push_back({w, u, v});
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
            g[cur].push_back(fu);
            g[cur].push_back(fv);
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
struct Info
{
    int max, min, cnt;
    Info() : max(-inf), min(inf), cnt(0) {};
    Info(int dfn, int cnt) : max(dfn), min(dfn), cnt(cnt)
    {
        if (cnt == 0)
        {
            max = -inf;
            min = inf;
        }
    };
    Info operator+(const Info &other) const
    {
        Info res;
        res.max = std::max(max, other.max);
        res.min = std::min(min, other.min);
        res.cnt = cnt + other.cnt;
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
    void modify(int x, int v, int c)
    {
        modify(1, 0, n, x, Info(v, c));
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    KruTree adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.add(u, v, w);
    }
    adj.work();
    auto &g = adj.g;
    vector<int> dfn(g.size()), rnk(g.size());
    int tmp = 0;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        dfn[u] = tmp, rnk[tmp] = u;
        tmp++;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, adj.cur, -1);
    vector<array<int, 3>> Q(q);
    vector<array<int, 2>> pos;
    for (int i = 1; i <= n; i++)
    {
        pos.push_back({a[i], i});
    }
    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        int c, t, k;
        if (op == 1)
        {
            cin >> c >> t, Q[i] = {op, c, t};
            pos.push_back({t, c});
        }
        else
            cin >> k, Q[i] = {op, k, -1};
    }
    ranges::sort(pos, [&](const array<int, 2> &x, const array<int, 2> &y)
                 {
        if (x[0] != y[0]) return x[0] > y[0]; 
        return x[1] < y[1]; });
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    map<array<int, 2>, int> mp;
    for (int i = 0; i < pos.size(); i++)
    {
        mp[pos[i]] = i;
    }
    SegTree t(pos.size());
    for (int i = 0; i < pos.size(); i++)
    {
        t.modify(i, dfn[pos[i][1]], 0);
    }
    for (int i = 1; i <= n; i++)
    {
        t.modify(mp[{a[i], i}], dfn[i], 1);
    }
    auto find = [&](int x)
    {
        int l = -1, r = pos.size();
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            int cnt = t.query(0, mid + 1).cnt;
            if (cnt >= x)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        idx[i] = mp[{a[i], i}];
    }
    for (auto [op, c, k] : Q)
    {
        if (op == 1)
        {
            t.modify(idx[c], dfn[c], 0);
            t.modify(mp[{k, c}], dfn[c], 1);
            idx[c] = mp[{k, c}];
        }
        else if (op == 2)
        {
            int d = find(c);
            Info info = t.query(0, d + 1);
            int l = info.min, r = info.max;
            int u = rnk[l], v = rnk[r];
            cout << adj.lca(u, v) << '\n';
        }
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