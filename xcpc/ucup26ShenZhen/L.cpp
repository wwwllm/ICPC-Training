#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n);
    for (auto &[p, v, w] : a)
        cin >> p >> v >> w;
    ranges::sort(a, [&](auto &x, auto &y)
                 { return x[1] < y[1]; });
    vector<long double> dp(m + 1);
    for (auto [p, v, w] : a)
    {
        for (int cost = m; cost >= w; cost--)
        {
            dp[cost] = max(dp[cost], dp[cost - w] * (1.0 - p * 1.0 / 100) + 1.0 * p / 100 * v);
        }
    }
    cout << fixed << setprecision(12) << *ranges::max_element(dp) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}