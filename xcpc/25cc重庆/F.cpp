#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
        cin >> fa[i], adj[fa[i]].push_back(i);
    vector<int> f(n + 1);
    vector<int> down(n + 1), up(n + 1, -1e18);
    vector pre(n + 1, vector<int>()), suf(n + 1, vector<int>());
    auto dfs = [&](auto &&self, int u) -> void
    {
        for (auto v : adj[u])
        {
            self(self, v);
        }
        ranges::sort(adj[u], [&](int x, int y)
                     { return f[x] > f[y]; });
        int m = adj[u].size();
        int cnt = 0;
        pre[u].resize(m);
        suf[u].resize(m);
        for (int i = 0; i < m; i++)
        {
            int v = adj[u][i];
            f[u] = max(2 * i + 1 + f[v], f[u]);
            if (adj[v].size())
            {
                down[u] = max(2 * cnt + 1 + f[v], down[u]);
                cnt++;
            }
            pre[u][i] = (2 * i + 1 + f[v]);
            suf[u][i] = (2 * i - 1 + f[v]);
        }
        for (int i = 1; i < m; i++)
        {
            pre[u][i] = max(pre[u][i - 1], pre[u][i]);
        }
        for (int i = m - 2; i >= 0; i--)
        {
            suf[u][i] = max(suf[u][i], suf[u][i + 1]);
        }
    };
    dfs(dfs, 1);
    auto dfs1 = [&](auto &&self, int u) -> void
    {
        int m = adj[u].size();
        for (int i = 0; i < m; i++)
        {
            int v = adj[u][i];
            int p = i == 0 ? -1e18 : pre[u][i - 1];
            int s = i == m - 1 ? -1e18 : suf[u][i + 1];
            up[v] = max({up[u], p, s}) + 1;
            self(self, v);
        }
    };
    dfs1(dfs1, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << max({up[i], down[i], 0LL}) << " \n"[i == n];
    }
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