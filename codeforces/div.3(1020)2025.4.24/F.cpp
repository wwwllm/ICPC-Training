#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 2>> dp(n);
    if (s[0] == '0')
        dp[0] = {0, n - 1};
    else
        dp[0] = {1, 0};
    int ans = max(dp[0][1], dp[0][0]);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            auto [n1, n2] = dp[i - 1];
            dp[i] = {n1 + i, (n - i - 1 == 0 ? 0 : n2 + n - i - 1)};
        }
        else
        {
            auto [n1, n2] = dp[i - 1];
            dp[i] = {n2 + 1, 0};
        }
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << endl;
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