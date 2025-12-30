#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(n + 1);
    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        int pos = lower_bound(p[x].begin(), p[x].end(), i) - p[x].begin();
        if (pos + 1 >= x)
        {
            int j = pos - x + 1;
            dp[i] = max(dp[p[x][j] - 1] + x, dp[i - 1]);
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n] << '\n';
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