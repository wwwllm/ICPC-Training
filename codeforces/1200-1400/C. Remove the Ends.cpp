#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2064/C
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += a[i] > 0 ? a[i] : 0;
        if (a[i] < 0)
            dp[i] = res;
        else
            dp[i] = res;
    }
    vector<int> f(n + 1, 0);
    res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res += a[i] < 0 ? -1 * a[i] : 0;
        if (a[i] < 0)
            f[i] = res;
        else
            f[i] = res;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i] + f[i]);
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