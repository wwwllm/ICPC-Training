#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
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
    vector<int> pre(n + 1), ind(n + 1);
    vector<int> dep(n + 1);
    dep[0] = -1;
    int sum = 0;
    int root = 1;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        pre[u] = adj[u].size();
        ind[u] = adj[u].size();
        sum += ind[u];
        dep[u] = dep[f] + 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            pre[u] += pre[v];
        }
    };
    dfs(dfs, root, 0);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[root] += ind[i] * dep[i];
    }
    int res = dp[1];
    vector<int> point;
    auto f = [&](auto &&self, int u, int f) -> void
    {
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            dp[v] = dp[u] + sum - 2 * pre[v];
            res = min(res, dp[v]);
            self(self, v, u);
        }
    };
    f(f, root, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == res)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto u : ans)
        cout << u << ' ';
    cout << '\n';
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