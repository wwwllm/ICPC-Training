#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<array<int, 4>> dp(30);
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < 30; k++)
        {
            int val = (a[i] >> k) & 3;
            dp[k][val]++;
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int op, x;
        cin >> op >> x;
        vector<array<int, 4>> ndp(30);
        for (int k = 0; k < 30; k++)
        {
            int val = (x >> k) & 3;
            for (int i = 0; i < 4; i++)
            {
                int j;
                if (op == 1)
                    j = val & i;
                else if (op == 2)
                    j = val | i;
                else
                    j = val ^ i;
                ndp[k][j] += dp[k][i];
            }
        }
        dp = ndp;
        int res = 0;
        for (int k = 0; k < 30; k++)
        {
            res += dp[k][1];
        }
        cout << res << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}