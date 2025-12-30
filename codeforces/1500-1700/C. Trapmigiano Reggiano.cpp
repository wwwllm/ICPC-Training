#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2071/C
void solve()
{
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> g(n + 1, vector<int>()), di(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1);
    auto dfs = [&](auto &&self, int u, int f)->void
    {
        d[u] = d[f] + 1;
        di[d[u]].push_back(u);
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, e, 0);
    for (int i = n; i >= 1; i--)
    {
        for (auto v : di[i])
            cout << v << ' ';
    }
    cout << '\n';
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