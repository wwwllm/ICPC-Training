#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        adj[f[i]].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = n; i >= 1; i--)
    {
        dp[i] = 1;
        int mx1 = 0, mx2 = 0;
        for (auto v : adj[i])
        {
            if (dp[v] > mx1)
            {
                mx2 = mx1;
                mx1 = dp[v];
            }
            else if (dp[v] > mx2)
            {
                mx2 = dp[v];
            }
        }
        dp[i] = max(mx1, mx2 + 1);
    }
    cout << dp[1] << '\n';
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