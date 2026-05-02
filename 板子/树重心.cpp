#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n + 1), dp(n + 1), dep(n + 1, -1);
    dp[0] = 1e9;
    vector<int> ans;
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        dep[u] = dep[f] + 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        dp[1] += dep[u];
    };
    dfs1(dfs1, 1, 0);
    auto dfs2 = [&](auto &&self, int u, int f) -> void
    {
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            dp[v] = dp[u] + n - 2 * sz[v];
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    cout << ranges::min_element(dp) - dp.begin() << ' ' << *ranges::min_element(dp) << '\n';
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