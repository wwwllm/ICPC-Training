#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<int> R(n + 1), L(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != s[i - 1])
            L[i] = i - 1;
        else
            L[i] = L[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == n || s[i] != s[i + 1])
            R[i] = i + 1;
        else
            R[i] = R[i + 1];
    }
    vector dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 4; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;

            if (i + 1 <= n)
                dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            if (j - 1 >= 1)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (s[i] == s[j])
            {
                int ir = R[i];
                int jl = L[j];
                if (ir < jl)
                {
                    int len = 4;
                    if (ir + 1 < jl - 1)
                        len += dp[ir + 1][jl - 1];
                    dp[i][j] = max(dp[i][j], len);
                }
            }
        }
    }
    int l = -1, r = -1;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == '(')
        {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            r = i;
            break;
        }
    }
    if (l < r && l != -1 && r != -1)
        cout << 2 + dp[l + 1][r - 1] << '\n';
    else
        cout << 0 << '\n';
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