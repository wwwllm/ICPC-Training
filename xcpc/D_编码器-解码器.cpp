#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    vector dp(n + 1, vector(m + 1, vector<int>(m + 1)));
    for (int i = 1; i <= n; i++)
    {
        for (int len = 1; len <= m; len++)
        {
            for (int l = 1; l + len - 1 <= m; l++)
            {
                int r = l + len - 1;
                if (l != r)
                {
                    dp[i][l][r] = dp[i - 1][l][r] * 2 % mod;
                    for (int k = l; k < r; k++)
                    {
                        dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 1][r] % mod) % mod;
                    }
                    char c = s[i];
                    for (int j = l; j <= r; j++)
                    {
                        if (c == t[j])
                        {
                            if (j == l)
                                dp[i][l][r] = (dp[i][l][r] + dp[i - 1][j + 1][r]) % mod;
                            else if (j == r)
                                dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][j - 1]) % mod;
                            else
                                dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][j - 1] * dp[i - 1][j + 1][r] % mod) % mod;
                        }
                    }
                }
                else
                {
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][r] * 2 % mod) % mod;
                    if (s[i] == t[l])
                        dp[i][l][r]++, dp[i][l][r] %= mod;
                }
                // cerr << i << ' ' << l << ' ' << r << ' ' << dp[i][l][r] << '\n';
            }
        }
    }
    cout << dp[n][1][m] << '\n';
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