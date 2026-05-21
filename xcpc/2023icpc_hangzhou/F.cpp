#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5, inf = 1e18;
struct LCA
{
    int n, l;
    vector<int> d, dep, val;
    vector<array<int, 20>> f;
    vector<vector<array<int, 2>>> adj;
    LCA(int n) : n(n), l(20), d(n + 1), dep(n + 1), val(n + 1), f(n + 1), adj(n + 1) {};
    void add(int u, int v, int l)
    {
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    void work(int rt = 1) { dfs(rt, 0); };
    void dfs(int u, int fa)
    {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for (auto [v, l] : adj[u])
        {
            if (v == fa)
                continue;
            dep[v] = dep[u] + l;
            val[v] = l;
            dfs(v, u);
        }
    }
    int query(int u, int v)
    {
        if (d[u] < d[v])
            swap(u, v);
        for (int i = l - 1; i >= 0; i--)
        {
            if (d[f[u][i]] >= d[v])
                u = f[u][i];
        }
        if (u == v)
            return u;
        for (int i = l - 1; i >= 0; i--)
        {
            if (f[u][i] != f[v][i])
            {
                u = f[u][i], v = f[v][i];
            }
        }
        return f[u][0];
    }
    int dis(int u, int v)
    {
        int lca = query(u, v);
        return dep[u] + dep[v] - 2 * dep[lca];
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    LCA adj(n);
    vector<int> mp(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        if (w > n)
            continue;
        mp[w] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        adj.add(u, v, l);
    }
    adj.work();
    vector<array<int, 3>> pre(n + 1, {-1, -1, inf});
    for (int i = 0; i <= n; i++)
    {
        if (mp[i] == -1)
            pre[i] = {-1, -1, inf};
        else
        {
            if (pre[i - 1][2] == inf && i >= 1)
                pre[i] = {-1, -1, inf};
            else
            {
                if (i == 0)
                    pre[i] = {mp[i], mp[i], 0};
                else
                {
                    int l = pre[i - 1][0], r = pre[i - 1][1], u = mp[i], d = pre[i - 1][2];
                    int dl = adj.dis(l, u), dr = adj.dis(r, u);
                    if (dl >= dr && dl > d)
                    {
                        r = u;
                        d = dl;
                    }
                    if (dr > dl && dr > d)
                    {
                        l = u;
                        d = dr;
                    }
                    pre[i] = {l, r, d};
                }
            }
        }
    }
    auto check = [&](int x, int u, int len) -> bool
    {
        if (x == -1)
            return 1;
        auto [l, r, d] = pre[x];
        if (d == inf)
            return 0;
        int dl = adj.dis(l, u), dr = adj.dis(r, u);
        return dl <= len && dr <= len;
    };
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int l = -1, r = n + 1;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (check(mid, x, k))
                l = mid;
            else
                r = mid;
        }
        cout << r << '\n';
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