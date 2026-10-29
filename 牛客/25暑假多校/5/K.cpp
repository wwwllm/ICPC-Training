#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18, mod = 998244353;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> g(n + 1);
    vector<int> fa(n + 1);
    vector<int> dep(n + 1);
    vector<int> pos(m);
    vector<array<int, 2>> edge(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edge[i] = {u, v};
    }
    for (auto &x : pos)
        cin >> x;

    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        fa[u] = f;
        dep[u] = dep[f] + 1;
        for (auto [v, _] : g[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);

    vector<int> dp(1 << m, INF);
    vector<int> cnt(1 << m, 0);
    dp[0] = 0;
    cnt[0] = 1;

    auto lca = [&](int u, int v) -> int
    {
        int mask = 0;
        if (dep[u] < dep[v])
            swap(u, v);
        while (dep[u] > dep[v])
        {
            int f = fa[u];
            for (int i = 0; i < m; i++)
            {
                auto [x, y] = edge[pos[i]];
                if ((x == u && y == f) || (x == f && y == u))
                    mask |= (1LL << i);
            }
            u = f;
        }

        while (u != v)
        {
            int f = fa[u];
            for (int i = 0; i < m; i++)
            {
                auto [x, y] = edge[pos[i]];
                if ((x == u && y == f) || (x == f && y == u))
                    mask |= (1LL << i);
            }
            u = f;
            f = fa[v];
            for (int i = 0; i < m; i++)
            {
                auto [x, y] = edge[pos[i]];
                if ((x == v && y == f) || (x == f && y == v))
                    mask |= (1LL << i);
            }
            v = f;
        }
        return mask;
    };

    while (k--)
    {
        int s, t;
        cin >> s >> t;
        int mask = lca(s, t);
        auto ndp = dp;
        auto ncnt = cnt;
        for (int s = 0; s < (1 << m); s++)
        {
            if (dp[s] == INF)
                continue;
            int news = s | mask;
            if (dp[news] > dp[s] + 1)
            {
                ndp[news] = dp[s] + 1;
                ndp[news] %= mod;
                ncnt[news] = cnt[s];
            }
            else if (dp[news] == dp[s] + 1)
            {
                ncnt[news] = (ncnt[news] + cnt[s]) % mod;
            }
        }
        dp = ndp;
        cnt = ncnt;
    }
    if (dp[(1LL << m) - 1] == INF)
        cout << -1 << '\n';
    else
        cout << dp[(1LL << m) - 1] << ' ' << cnt[(1LL << m) - 1] << '\n';
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
