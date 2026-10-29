#include <bits/stdc++.h>
#define int long long
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int, 2>> e(m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
    }
    vector<int> p(q);
    for (int i = 0; i < q; i++)
    {
        cin >> p[i];
    }
    auto check = [&](int pos)
    {
        vector adj(n + 1, vector<int>());
        vector<int> vis(n + 1);
        for (int i = 0; i < pos; i++)
        {
            vis[p[i]] = 1;
        }
        for (auto [u, v] : e)
        {
            if (vis[u] || vis[v])
                continue;
            adj[u].push_back(v);
        }
        queue<int> q;
        vis.assign(n, 0);
        q.push(1);
        vis[1] = 1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (vis[v])
                    continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        return vis[n] == 1;
    };
    int l = -1, r = q + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    if (l == q)
    {
        cout << "YES\n";
    }
    else if (!check(l))
    {
        cout << "NO\n";
    }
    else
        cout << l << '\n';
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
