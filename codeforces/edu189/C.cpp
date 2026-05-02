#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{

    int n;
    cin >> n;
    vector a(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'R')
            a[0][i] = 1;
        else
            a[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'R')
            a[1][i] = 1;
        else
            a[1][i] = 0;
    }
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + !(a[0][i] == a[1][i]));
        if (i - 2 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 2] + !(a[0][i] == a[0][i - 1]) + !(a[1][i] == a[1][i - 1]));
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