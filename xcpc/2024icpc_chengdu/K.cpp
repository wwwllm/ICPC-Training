#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

struct MinCostFlow
{
    const int inf = 1e9;
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_set<int> s;
    vector e(n, vector<array<int, 2>>{});
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = a[i];
        vector<array<int, 2>> pri;
        int cnt = 0;
        for (int j = 2; j <= a[i] / j; j++)
        {
            if (tmp % j == 0)
            {
                int c = 0;
                while (tmp % j == 0)
                {
                    tmp /= j;
                    c++;
                }
                pri.push_back({j, c});
                cnt += c;
            }
        }
        if (tmp > 1)
        {
            pri.push_back({tmp, 1});
            cnt++;
        }
        sum += cnt;
        vector<array<int, 2>> x;
        x.push_back({0, 1});
        for (auto [p, c] : pri)
        {
            int sz = x.size();
            for (int j = 0; j < sz; j++)
            {
                auto [dis, y] = x[j];
                for (int k = 1; k <= c; k++)
                {
                    y *= p;
                    dis++;
                    x.push_back({dis, y});
                }
            }
        }
        ranges::sort(x);
        int sz = min((int)x.size(), n);
        for (int j = 0; j < sz; j++)
        {
            auto [dis, p] = x[j];
            e[i].push_back({p, dis});
            s.insert(p);
        }
    }
    unordered_map<int, int> pos;
    int p = 0;
    for (auto x : s)
    {
        pos[x] = p++;
    }
    MinCostFlow adj(n + p + 2);
    int S = n + p, T = n + p + 1;
    for (int i = 0; i < n; i++)
    {
        int u = i + p;
        for (auto [x, val] : e[i])
        {
            int v = pos[x];
            adj.add(u, v, 1, val);
        }
    }
    for (int i = 0; i < n; i++)
    {
        adj.add(S, i + p, 1, 0);
    }
    for (int i = 0; i < p; i++)
    {
        adj.add(i, T, 1, 0);
    }
    auto [f, cost] = adj.flow(S, T);
    if (f == n)
        cout << sum - cost << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}