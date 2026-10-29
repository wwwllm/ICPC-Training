#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p2[i] = p2[i - 1] * 2 % mod;
    }
    vector<int> dp(n + 1), sz(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        dp[u] = sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            (dp[u] *= dp[v]) %= mod;
        }
        if (c[u] == 1)
            (dp[u] += p2[sz[u] - 1]) %= mod;
    };
    dfs(dfs, 1, 0);
    cout << dp[1] << '\n';
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