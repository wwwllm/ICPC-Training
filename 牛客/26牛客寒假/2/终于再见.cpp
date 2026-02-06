#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<int>{});
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> ind(n + 1), ans(n + 1);
    vector d(n + 1, vector<int>{});
    for (int i = 1; i <= n; i++)
    {
        ind[i] = adj[i].size();
        d[ind[i]].pb(i);
    }
    vector<int> dis(n + 1, inf);
    queue<int> q;
    auto bfs = [&](int deg)
    {
        for (auto u : d[deg])
        {
            q.push(u);
            dis[u] = 0;
        }
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (ind[v] < deg)
                {
                    if (dis[v] > dis[u] + 1)
                    {
                        q.push(v);
                        dis[v] = dis[u] + 1;
                    }
                }
            }
        }
    };
    for (int i = n; i >= 0; i--)
    {
        if (d[i].size() == 0)
            continue;
        for (auto u : d[i])
        {
            if (dis[u] == inf)
                ans[u] = -1;
            else
                ans[u] = dis[u];
        }
        bfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
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