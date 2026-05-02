#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e18, mod = 998244353;
struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
        int k;
    };
    vector<int> root;
    int tot;
    int n; // 值域
    vector<Node> info;
    SegTree(int n, int nodes, int ver) : n(n), tot(0)
    {
        info.assign(nodes, {0, 0, 0, 0});
        root.assign(ver + 1, 0);
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = max(info[l].cnt, info[r].cnt);
        info[p].k = 0;
        if (info[p].cnt == info[l].cnt)
            info[p].k += info[l].k;
        if (info[p].cnt == info[r].cnt)
            info[p].k += info[r].k;
    }

    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];

        if (r - l == 1)
        {
            info[p].cnt += v;
            info[p].k = info[p].cnt > 0 ? 1 : 0;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int ver, int pre_ver, int x, int v = 1)
    {
        modify(root[ver], root[pre_ver], 0, n, x, v);
    }

    int merge(int p, int q, int l, int r)
    {
        if (!p || !q)
            return p | q;

        int rt = p;

        if (r - l == 1)
        {
            info[rt].cnt = info[p].cnt + info[q].cnt;
            info[rt].k = info[rt].cnt > 0 ? 1 : 0;
            return rt;
        }
        int mid = l + r >> 1;
        info[rt].l = merge(info[p].l, info[q].l, l, mid);
        info[rt].r = merge(info[p].r, info[q].r, mid, r);
        pull(rt);
        return rt;
    }
    void merge_ver(int new_ver, int u, int v)
    {
        root[new_ver] = merge(root[u], root[v], 0, n);
    }
};
void solve()
{
    int n, m, f;
    ll seed;
    cin >> n >> seed >> m >> f;
    vector<ll> q(m + 1), d(m + 1), c(n + 1);
    for (int i = 2; i <= m; i++)
        cin >> q[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];
    vector adj(n + 1, vector<int>());
    vector<int> p(n + 1, 0);
    int root = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= m)
        {
            p[i] = q[i];
            adj[p[i]].push_back(i);
        }
        else
        {
            p[i] = seed % (i - 1) + 1;
            adj[p[i]].push_back(i);
            seed = (seed * 1103515245 + 12345) % (1LL << 31);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i <= m)
        {
            c[i] = d[i];
        }
        else
        {
            c[i] = seed % (f) + 1;
            seed = (seed * 1103515245 + 12345) % (1LL << 31);
        }
    }
    SegTree t(n + 1, n * 24, n + 1);
    for (int i = 1; i <= n; i++)
    {
        t.modify(i, 0, c[i], 1);
    }
    ll ans = 0;
    auto dfs = [&](auto &&self, int u) -> void
    {
        for (auto v : adj[u])
        {
            self(self, v);
            t.merge_ver(u, u, v);
        }
        int rt = t.root[u];
        auto p = t.info[rt];
        (ans += 1LL * (p.cnt ^ u) * (p.k ^ u) % mod) %= mod;
    };
    dfs(dfs, 1);
    cout << ans << '\n';
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