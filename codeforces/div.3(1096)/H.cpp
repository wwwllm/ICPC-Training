#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n + 1), d(n + 1);
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        if (adj[u].size() == 1)
            sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        int tmp = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            tmp = max(tmp, d[v] + (sz[v] & 1 ? 1 : -1));
        }
        d[u] = tmp;
    };
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > 1)
        {
            root = i;
            dfs1(dfs1, root, 0);
            break;
        }
    }
    int ans = 0;
    auto dfs2 = [&](auto &&self, int u, int f) -> void
    {
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            if (sz[v] & 1)
            {
                ans++;
            }
            self(self, v, u);
        }
    };
    dfs2(dfs2, root, 0);
    if (sz[root] & 1)
        cout << ans - d[root] << '\n';
    else
        cout << ans << '\n';
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