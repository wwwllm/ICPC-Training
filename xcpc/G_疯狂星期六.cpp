#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
struct Flow
{
    struct _edge
    {
        int to;
        int cap;
        _edge(int to, int cap) : to(to), cap(cap) {};
    };
    const int inf = 1e18;
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> v[i];
    vector<array<int, 3>> e(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    int cost = 0;
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, w] = e[i];
        sum += w;
        if (u == 1 || v == 1)
            cost += w;
    }
    cost = min(cost + v[1], a[1]);
    Flow f(n + m + 2);
    int s = 0, t = m + n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
        {
            int c = min(cost - 1, a[i]) - v[i];
            if (c < 0)
            {
                cout << "NO\n";
                return;
            }
            f.add(s, i, c);
        }
        else
            f.add(s, i, cost - v[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        auto [u, v, w] = e[i];
        f.add(i + n, t, w);
        f.add(u, i + n, w);
        f.add(v, i + n, w);
    }
    int ff = f.flow(s, t);
    if (ff == sum)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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