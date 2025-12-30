#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> b(n + 1);
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            g[i].push_back({i - 1, 0});
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].pb({b[i], a[i]});
    }
    vector<int> dis(n + 1, 1e18);
    auto dij = [&]()
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        dis[1] = 0;
        pq.push({0, 1});
        vector<int> vis(n + 1);

        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto v : g[u])
            {
                if (dis[v[0]] > d + v[1])
                {
                    dis[v[0]] = d + v[1];
                    pq.push({dis[v[0]], v[0]});
                }
            }
        }
    };
    dij();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, pre[i] - dis[i]);
    }
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