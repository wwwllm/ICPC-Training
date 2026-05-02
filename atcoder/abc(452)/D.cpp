#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    vector<int> dp(m + 1, 0);
    t = ' ' + t;
    int ans = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        vector<int> ndp(m + 1, 0);
        if (s[i] == t[1])
            ndp[1] = 1;
        else
            ndp[0] = 1;
        for (int j = 0; j <= m; j++)
        {
            if (t[j] == s[i])
                ndp[j] += dp[j - 1];
            if ((j < m && t[j + 1] != s[i]) || j == m)
                ndp[j] += dp[j];
        }
        dp = ndp;
        ans -= dp[m];
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
}