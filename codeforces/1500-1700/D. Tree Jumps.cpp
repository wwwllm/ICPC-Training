#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2070/D
const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> f(n + 1), dp(n + 1), dph(n + 1);
    vector<vector<int>> d(n + 1), g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> f[i];
        g[f[i]].push_back(i);
    }
    queue<array<int, 2>> q;
    q.push({1, 1});
    while (q.size())
    {
        auto [u, h] = q.front();
        q.pop();
        d[h].push_back(u);
        for (auto v : g[u])
        {
            q.push({v, h + 1});
        }
    }
    dp[1] = 1;
    dph[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int res = 0;
        for (auto u : d[i])
        {
            dp[u] = dph[i - 1];
            dp[u] = (f[u] == 1 ? dp[u] : ((dp[u] - dp[f[u]] + mod) % mod));
            res = (res + dp[u]) % mod;
        }
        dph[i] = res;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % mod;
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