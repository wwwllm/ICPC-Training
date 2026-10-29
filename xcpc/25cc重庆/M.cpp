#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a);
        a *= a;
        b >>= 1;
    }
    return ans;
}
struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
    };
    vector<int> root;
    int tot;
    int n;
    vector<Node> info;
    SegTree(int n, int cnt) : n(n), tot(0)
    {
        info.assign(cnt, {0, 0, 0});
        root.assign(N + 1, 0);
        tot = 0;
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = info[l].cnt + info[r].cnt;
    }

    void modify(int &p, int l, int r, int x, int v)
    {
        if (!p)
            p = ++tot;
        if (r - l == 1)
        {
            info[p].cnt += v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int p, int x, int v)
    {
        return modify(root[p], 0, n, x, v);
    }

    int query(int p, int l, int r, int x, int y)
    {
        if (!p || l >= y || r <= x)
        {
            return 0;
        }
        if (l >= x && r <= y)
        {
            return info[p].cnt;
        }
        int mid = l + r >> 1;
        return query(info[p].l, l, mid, x, y) + query(info[p].r, mid, r, x, y);
    }
    int query(int p, int x, int y)
    {
        return query(root[p], 0, n, x, y);
    }
};
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
void solve()
{
    int n;
    cin >> n;
    vector<int> val(n + 1);
    cin >> val[1];
    vector<array<int, 3>> op(n + 1);
    HLD adj(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        int a, u, v;
        cin >> a >> u >> v;
        op[i] = {a, u, v};
        adj.add(i, v);
    }
    adj.work();
    SegTree t(n + 1, (n + 1) * 30);
    auto &dfn = adj.dfn;
    auto calc = [&](int x, vector<array<int, 2>> &path)
    {
        int res = 1;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                int cnt = 0;
                while (x % i == 0)
                    cnt++, x /= i;
                int d = 0;
                for (auto [l, r] : path)
                {
                    d += t.query(i, l, r + 1);
                }
                cnt = max(0LL, cnt - d);
                res *= exp(i, cnt);
            }
        }
        if (x != 1)
        {
            int d = 0;
            for (auto [l, r] : path)
            {
                d += t.query(x, l, r + 1);
            }
            int cnt = max(0LL, 1 - d);
            res *= (cnt == 0 ? 1 : x);
        }
        return res;
    };
    auto add = [&](int u, int x)
    {
        int pos = dfn[u];
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                int cnt = 0;
                while (x % i == 0)
                    cnt++, x /= i;
                t.modify(i, pos, cnt);
            }
        }
        if (x != 1)
            t.modify(x, pos, 1);
    };
    add(1, val[1]);
    for (int i = 2; i <= n; i++)
    {
        auto [a, u, v] = op[i];
        auto path = adj.path(u, v);
        val[i] = calc(a, path);
        add(i, val[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << val[i] << " \n"[i == n];
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