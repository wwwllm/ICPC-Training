#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    ranges::sort(b);
    vector<array<int, 2>> dp(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int sum = pre[b[i]] - pre[b[i - 1]];
        dp[i][1] = -sum + max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = sum + max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[m][0], dp[m][1]) + pre[n] - pre[b[m]] << '\n';
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