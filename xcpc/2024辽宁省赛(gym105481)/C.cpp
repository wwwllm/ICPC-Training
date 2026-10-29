#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1), out(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i] >> a[i];
        out[f[i]]++;
        adj[f[i]].push_back(i);
    }
    vector<int> sum(n + 1, 0);
    auto dfs = [&](auto &&self, int u, int f) -> int
    {
        if (out[u] == 0)
            return a[u];
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            int res = self(self, v, u);
            sum[u] += res;
        }
        return sum[u];
    };
    dfs(dfs, 0, -1);
    multiset<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (out[i])
            s.insert(a[i]);
    }
    if (sum[0] > 2200)
    {
        cout << "NO\n";
        return;
    }
    vector<int> ans(n + 1);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (out[i])
        {
            auto tmp = s.lower_bound(sum[i]);
            if (!s.count(*tmp))
            {
                ok = 0;
                break;
            }
            ans[i] = *tmp;
            s.erase(tmp);
            if (ans[i] < sum[i])
                ok = 0;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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