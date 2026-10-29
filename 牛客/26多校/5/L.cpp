#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    if (n * m <= 2)
    {
        bool ok = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ok &= g[i][j] == g[1][1];
            }
        }
        if (ok)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    if (n == 1 || m == 1)
    {
        bool ok = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ok &= g[i][j] == g[1][1];
            }
        }
        if (ok)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    vector<int> sum(n + m + 1);
    int tar = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i + j] += g[i][j];
        }
    }
    int t = sum[3] - sum[2];

    vector dp(n + 1, vector<int>(m + 1));
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = t - g[i][j];
            if (dp[i][j] < 0)
                ok = 0;
        }
    }

    auto req = dp;
    req[1][1] = 0;
    for (int i = 2; i <= n + m; i++)
    {
        for (int x = 1; x <= n; x++)
        {
            int y = i - x;
            if (y > m || y < 1)
                continue;
            ok &= req[x][y] == 0;
            if (dp[x][y] == 0)
                continue;
            if (y + 1 <= m)
            {
                int cnt = min(dp[x][y], req[x][y + 1]);
                dp[x][y] -= cnt;
                req[x][y + 1] -= cnt;
            }
            if (x + 1 <= n)
            {
                int cnt = min(dp[x][y], req[x + 1][y]);
                dp[x][y] -= cnt;
                req[x + 1][y] -= cnt;
            }
            if (x != n || y != m)
                ok &= dp[x][y] == 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ok &= req[i][j] == 0;
        }
    }
    cout << (ok ? t - g[1][1] : -1) << '\n';
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