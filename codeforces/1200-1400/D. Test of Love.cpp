#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1992/D
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = '0' + s;
    vector<int> dp(n + 2, INF);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i <= n && s[i] != 'C')
            dp[i] = 0;
        if (i > n)
            dp[n + 1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'W')
        {
            if (i < n && s[i + 1] != 'C')
                dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
            if (i == n)
                dp[n + 1] = min(dp[i] + 1, dp[n + 1]);   
        }
        else if (s[i] == 'L')
        {
            for (int j = 1; j <= m; j++)
            {
                if (i + j <= n && s[i + j] != 'C')
                    dp[i + j] = min(dp[i], dp[i + j]);
                if (i + j > n)
                    dp[n + 1] = min(dp[i], dp[n + 1]);
            }
        }
    }
    if (dp[n + 1] <= k)
        cout << "YES\n";
    else
        cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}