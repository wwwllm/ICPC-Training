#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
const int N = 5000, inf = 1e18;
struct MinCostFlow
{
    struct _edge
    {
        int to;
        long long cap;
        long long cost;
        _edge(int to, long long cap, long long cost) : to(to), cap(cap), cost(cost) {}
    };

    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<long long> dis;
    vector<int> cur;
    vector<bool> vis;

    MinCostFlow(int n) : n(n)
    {
        e.clear();
        g.assign(n, {});
        dis.assign(n, inf);
        cur.assign(n, 0);
        vis.assign(n, false);
    }

    void add(int u, int v, long long cap, long long cost)
    {
        g[u].push_back(e.size());
        e.push_back({v, cap, cost});
        g[v].push_back(e.size());
        e.push_back({u, 0, -cost});
    }

    bool spfa(int s, int t)
    {
        fill(dis.begin(), dis.end(), inf);
        fill(vis.begin(), vis.end(), false);
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        vis[s] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int idx : g[u])
            {
                auto [v, cap, cost] = e[idx];
                if (cap > 0 && dis[v] > dis[u] + cost)
                {
                    dis[v] = dis[u] + cost;
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dis[t] != inf;
    }

    long long dfs(int u, int t, long long f, long long &maxcost)
    {
        if (u == t || f == 0)
            return f;
        long long flow = 0;
        vis[u] = true;

        for (int &i = cur[u]; i < g[u].size(); ++i)
        {
            int idx = g[u][i];
            auto [v, cap, cost] = e[idx];
            if (!vis[v] && cap > 0 && dis[v] == dis[u] + cost)
            {
                long long nf = dfs(v, t, min(f, cap), maxcost);
                if (nf > 0)
                {
                    e[idx].cap -= nf;
                    e[idx ^ 1].cap += nf;
                    flow += nf;
                    f -= nf;
                    maxcost += nf * cost;
                    if (f == 0)
                        break;
                }
            }
        }
        vis[u] = false;
        return flow;
    }

    pair<long long, long long> flow(int s, int t)
    {
        long long maxflow = 0;
        long long maxcost = 0;
        while (spfa(s, t))
        {
            fill(cur.begin(), cur.end(), 0);
            maxflow += dfs(s, t, inf, maxcost);
        }
        return {maxflow, maxcost};
    }

    struct Edge
    {
        int from, to;
        long long cap, flow, cost;
    };

    vector<Edge> edges()
    {
        vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2)
        {
            a.push_back({e[i + 1].to, e[i].to, e[i].cap + e[i + 1].cap, e[i + 1].cap, e[i].cost});
        }
        return a;
    }
};
int g[N + 1][N + 1];
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        g[x][y] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        b[i] = {x, y};
        g[x][y] = i + n;
    }
    MinCostFlow f(2 * n + 2);
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        f.add(s, i, 1, 0);
        f.add(i + n, t, 1, 0);
    }
    vector<array<int, 2>> walk = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    auto check = [&](int x, int y)
    {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    };
    for (int i = 1; i <= n; i++)
    {
        for (auto [dx, dy] : walk)
        {
            auto [x, y] = a[i];
            int len = 0;
            while (check(x + dx, y + dy) && g[x][y] <= n && g[x][y] >= 1)
                x += dx, y += dy, len++;
            if (g[x][y] > n)
                f.add(i, g[x][y], 1, len);
        }
    }
    auto [ff, cost] = f.flow(s, t);
    if (ff == n)
    {
        cout << "Yes\n";
        auto e = f.edges();
        vector<int> match(n + 1);
        for (auto [u, v, c, fl, cost] : e)
        {
            if (u == s || v == t)
                continue;
            if (fl == 1)
            {
                match[u] = v;
            }
        }
        vector adj(n + 1, vector<int>());
        for (int i = 1; i <= n; i++)
        {
            auto [x0, y0] = a[i];
            auto [x1, y1] = b[match[i] - n];
            int dx = (x0 - x1) == 0 ? 0 : (x1 - x0) / abs(x0 - x1);
            int dy = (y0 - y1) == 0 ? 0 : (y1 - y0) / abs(y0 - y1);
            int x = x0, y = y0;
            while (check(x + dx, y + dy) && g[x][y] <= n && g[x][y] >= 1)
            {
                x += dx, y += dy;
                if (g[x][y] > n)
                    break;
                adj[i].push_back(g[x][y]);
            }
        }
        map<array<int, 2>, char> mp;
        mp[{0, 1}] = 'R', mp[{0, -1}] = 'L', mp[{1, 0}] = 'D', mp[{-1, 0}] = 'U';
        auto print = [&](int i, int j)
        {
            auto [x0, y0] = a[i];
            auto [x1, y1] = b[j];
            int dx = (x0 - x1) == 0 ? 0 : (x1 - x0) / abs(x0 - x1);
            int dy = (y0 - y1) == 0 ? 0 : (y1 - y0) / abs(y0 - y1);
            cout << i << ' ' << mp[{dx, dy}] << '\n';
        };
        queue<int> q;
        vector<int> ind(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (auto v : adj[i])
                ind[v]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            print(u, match[u] - n);
            for (auto v : adj[u])
            {
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }
    }
    else
        cout << "No\n";
    for (int i = 1; i <= n; i++)
    {
        g[a[i][0]][a[i][1]] = 0;
        g[b[i][0]][b[i][1]] = 0;
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