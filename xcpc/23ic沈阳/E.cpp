#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vector dp(n + 1, vector<array<int, 2>>(m + 1, {inf, inf}));
    dp[n][m][0] = 0;
    queue<array<int, 3>> qu;
    qu.push({n, m, 0});
    while (qu.size())
    {
        auto [x, y, op] = qu.front();
        qu.pop();
        if (x == 0 && op == 1)
        {
            cout << dp[x][y][op] << '\n';
            return;
        }
        int nx = op ? n - x : x, ny = op ? m - y : y;
        for (int i = 0; i <= min(nx, p); i++)
        {
            for (int j = 0; j <= min(ny, p); j++)
            {
                int dx = nx - i, dy = ny - j;
                if (i + j > p)
                    continue;
                if (dx > 0 && dy > dx + q)
                    continue;
                int xx = op ? n - dx : dx, yy = op ? m - dy : dy;
                if (dp[xx][yy][!op] == inf)
                {
                    dp[xx][yy][!op] = dp[x][y][op] + 1;
                    qu.push({xx, yy, !op});
                }
            }
        }
    }
    cout << -1 << '\n';
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