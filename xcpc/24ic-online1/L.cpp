#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
struct DSU
{
    vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x)
    {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }
};
void solve()
{
    int n, l, q;
    cin >> n >> l >> q;
    vector t(l + 1, vector<int>(n + 1));
    auto get_int = [&]() -> int
    {
        char a, b;
        cin >> a >> b;
        return (a - 48) * 50 + (b - 48) % 50;
    };
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            t[i][j] = get_int();
        }
    }
    vector<int> vis(l + 1);
    vector<int> x(l + 1);
    for (int i = 1; i <= l; i++)
    {
        vector<int> cnt(n + 1);
        int c = 0;
        for (int j = 1; j <= n; j++)
        {
            cnt[t[i][j]]++;
            if (cnt[t[i][j]] == 1)
                c++;
        }
        if (c == n)
            vis[i] = 0;
        else if (c == n - 1)
        {
            int u = 0;
            for (int j = 1; j <= n; j++)
            {
                if (cnt[j] == 2)
                    u = j;
            }
            vis[i] = u;
            for (int j = 1; j <= n; j++)
            {
                if (cnt[j] == 0)
                    x[i] = j;
            }
        }
        else
            vis[i] = -1;
    }
    vector<array<int, 3>> Q(q);
    for (int i = 0; i < q; i++)
    {
        int a = get_int(), b = get_int(), c = get_int();
        Q[i] = {a, b, c};
    }
    DSU dsu(n + 1);
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i <= l; i++)
    {
        if (vis[i] == -1)
            continue;
        if (vis[i])
        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i][j] == vis[i])
                    adj[j].push_back({x[i], i});
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                if (dsu.merge(j, t[i][j]))
                {
                    adj[j].push_back({t[i][j], i});
                    adj[t[i][j]].push_back({j, i});
                }
            }
        }
    }
    vector dist(n + 1, vector<int>(n + 1, inf));
    auto dij = [&](int s)
    {
        auto &dis = dist[s];
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dis[u])
                continue;
            for (auto [v, w] : adj[u])
            {
                if (max(w, d) < dis[v])
                {
                    dis[v] = max(w, d);
                    pq.push({max(w, d), v});
                }
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        dij(i);
    }
    for (auto [a, b, c] : Q)
    {
        if (dist[a][b] <= c)
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}