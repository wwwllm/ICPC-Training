#include <bits/stdc++.h>
using namespace std;

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
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
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
    int n;
    cin >> n;
    vector g(n + 1, vector<int>(n + 1));
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        s = ' ' + s;
        for (int j = 1; j <= n; j++)
        {
            g[i][j] = s[j] - '0';
            if (g[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> cnt(n + 1);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cnt[i] += g[i][j];
            if (i != j && g[i][j] && g[j][i])
                ok = 0;
        }
    }
    DSU dsu(n + 1);
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    vector<array<int, 2>> e;
    sort(p.begin(), p.end(), [&](int a, int b)
         { return cnt[a] < cnt[b]; });
    auto p_rev = p;
    ranges::reverse(p_rev);
    for (auto u : p)
    {
        if (g[u][u] == 0)
        {
            ok = 0;
            continue;
        }
        g[u][u] = 0;
        for (auto v : p_rev)
        {
            if (v == u || !g[u][v])
                continue;
            e.push_back({u, v});
            if (!dsu.merge(u, v))
                ok = 0;
            for (auto w : adj[v])
            {
                if (w == v)
                    continue;
                if (!g[u][w])
                {
                    ok = 0;
                    continue;
                }
                g[u][w] = 0;
            }
            g[u][v] = 0;
        }
        if (e.size() >= n)
            break;
        if (ranges::count(g[u], 1))
            ok = 0;
    }
    if (e.size() != n - 1)
        ok = 0;
    if (ok)
    {
        cout << "Yes\n";
        for (auto [u, v] : e)
            cout << u << ' ' << v << '\n';
    }
    else
    {
        cout << "No\n";
    }
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