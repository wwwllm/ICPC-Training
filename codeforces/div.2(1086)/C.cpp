#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> c[i] >> x;
        p[i] = (1.0 - (double)x / 100.0);
    }
    vector<double> dp(n + 1);
    dp[n] = c[n];
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = max(dp[i + 1], dp[i + 1] * p[i] + c[i]);
    }
    cout << fixed << setprecision(10) << dp[1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}