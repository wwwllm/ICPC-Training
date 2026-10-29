#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    ranges::sort(a), ranges::sort(b);
    int ans = 0;
    for (int t = 1; t <= 500; t++)
    {
        vector<int> c(m), dp(m + 1);
        for (int i = 0, j = 0; i < m; i++)
        {
            while (j < m && a[j] <= b[i] - t)
                j++;
            c[i] = j;
        }
        if (c[m - 1] == 0)
            continue;
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                (dp[j] += dp[j - 1] * max(0LL, c[i] - j + 1) % mod) % mod;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            (ans += dp[i]) %= mod;
        }
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
    return 0;
}