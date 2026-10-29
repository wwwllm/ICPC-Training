#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct MinCostFlow
{
    const int inf = 1e18;
    struct _edge
    {
        int to;
        int cap;
        int cost;
        _edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {};
    };
    int n;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> dis, h;
    vector<int> pre;
    MinCostFlow(int n) : n(n)
    {
        init(n);
    }
    void init(int n)
    {
        e.clear();
        g.assign(n, {});
    }
    void add(int u, int v, int w, int c)
    {
        g[u].push_back(e.size());
        e.push_back({v, w, c});
        g[v].push_back(e.size());
        e.push_back({u, 0, -c});
    }
    bool dij(int s, int t)
    {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        dis[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] != d)
                continue;
            for (auto idx : g[u])
            {
                auto [v, cap, w] = e[idx];
                if (cap > 0 && dis[v] > d + h[u] - h[v] + w)
                {
                    dis[v] = d + h[u] - h[v] + w;
                    pre[v] = idx;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[t] != inf;
    }
    array<int, 2> flow(int s, int t)
    {
        int f = 0;
        int cost = 0;
        h.assign(n, 0);
        while (dij(s, t))
        {
            for (int i = 0; i < n; i++)
            {
                h[i] += dis[i];
            }
            int nf = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                nf = min(nf, e[pre[i]].cap);
            for (int i = t; i != s; i = e[pre[i] ^ 1].to)
                e[pre[i]].cap -= nf, e[pre[i] ^ 1].cap += nf;
            f += nf;
            cost += nf * h[t];
        }
        return array<int, 2>({f, cost});
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    int s = 0, t = n + m + 1;
    MinCostFlow f(n + m + 2);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        g[i].assign(x, 0);
        for (int j = 0; j < x; j++)
        {
            cin >> g[i][j];
            f.add(i, n + g[i][j], 1, 0);
        }
    }

    vector w(m + 1, vector<int>());
    for (int i = 1; i <= m; i++)
    {
        int y;
        cin >> y;
        w[i].assign(y, 0);
        for (int j = 0; j < y; j++)
        {
            cin >> w[i][j];
            f.add(n + i, t, 1, w[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f.add(s, i, 1, 0);
    }
    auto [flow, cost] = f.flow(s, t);
    cout << cost << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}