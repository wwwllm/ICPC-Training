#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int all = (1LL << 4);
    int tar = 0;
    for (int i = 2; i <= n; i++)
    {
        int u = ((s[i - 1] - '0') << 1) + (s[i] - '0');
        tar |= (1LL << u);
    }
    vector dp(n + 1, vector(all, array<int, 2>{inf, inf}));
    dp[1][0][s[1] - '0'] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        int u = s[i] - '0';
        dp[i][0][u] = min(1LL, dp[i][0][u]);
        for (int mask = 0; mask < all; mask++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (dp[i - 1][mask][j] == inf)
                    continue;
                int st = (j << 1) + u;
                int nmask = mask | (1 << st);
                dp[i][nmask][u] = min(dp[i][nmask][u], dp[i - 1][mask][j] + 1);
            }
        }
    }
    cout << min(dp[n][tar][0], dp[n][tar][1]) << '\n';
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
