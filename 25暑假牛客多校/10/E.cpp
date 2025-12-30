#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (m == 1)
    {
        int ans = 0;
        int M = *max_element(a.begin() + 1, a.end());
        vector<int> d(n + 2);
        for (int i = 1; i <= n; i++)
        {
            d[i] = M - a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (d[i] > d[i - 1])
                ans += d[i] - d[i - 1];
        }
        cout << ans << '\n';
    }
    else
    {
        int M = *max_element(a.begin() + 1, a.end());
        int N = *min_element(a.begin() + 1, a.end());
        int res = 1e18;
        for (int l = N; l <= 200; l++)
        {
            for (int r = M; r <= 200; r++)
            {
                if (l > r)
                    continue;
                vector<array<int, 2>> dp(n + 1, {-1, -1});
                dp[1][1] = r - a[1];
                dp[1][0] = l < a[1] ? -1 : l - a[1];
                for (int i = 2; i <= n; i++)
                {
                    if (a[i] <= l)
                    {
                        int cnt0 = 0, cnt1 = 0;
                        if (dp[i - 1][0] != -1)
                        {
                            cnt0 = max(0LL, a[i - 1] - a[i]);
                        }
                        cnt1 = l - a[i] - (r - a[i - 1]);
                        cnt1 = max(0LL, cnt1);
                        if (dp[i - 1][0] == -1)
                        {
                            dp[i][0] = dp[i - 1][1] + cnt1;
                        }
                        else
                            dp[i][0] = min(dp[i - 1][1] + cnt1, dp[i - 1][0] + cnt0);
                    }
                    int cnt0 = 0, cnt1 = 0;
                    if (dp[i - 1][0] != -1)
                    {
                        cnt0 = r - a[i] - (l - a[i - 1]);
                        cnt0 = max(0LL, cnt0);
                    }
                    cnt1 = r - a[i] - (r - a[i - 1]);
                    cnt1 = max(0LL, cnt1);
                    if (dp[i - 1][0] == -1)
                    {
                        dp[i][1] = dp[i - 1][1] + cnt1;
                    }
                    else
                        dp[i][1] = min(dp[i - 1][1] + cnt1, dp[i - 1][0] + cnt0);
                }
                res = min(res, dp[n][1]);
                if (dp[n][0] != -1)
                {
                    res = min({dp[n][0], res});
                }
            }
        }
        cout << res << '\n';
    }
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