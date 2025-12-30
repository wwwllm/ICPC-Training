#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]].push_back(i);
    }
    vector<int> s(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            s[i] = s[i - 1] + a[i];
        else
            s[i] = s[i - 1];
    }
    vector<array<int, 2>> dp(n + 1, {0, 0});
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i][0];
        int pos = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i) - mp[a[i]].begin();
        if (pos > 0)
        {
            int j = mp[a[i]][pos - 1];
            if (j == i - 1)
            {
                dp[i][0] = max(dp[i][0], dp[j][0] + a[i]);
                dp[i][1] = max(dp[i][1], dp[j][1] + a[i]);
            }
            else
            {
                dp[i][0] = max(dp[i][0], dp[j + 1][1] + a[i] + s[i - 1] - s[j + 1]);
                dp[i][1] = max(dp[i][1], dp[j + 1][0] + a[i] + s[i - 1] - s[j + 1]);
            }
        }
    }
    cout << max(dp[n][1], dp[n][0]) << '\n';
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