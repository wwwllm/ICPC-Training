#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

// https://www.luogu.com.cn/problem/P1993
const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].pb({b, -c});
        }
        else if (op == 2)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[b].pb({a, c});
        }
        else
        {
            int a, b;
            cin >> a >> b;
            g[a].pb({b, 0});
            g[b].pb({a, 0});
        }
    }

    for (int i = 1; i <= n; i++)
        g[0].pb({i, 0});
    vector<int> dis(n + 1, inf);
    auto spfa = [&]() -> bool
    {
        vector<int> vis(n + 1), cnt(n + 1);
        queue<int> q;
        dis[0] = 0;
        q.push(0);
        vis[0] = 1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto [v, w] : g[u])
            {
                if (dis[v] > dis[u] + w)
                {
                    cnt[v] = cnt[u] + 1;
                    dis[v] = dis[u] + w;
                    if (cnt[v] >= n)
                        return 0;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
        return 1;
    };
    bool ok = spfa();
    cout << (ok ? "Yes\n" : "No\n");
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