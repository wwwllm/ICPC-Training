#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dp(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> int
    {
        int d = 0;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            d = max(d, self(self, v, u));
            d = max(d, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
        return d;
    };

    cout << dfs(dfs, 1, 0) << '\n';
    return 0;
}