#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
using i128 = __int128_t;
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
    int n, k;
    vector<_edge> e;
    vector<vector<int>> g;
    vector<int> dis, h;
    vector<int> pre;
    MinCostFlow(int n, int k) : n(n), k(k)
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
    void spfa(int s)
    {
        h.assign(n, inf);
        vector<bool> vis(n, false);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        vis[s] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (auto idx : g[u])
            {
                auto [v, cap, w] = e[idx];
                if (cap > 0 && h[v] > h[u] + w)
                {
                    h[v] = h[u] + w;
                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    array<int, 2> flow(int s, int t)
    {
        int f = 0;
        int cost = 0;
        h.assign(n, 0);
        spfa(s);
        while (f < k && dij(s, t))
        {
            for (int i = 0; i < n; i++)
            {
                h[i] += dis[i];
            }
            int nf = k - f;
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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    MinCostFlow adj(a + b + 2, k);
    int s = 0, t = a + b + 1;
    vector<array<int, 2>> fa(a + 1), fb(b + 1);
    for (int i = 1; i <= a; i++)
    {
        int fa, c;
        cin >> fa >> c;
        adj.add(fa, i, c, 0);
    }
    for (int i = 1; i <= b; i++)
    {

        int fa, c;
        cin >> fa >> c;
        fa += a;
        if (i == 1)
        {
            adj.add(i + a, t, c, 0);
        }
        else
        {
            adj.add(i + a, fa, c, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj.add(x, y + a, 1, -w);
    }
    auto [f, cost] = adj.flow(s, t);
    if (f != k)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << -cost << '\n';
    }
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
