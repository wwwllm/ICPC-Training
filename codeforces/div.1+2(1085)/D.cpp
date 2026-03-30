#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, k, s;
    cin >> n >> k >> s;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dp(n + 1, inf);
    vector<int> res(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa)
    {
        if (adj[u].size() == 1)
        {
            res[u] = 1;
            dp[u] = 0;
            return;
        }
        int mi = inf, mii = inf;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            dfs(v, u);
            dp[u] = min(dp[u], dp[v] + 1);
            if (mi > dp[v])
            {
                mii = mi;
                mi = dp[v];
            }
            else if (mii > dp[v])
                mii = dp[v];
        }
        if (mi + mii <= k - 1)
            res[u] = 1, dp[u] = 0;
    };
    dfs(s, 0);
    cout << (res[s] ? "YES\n" : "NO\n");
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}