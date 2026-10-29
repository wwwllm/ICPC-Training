#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int N = (1 << n);
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    vector<int> p3(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        p3[i] = p3[i - 1] * 3;
    }
    vector<int> dp(p3[n]);
    for (int mask = 0; mask < N; mask++)
    {
        int st = 0;
        for (int bit = 0; bit < n; bit++)
        {
            st += p3[bit] * (mask >> bit & 1);
        }
        dp[st] = a[mask];
    }
    for (int bit = 0; bit < n; bit++)
    {
        for (int st = 0; st < p3[n - 1]; st++)
        {
            int x = st % p3[bit] + 2 * p3[bit] + st / p3[bit] * p3[bit] * 3;
            int y = st % p3[bit] + 1 * p3[bit] + st / p3[bit] * p3[bit] * 3;
            int z = st % p3[bit] + st / p3[bit] * p3[bit] * 3;
            dp[x] = dp[y] + dp[z];
        }
    }
    int ans = 0;
    for (int i = 0; i < p3[n]; i++)
    {
        ans ^= dp[i];
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