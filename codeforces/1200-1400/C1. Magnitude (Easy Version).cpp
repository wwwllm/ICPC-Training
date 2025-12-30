#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/1984/C1
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<array<ll, 2>> dp(n);
    for (auto &ele : a)
        cin >> ele;
    dp[0] = {abs(a[0]), a[0]};
    for (int i = 1; i < n; i++)
    {
        dp[i][1] = dp[i - 1][1] + a[i];
        dp[i][0] = max(abs(dp[i - 1][0] + a[i]), abs(dp[i - 1][1] + a[i]));
    }
    cout << dp[n - 1][0] << '\n';
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