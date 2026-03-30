#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = i; j >= 1; j--)
        {
            if (a[j] > a[i])
            {
                res += pre[j];
                break;
            }
            else
                res += h - a[i];
        }
        pre[i] = res;
    }
    for (int i = n; i >= 1; i--)
    {
        int res = 0;
        for (int j = i; j <= n; j++)
        {
            if (a[j] > a[i])
            {
                res += suf[j];
                break;
            }
            else
            {
                res += h - a[i];
            }
        }
        suf[i] = res;
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = pre[i] + suf[i] - (h - a[i]);
        cerr << i << ' ' << dp[i] << '\n';
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int ma = i;
        for (int j = i; j <= n; j++)
        {
            if (a[j] > a[ma])
                ma = j;
            ans = max(ans, dp[i] + dp[j] - dp[ma]);
        }
    }
    cout << ans << '\n';
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