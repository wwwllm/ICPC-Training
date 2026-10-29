#include <bits/stdc++.h>
#define int long long

using namespace std;

// dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-10]
int dp[15][100];
void init()
{
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i < 15; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            for (int k = 0; k < 10; k++)
                if (j - k > 0)
                    dp[i][j] += dp[i - 1][j - k];
        }
    }
}
void solve()
{
    int k;
    cin >> k;
    int ans = 0;
    if (k >= 100)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i <= 10; i++)
        ans += dp[i][k];
    if (k == 1)
        ans += dp[11][k];
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}