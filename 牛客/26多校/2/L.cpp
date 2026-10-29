#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector adj(n + 1, vector<int>()),
        radj(n + 1, vector<int>());
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                cnt++;
                adj[i - 1].push_back(j - 1);
                radj[j - 1].push_back(i - 1);
            }
        }
    }
    int ans = 0;
    vector<int> dp(1LL << n);
    dp[0] = 1;
    for (int st = 0; st < (1LL << n); st++)
    {
        for (int u = 0; u < n; u++)
        {
            if ((st >> u) & 1)
                continue;
            bool ok = 1;
            for (auto v : adj[u])
            {
                ok &= (st >> v) & 1;
            }
            if (ok)
            {
                (dp[st | (1LL << u)] += dp[st]) %= mod;
            }
        }
    }

    if (cnt)
        ans = (dp[(1LL << n) - 1] * 2) % mod;
    else
        ans = dp[(1LL << n) - 1];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}