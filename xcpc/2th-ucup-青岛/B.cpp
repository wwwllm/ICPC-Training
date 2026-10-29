#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct LCA
{
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<array<int, 2>>> adj;

    LCA(int n) : n(n), l(__lg(n) + 1), d(n + 1), f(n + 1, vector<int>(l, 0)), adj(n + 1) {}

    void add(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void work(int rt = 1)
    {
        dfs(rt, 0);
    }

    void dfs(int u, int fa)
    {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (auto [v, w] : adj[u])
        {
            if (v != fa)
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
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    int dist(int u, int v)
    {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> red(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        red[x] = 1;
    }
    LCA lca(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        lca.add(u, v, w);
    }
    lca.work();
    vector<int> dp(n + 1);
    auto &adj = lca.adj;
    vector<int> dep(n + 1);
    auto dfs = [&](auto &&self, int u, int f, int cost) -> void
    {
        dep[u] = dep[f] + cost;
        if (red[u])
            dp[u] = 0;
        else
            dp[u] = dp[f] + cost;
        for (auto [v, w] : adj[u])
        {
            if (f == v)
                continue;
            self(self, v, u, w);
        }
    };
    dfs(dfs, 1, 0, 0);
    vector<int> p;
    while (q--)
    {
        int k;
        cin >> k;
        p.assign(k, 0);
        for (int i = 0; i < k; i++)
        {
            cin >> p[i];
        }
        if (k == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        ranges::sort(p, [&](int u, int v)
                     { return dp[u] > dp[v]; });
        int ans = dp[p[1]];
        if (ans == 0)
        {
            cout << ans << '\n';
            continue;
        }
        int cur = p[0];
        int mx = dep[p[0]];
        for (int i = 1; i < k; i++)
        {
            cur = lca.query(cur, p[i]);
            mx = max(mx, dep[p[i]]);
            int L = mx - dep[cur];
            int R = 0;
            if (i + 1 < k)
                R = dp[p[i + 1]];
            ans = min(ans, max(L, R));
        }
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