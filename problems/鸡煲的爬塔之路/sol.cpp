#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, h, s;
    cin >> n >> m >> h >> s;
    vector adj(n + 1, vector<array<int, 2>>());
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector dp(n + 1, vector<int>(h + 1, -inf));
    dp[s][0] = V[s];
    for (int i = 0; i <= h; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            if (dp[u][i] == -inf)
                continue;
            for (auto [v, w] : adj[u])
            {
                if (i + w >= h)
                    continue;
                dp[v][i + w] = max(dp[v][i + w], dp[u][i] + V[v]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= h; i++)
        ans = max(ans, dp[s][i]);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}