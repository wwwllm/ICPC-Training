#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> hou(h);
    vector<vector<array<int, 2>>> g(2 * n + 1);
    for (auto &x : hou)
        cin >> x;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        g[u + n].pb({v + n, w / 2});
        g[v + n].pb({u + n, w / 2});
    }
    for (auto x : hou)
    {
        g[x].pb({x + n, 0});
    }
    vector<int> dis1(2 * n + 1, inf), dis2(2 * n + 1, inf);
    auto dij = [&](int st, vector<int> &dis)
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<int> vis(2 * n + 1);
        dis[st] = 0;
        pq.push({0, st});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [v, w] : g[u])
            {
                if (dis[v] > d + w)
                {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
    };
    dij(1, dis1), dij(n, dis2);
    int ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(max(min(dis1[i], dis1[i + n]), min(dis2[i], dis2[i + n])), ans);
    }
    if (ans > inf / 2)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
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