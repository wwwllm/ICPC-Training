#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(2 * n + 2), suf(2 * n + 2);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        x = min(x, 2 * n + 1);
        vis[x] += 1;
        suf[x] += 1;
    }
    for (int i = 2 * n; i >= 1; i--)
        suf[i] += suf[i + 1];

    vector<int> dp(2 * n + 2);
    if (suf[2] == n)
    {
        cout << 0 << '\n';
        return;
    }
    dp[1] = 1;
    for (int i = 2; i <= 2 * n; i++)
    {
        vector<int> ndp(2 * n + 2);
        int mi = (i + 1) / 2;
        int ma = n - suf[i + 1];
        if (mi > ma)
        {
            cout << 0 << '\n';
            return;
        }
        if (vis[i])
        {
            for (int j = mi; j <= ma; j++)
            {
                if (2 * (j - 1) >= i - 1)
                    ndp[j] = dp[j - 1];
            }
        }
        else
        {
            for (int j = mi; j <= ma; j++)
            {
                ndp[j] = dp[j];
                if (2 * (j - 1) >= i - 1)
                {
                    (ndp[j] += dp[j - 1]) %= mod;
                }
            }
        }
        dp = ndp;
    }
    int ans = dp[n];

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
