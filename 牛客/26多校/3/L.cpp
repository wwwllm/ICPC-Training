#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector<int>(m + 1, -1));
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector h(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    }
    auto dfs = [&](auto &&self, int x, int y) -> int
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        bool ok = 0;
        bool flag = 0;
        for (auto [dx, dy] : walk)
        {
            int xx = dx + x, yy = dy + y;
            int res = 0;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && h[xx][yy] > h[x][y])
            {

                res = self(self, xx, yy);
                ok = 1;
                flag |= res;
            }
        }
        if (!ok)
            dp[x][y] = 1;
        else
            dp[x][y] = !flag;
        return dp[x][y];
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] == -1)
                dfs(dfs, i, j);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cerr << dp[i][j] << " \n"[j == m];
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ok = dp[x][y];
        cout << (!ok ? "First\n" : "Second\n");
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}