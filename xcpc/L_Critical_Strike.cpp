#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3588
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    ranges::sort(a);
    vector<double> dp(m + 1);
    for (int i = 0; i < n; i++)
    {
        auto [v, p, w] = a[i];
        for (int j = m; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] * (100.0 - p) / 100.0 + 1.0 * p * v / 100);
        }
    }
    double ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(ans, dp[i]);
    cout << fixed << setprecision(9) << ans << '\n';
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