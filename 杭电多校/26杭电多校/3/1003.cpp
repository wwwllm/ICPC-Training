#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128;
const int inf = 4e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector dp(n + 1, vector<int>(62, inf));
    dp[0][0] = 0;
    vector<int> mi(62, inf);
    mi[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 61; l >= 1; l--)
        {
            int tmp = mi[l - 1];
            if (tmp <= a[i])
                dp[i][l] = tmp + a[i], mi[l] = min(mi[l], tmp + a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 1; l < 62; l++)
        {
            if (dp[i][l] != inf)
                ans = max(ans, l);
        }
    }
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