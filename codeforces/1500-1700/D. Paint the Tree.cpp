#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// https://codeforces.com/problemset/problem/1975/D
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dep(n + 1), fa(n + 1);

    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    dep[0] = -1;
    dfs(dfs, a, 0);

    int cost = (dep[b] + 1) / 2;
    int r = b;
    for (int i = 1; i <= cost; i++)
        r = fa[r];
    dfs(dfs, r, 0);
    int d = *max_element(dep.begin(), dep.end());

    cout << 2 * (n - 1) - d + cost << '\n';
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