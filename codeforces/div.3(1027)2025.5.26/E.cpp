#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 2>> dp(n + 1, {INF, INF});
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp[1][0] = a[1];
    dp[1][1] = a[1];
    auto dfs = [&](auto &&self, int u)->void
    {
        for (auto v : g[u])
        {
            if (dp[v][0] > INF / 2 && dp[v][1] > INF / 2)
            {
                dp[v][0] = max(a[v] - dp[u][1], a[v]);
                dp[v][1] = min(a[v] - dp[u][0], a[v]);
                self(self, v);
            }
            else
                continue;
        }
    };
    dfs(dfs, 1);
    for (int i = 1; i <= n; i++)
        cout << dp[i][0] << " \n"[i == n];
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