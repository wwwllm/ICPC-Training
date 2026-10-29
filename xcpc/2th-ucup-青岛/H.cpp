#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i] - '0';
    }
    vector<array<int, 2>> dp(n + 1, {inf, inf});
    dp[n] = {0, 0};
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto op : {0, 1})
        {
            int now = a[i + 1] ^ op;
            if (now)
                dp[i][op] = dp[i + 1][op ^ 1] + (n - i) * 1;
            else
                dp[i][op] = dp[i + 1][op] + (n - i) * 2;
        }
        ans += min(dp[i][0], dp[i][1] + (n - i));
    }
    cout << ans << '\n';
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