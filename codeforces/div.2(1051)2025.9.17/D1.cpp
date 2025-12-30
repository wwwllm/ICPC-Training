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
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        auto tmp = dp;
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                
                if (dp[j][k] == 0)
                    continue;
                if (a[i] >= j)
                {
                    tmp[a[i]][k] = (tmp[a[i]][k] + dp[j][k]) % mod;
                }
                else if (a[i] >= k)
                {
                    tmp[j][a[i]] = (tmp[j][a[i]] + dp[j][k]) % mod;
                }
            }
        }
        dp = tmp;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            ans = (ans + dp[i][j]) % mod;
        }
    }
    cout << ans << '\n';
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