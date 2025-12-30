#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));

    for (int i = 1; i <= n; i++)
    {
        auto tmp = dp;
        for (int k = 0; k <= n; k++)
        {
            tmp[a[i]][k] = (tmp[a[i]][k] + dp[a[i]][k]) % mod;
        }
        for (int j = 0; j <= n; j++)
        {
            tmp[j][a[i]] = (tmp[j][a[i]] + dp[j][a[i]]) % mod;
        }
        dp = tmp;
    }
    cout << dp[n][n] << '\n';
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