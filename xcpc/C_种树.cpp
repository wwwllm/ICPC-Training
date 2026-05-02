#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    vector<int> siz(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            siz[u] += siz[v];
        }
        if (vis[u])
        {
            ans += siz[u] / 2;
            if (siz[u] % 2 == 0)
                vis[f] = 1;
            siz[u] = 0;
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            dfs(dfs, i, 0);
            cout << ans << '\n';
            return;
        }
    }
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