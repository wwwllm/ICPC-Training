#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = p;
        if (a[i])
            p = i;
    }
    vector<int> dp(n + 1), sum(n + 1);
    dp[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int j = pre[i];
        int s = a[i];
        while (j && !(s & a[j]))
        {
            s |= a[j];
            j = pre[j];
        }
        dp[i] = sum[i - 1] - (j ? sum[j - 1] : 0);
        dp[i] = (dp[i] + mod) % mod;
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= mod;
    }
    cout << dp[n] << '\n';
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