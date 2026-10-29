#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105143
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector dp(n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++)
    {
        int sl = 0, sr = 0;
        for (int j = 0; j <= 2 * n; j++)
        {
            if (i - j >= 1)
                sl += a[i - j];
            if (i + j <= n)
                sr += a[i + j];
            dp[i][j] = max(sl, sr);
        }
    }
    for (int j = 1; j <= 2 * n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i - 1 >= 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (i + 1 <= n)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            tmp ^= dp[i][j] * j;
        }
        ans ^= (tmp + i);
    }
    cout << ans << '\n';
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