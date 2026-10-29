#include <bits/stdc++.h>
#define int long long
using namespace std;

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
const int inf = 1e18;
int mod;
struct Info
{
    int sum;
    int size;
    Info() : sum(), size(0) {};
    Info(int value) : sum(value), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.size = size + other.size;
        res.sum %= mod;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v)
    {
        (tag[p] += v) %= mod;
        (info[p].sum += v * info[p].size % mod) %= mod;
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
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
        push(p);
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 区间修改[x,y)
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeAdd(p << 1, l, mid, x, y, v);
        rangeAdd(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        push(p);
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
    int n, q, r;
    cin >> n >> q >> r >> mod;
    r--;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    HLD adj(n, r);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.add(u, v);
    }
    adj.work();
    auto &rnk = adj.rnk;
    auto &dfn = adj.dfn;
    SegTree t(n);
    for (int i = 0; i < n; i++)
        t.modify(dfn[i], a[i] % mod);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            auto p = adj.path(u, v);
            for (auto [l, r] : p)
            {
                t.rangeAdd(l, r + 1, w);
            }
        }
        else if (op == 2)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            auto p = adj.path(u, v);
            int res = 0;
            for (auto [l, r] : p)
            {
                (res += t.query(l, r + 1).sum) %= mod;
            }
            cout << res << '\n';
        }
        else if (op == 3)
        {
            int u, w;
            cin >> u >> w;
            u--;
            auto [l, r] = adj.subtree(u);
            t.rangeAdd(l, r + 1, w);
        }
        else
        {
            int u;
            cin >> u;
            u--;
            auto [l, r] = adj.subtree(u);
            cout << t.query(l, r + 1).sum << '\n';
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