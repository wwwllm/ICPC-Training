#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<array<int, 2>> dp(n + 1);
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1] && a[i] >= b[i - 1] && b[i] >= a[i - 1])
        {
            dp[i][1] = dp[i - 1][1] * 2 % mod;
            dp[i][0] = dp[i - 1][0] * 2 % mod;
        }
        else if ((a[i] >= a[i - 1] && b[i] >= b[i - 1]) || (a[i] >= b[i - 1] && b[i] >= a[i - 1]))
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << (dp[n][1] + dp[n][0]) % mod << '\n';
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