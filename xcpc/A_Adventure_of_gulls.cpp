#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
const int N = 5000, inf = 1e18;
struct Flow
{
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow() {};
    Flow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
        cur.assign(n, 0);
        h.assign(n, -1);
    }
    void add(int u, int v, int c)
    {
        g[u].push_back(e.size());
        e.push_back({v, c});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    bool bfs(int s, int t)
    {
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto p : g[u])
            {
                auto [v, c] = e[p];
                if (c > 0 && h[v] == -1)
                {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    int dfs(int u, int t, int f)
    {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < g[u].size(); i++)
        {
            int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1)
            {
                int nf = dfs(v, t, min(r, c));
                e[j].cap -= nf;
                e[j ^ 1].cap += nf;
                r -= nf;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    int flow(int s, int t)
    {
        int ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
    vector<bool> minCut()
    {
        vector<bool> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = (h[i] != -1);
        }
        return c;
    }
    struct Edge
    {
        int from;
        int to;
        int cap;
        int flow;
    };
    vector<Edge> edges()
    {
        vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2)
        {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
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
    Flow f(2 * n + 2);
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        f.add(s, i, 1);
        f.add(i + n, t, 1);
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
            while (check(x + dx, y + dy) && g[x][y] <= n && g[x][y] >= 1)
                x += dx, y += dy;
            if (g[x][y] > n)
                f.add(i, g[x][y], 1);
        }
    }
    int c = f.flow(s, t);
    if (c == n)
    {
        cout << "Yes\n";
        auto e = f.edges();
        vector<int> match(n + 1);
        for (auto [u, v, c, f] : e)
        {
            if (u == s || v == t)
                continue;
            if (f == 1)
            {
                match[u] = v;
            }
        }
        vector adj(n + 1, vector<int>());
        vector<int> vis(n + 1), cyc, f(n + 1);
        auto init = [&]()
        {
            adj.assign(n + 1, vector<int>());
            vis.assign(n + 1, 0);
            f.assign(n + 1, -1);
            cyc.clear();
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
        };
        auto dfs = [&](auto &&self, int u) -> bool
        {
            vis[u] = 1;
            for (auto v : adj[u])
            {
                if (!vis[v])
                {
                    f[v] = u;
                    if (self(self, v))
                        return 1;
                }
                else if (vis[v] == 1)
                {
                    for (int i = u; i != v; i = f[i])
                    {
                        cyc.push_back(i);
                    }
                    cyc.push_back(v);
                    ranges::reverse(cyc);
                    return 1;
                }
            }
            vis[u] = 2;
            return 0;
        };
        while (1)
        {
            init();
            bool ok = 0;
            for (int i = 1; i <= n; i++)
            {
                if (!vis[i] && dfs(dfs, i))
                {
                    ok = 1;
                    break;
                }
            }
            if (!ok)
                break;
            int tmp = match[cyc.back()];
            for (int i = cyc.size() - 1; i > 0; i--)
            {
                match[cyc[i]] = match[cyc[(i - 1 + cyc.size()) % cyc.size()]];
            }
            match[cyc[0]] = tmp;
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