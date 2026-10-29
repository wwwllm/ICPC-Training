#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<array<int, 2>>());
    int root = 1;
    vector<int> d(n + 1);
    int W = 0;
    vector<int> fa(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        W = max(W, w);
        d[u]++, d[v]++;
    }
    d[root]++;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        fa[u] = f;
        for (auto [v, w] : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1)
            q.push(i);
    }
    vector dp(n + 1, vector<int>(2 * W + 1, inf));
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (int val = 0; val <= 2 * W; val++)
        {
            int res = val;
            for (auto [v, w] : adj[u])
            {
                if (v == fa[u])
                    continue;
                int tmp = 1e9;
                if (val - w >= 0)
                    tmp = min(tmp, dp[v][val - w]);
                if (val + w <= 2 * W)
                    tmp = min(tmp, dp[v][val + w]);
                res = max(res, tmp);
                
            }
            dp[u][val] = min(dp[u][val], res);
        }
        d[fa[u]]--;
        if (d[fa[u]] == 1)
            q.push(fa[u]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << *ranges::min_element(dp[i]) << " \n"[i == n];
    }
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