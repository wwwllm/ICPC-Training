#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;

struct MinCostFlow
{
    struct _edge
    {
        int to;
        int cap;
        int cost;
        _edge(int to, int cap, int cost) : to(to), cap(cap), cost(cost) {};
    };
    int n;
    int mxcap;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> dis, h;
    vector<int> pre;
    MinCostFlow(int n, int cap) : n(n), mxcap(cap)
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
                auto [v, cap, k] = e[idx];
                int w;
                if (idx & 1)
                    w = (cap - 1) * k;
                else
                {
                    int c = e[idx | 1].cap;
                    w = c * k;
                }
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
        while (f < mxcap && dij(s, t))
        {
            for (int i = 0; i < n; i++)
            {
                if (dis[i] != inf)
                    h[i] += dis[i];
            }
            int nf = 1;
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
    int n, m, W, H, K;
    cin >> n >> m >> W >> H >> K;
    MinCostFlow adj(n * m + W + H + 3, K);
    vector<int> fa(W + H + 1), q(W + 1);
    for (int i = 1; i <= W + H; i++)
    {
        cin >> fa[i];
    }
    for (int i = 1; i <= W; i++)
    {
        cin >> q[i];
    }
    vector time(H + 1, vector<array<int, 2>>());
    for (int i = 1; i <= H; i++)
    {
        int siz;
        cin >> siz;
        for (int j = 0; j < siz; j++)
        {
            int d, w;
            cin >> d >> w;
            time[i].push_back({d, w});
        }
    }
    int s = 0, t = W + H + n * m + 1;
    vector<int> val(W + 1 + H);
    for (int i = 1; i <= W; i++)
    {
        if (fa[i] == 0)
            val[i] = q[i];
        else
            val[i] = q[i] - q[fa[i]];
    }
    for (int i = 1; i <= W + H; i++)
    {
        if (i <= W)
            adj.add(fa[i], i, inf, val[i]);
        else
            adj.add(fa[i], i, 1, val[i]);
    }
    for (int i = 1; i <= H; i++)
    {
        for (auto [d, w] : time[i])
        {
            int u = i + W, v = (d - 1) * m + w + W + H;
            adj.add(u, v, 1, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            adj.add((i - 1) * m + j + W + H, t, 1, 0);
        }
    }
    auto [f, cost] = adj.flow(s, t);
    if (f != K)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << cost << '\n';
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