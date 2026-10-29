#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dis(n + 1);
    int l = 1;
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dis[v] = dis[u] + 1;
            if (dis[v] > dis[l])
                l = v;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    dis.assign(n + 1, 0);
    dfs(dfs, l, 0);
    cout << dis[l] << '\n';
    return 0;
}