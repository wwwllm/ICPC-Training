#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2052/F
void solve()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    vector<array<int, 3>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == '#' && b[i] == '#')
        {
            dp[i][0] = dp[i - 1][0];
        }
        else if (a[i] == '.' && b[i] == '#')
        {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = dp[i - 1][1];
        }
        else if (a[i] == '#' && b[i] == '.')
        {
            dp[i][2] = dp[i - 1][0];
            dp[i][0] = dp[i - 1][2];
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][2];
            dp[i][2] = dp[i - 1][1];
            if (i > 1 && a[i - 1] == '.' && b[i - 1] == '.')
                dp[i][0] += dp[i - 2][0];
        }
        dp[i][0] = min(dp[i][0], 2LL);
    }
    if (dp[n][0] == 0)
        cout << "None\n";
    else if (dp[n][0] == 1)
        cout << "Unique\n";
    else
        cout << "Multiple\n";
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