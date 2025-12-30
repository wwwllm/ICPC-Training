#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), dep(n + 1), f(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> p[i], f[p[i]] = 1;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        g[p[i]].pb(i);
    }

    int d = n;
    auto dfs = [&](auto &&self, int u) -> void
    {
        dep[u] = dep[p[u]] + 1;
        if (f[u] == 0)
            d = min(dep[u], d);
        for (auto v : g[u])
            self(self, v);
    };
    dfs(dfs, 1);

    vector<int> cnt(d + 1);
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] <= d)
            cnt[dep[i]]++;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    int sum = 0;
    for (int i = 1; i <= d; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            dp[j + cnt[i]] |= dp[j];
        }
        sum += cnt[i];
    }
    if (sum <= k || sum <= n - k)
    {
        cout << d << '\n';
        return;
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[i])
        {
            if (i <= k && sum - i <= n - k)
            {
                cout << d << '\n';
                return;
            }
        }
    }
    cout << d - 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}