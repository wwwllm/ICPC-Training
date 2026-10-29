#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> siz(n + 1), sum(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        siz[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            siz[u] += siz[v];
            sum[u] += sum[v] + w;
        }
    };
    dfs(dfs, 1, 0);
    vector dp(n + 1, vector<array<int, 3>>(2 * n, {-inf, -inf, -inf}));
    auto dfs1 = [&](auto &&self, int u, int fa) -> void
    {
        dp[u][0][0] = 0;
        for (auto [v, w] : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            for (int i = 2 * n - 2; i >= 0; i--)
            {
                for (int c = 2; c >= 0; c--)
                {
                    if (dp[u][i][c] == -inf)
                        continue;

                    int ni = i + 2 * siz[v];
                    if (ni <= 2 * n - 2)
                    {
                        int cost = dp[u][i][c] + 2 * (sum[v] + w);
                        dp[u][ni][c] = max(dp[u][ni][c], cost);
                    }

                    if (c < 2)
                    {
                        int lim = min(2 * n - 2 - i - 1, 2 * siz[v] - 2);
                        for (int x = 0; x <= lim; x++)
                        {
                            int val =
                                max(dp[v][x][0],
                                    dp[v][x][1]);
                            if (val == -inf)
                                continue;
                            int ni = i + x + 1;
                            int cost = dp[u][i][c] + val + w;
                            dp[u][ni][c + 1] = max(dp[u][ni][c + 1], cost);
                        }
                    }
                }
            }
        }
    };
    dfs1(dfs1, 1, 0);
    int tot = 2 * sum[1];
    for (int k = 0; k <= 2 * n - 2; k++)
    {
        int d = -inf;
        for (int u = 1; u <= n; u++)
        {
            d = max(d, *ranges::max_element(dp[u][k]));
        }
        cout << tot - d << " \n"[k == 2 * n - 2];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}