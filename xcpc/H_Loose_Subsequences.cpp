#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105945
const int inf = 1e18, mod = 998244353;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    vector<int> pre(26), sum(n + 1), dp(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f[i] = pre[a[i]];
        pre[a[i]] = i;
    }
    for (int i = 1; i <= min(n, k + 1); i++)
    {
        dp[i] = !f[i];
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= mod;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i + k + 1 <= n)
        {
            dp[i + k + 1] = sum[i] - sum[max(0LL, f[i + k + 1] - k - 1)] + !f[i + k + 1] + mod;
            dp[i + k + 1] %= mod;
            sum[i + k + 1] = sum[i + k] + dp[i + k + 1];
            sum[i + k + 1] %= mod;
        }
    }
    cout << sum[n] << '\n';
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