#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// https://codeforces.com/problemset/problem/2190/B2
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector dp(n + 2, vector<array<int, 4>>(n + 2));
    dp[0][0][0] = 1;
    for (auto c : s)
    {
        auto ndp = dp;
        if (c == '(')
        {
            for (int b = 0; b <= n; b++)
            {
                for (int len = 0; len < n; len++)
                {
                    ndp[b + 1][len + 1][0] += dp[b][len][0];
                    ndp[b + 1][len + 1][2] += dp[b][len][1];
                    ndp[b + 1][len + 1][3] += dp[b][len][2];
                    ndp[b + 1][len + 1][3] += dp[b][len][3];
                    ndp[b + 1][len + 1][0] %= mod;
                    ndp[b + 1][len + 1][2] %= mod;
                    ndp[b + 1][len + 1][3] %= mod;
                    ndp[b + 1][len + 1][3] %= mod;
                }
            }
        }
        else
        {
            for (int b = 1; b <= n; b++)
            {
                for (int len = 0; len < n; len++)
                {
                    ndp[b - 1][len + 1][1] += dp[b][len][0];
                    ndp[b - 1][len + 1][1] += dp[b][len][1];
                    ndp[b - 1][len + 1][2] += dp[b][len][2];
                    ndp[b - 1][len + 1][3] += dp[b][len][3];
                    ndp[b - 1][len + 1][1] %= mod;
                    ndp[b - 1][len + 1][1] %= mod;
                    ndp[b - 1][len + 1][2] %= mod;
                    ndp[b - 1][len + 1][3] %= mod;
                }
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for (int l = 2; l <= n; l++)
    {
        ans += dp[0][l][3] * (l - 2);
        ans %= mod;
    }
    cout << ans << '\n';
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