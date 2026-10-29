#include <bits/stdc++.h>
#define int long long
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
    int n, q;
    cin >> n >> q;
    vector<int> fa(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        adj[fa[i]].push_back(i);
    }
    vector<int> dep(n + 1);
    auto dfs = [&](auto &&self, int u) -> void
    {
        for (auto v : adj[u])
        {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
    };
    dfs(dfs, 1);
    vector<array<int, 2>> a(q);
    for (auto &[u, v] : a)
        cin >> u >> v;
    ranges::sort(a, [&](array<int, 2> &a, array<int, 2> &b)
                 { return dep[a[1]] > dep[b[1]]; });
    DSU dsu(n + 1);
    adj.assign(n + 1, {});
    for (auto [u, v] : a)
    {
        int fu = dsu.find(u);
        if (dsu.merge(v, fu))
            adj[v].push_back(fu);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i && i != 1)
        {
            adj[1].push_back(i);
            dsu.merge(1, i);
        }
    }
    dep[1] = 0;
    dfs(dfs, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dep[i];
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}