#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> dist(n + 1), p(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dist[u] = dist[fa] + 1;
        p[u] = fa;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
        }
    };
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //两次dfs求树的直径
    dist[0] = 0;
    dfs(dfs, 1, 0);
    int st = max_element(dist.begin(), dist.end()) - dist.begin();
    dfs(dfs, st, 0);
    int ed = max_element(dist.begin(), dist.end()) - dist.begin();
    if (dist[ed] == n)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> vis(n + 1);
    int tmp = ed;
    while (tmp != 0)
    {
        vis[tmp] = 1;
        tmp = p[tmp];
    }
    int a = 0, b = 0, c = 0;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : g[u])
        {
            if (vis[u] && !vis[v])
            {
                a = p[u], b = u, c = v;
                cout << a << ' ' << b << ' ' << c << '\n';
                return;
            }
        }
    }
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