#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ranges::sort(a);
    vector<int> dp(n + 1, inf);
    for (int i = 0; i < n; i++)
        dp[a[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n / j; j++)
        {
            if (i % j == 0)
            {
                dp[i] = min(dp[i], dp[i / j] + dp[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] >= inf)
            cout << -1 << " \n"[i == n];
        else
            cout << dp[i] << " \n"[i == n];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}