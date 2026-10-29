#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, T;
    cin >> n >> m >> T;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v, T};
    }
    vector<int> can(m);
    int k;
    cin >> k;
    vector<int> sp;
    for (int i = 0; i < k; i++)
    {
        int pos, val;
        cin >> pos >> val;
        pos--;
        sp.push_back(pos);
        e[pos][2] = val;
        can[pos] = 1;
    }
    vector dis(n + 1, vector<int>(n + 1, inf));
    {
        vector adj(n + 1, vector<int>());
        vector<int> vis(n + 1);
        queue<int> q;
        for (int i = 0; i < m; i++)
        {
            if (can[i])
                continue;
            auto [u, v, T] = e[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int s = 1; s <= n; s++)
        {
            vis.assign(n + 1, 0);
            vis[s] = 1;
            q.push(s);
            dis[s][s] = 0;
            while (q.size())
            {
                auto u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (vis[v])
                        continue;
                    dis[s][v] = dis[v][s] = dis[u][s] + T;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    vector<int> p;
    vector<int> pos(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        if (can[i])
        {
            auto [u, v, val] = e[i];
            p.push_back(u);
            p.push_back(v);
        }
    }
    ranges::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    int s = p.size();
    {
        for (int i = 0; i < s; i++)
        {
            pos[p[i]] = i;
        }
    }
    vector g(s, vector<int>(s, inf));
    for (int i = 0; i < s; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        if (can[i])
        {
            auto [u, v, val] = e[i];
            g[pos[u]][pos[v]] = g[pos[v]][pos[u]] = min(g[pos[v]][pos[u]], val);
        }
    }
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (dis[p[i]][p[j]] != inf)
            {
                g[i][j] = g[j][i] = min(g[i][j], dis[p[i]][p[j]]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, val;
        cin >> x >> val;
        x--;
        e[x][2] = val;
        auto [u, v, _] = e[x];
        g[pos[u]][pos[v]] = g[pos[v]][pos[u]] = dis[u][v];
        {
            for (int i : sp)
            {
                auto [u, v, w] = e[i];
                g[pos[u]][pos[v]] = g[pos[v]][pos[u]] = min(g[pos[u]][pos[v]], w);
            }
        }
        int l;
        cin >> l;
        while (l--)
        {
            int st, ed;
            cin >> st >> ed;

            vector<int> d(s, inf), vis(s);

            for (int i = 0; i < s; i++)
                d[i] = dis[st][p[i]];

            for (int t = 0; t < s; t++)
            {
                int u = -1;

                for (int i = 0; i < s; i++)
                {
                    if (!vis[i] && (u == -1 || d[i] < d[u]))
                        u = i;
                }

                if (u == -1 || d[u] == inf)
                    break;

                vis[u] = 1;

                for (int v = 0; v < s; v++)
                {
                    if (g[u][v] != inf)
                        d[v] = min(d[v], d[u] + g[u][v]);
                }
            }

            int ans = dis[st][ed];

            for (int i = 0; i < s; i++)
            {
                if (d[i] != inf && dis[p[i]][ed] != inf)
                    ans = min(ans, d[i] + dis[p[i]][ed]);
            }

            cout << ans << '\n';
        }
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