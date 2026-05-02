#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

struct DSU
{
    vector<int> f, siz;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
        f[y] = x;
        return 1;
    }

    int elesize(int x)
    {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m, x, d;
    cin >> n >> m >> x >> d;
    vector<array<int, 2>> h(n);
    vector<int> val(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h[i][0] = x;
        val[i + 1] = x;
        h[i][1] = i + 1;
    }
    ranges::sort(h, greater<array<int, 2>>());
    vector adj(n + 1, vector<int>{});
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> q(x + 1);
    DSU dsu(n + 1);
    for (int i = 1; i <= x; i++)
        cin >> q[i];
    int j = 0;
    int res = 0;
    vector<int> ans(x + 1);
    for (int i = x; i >= 1; i--)
    {
        while (j < n && h[j][0] > q[i])
        {
            int u = h[j][1];
            if (d == 1)
                res++;
            for (auto v : adj[u])
            {
                if (val[v] > q[i])
                {
                    int fu = dsu.find(u), fv = dsu.find(v);
                    if (fu != fv)
                    {
                        if (dsu.elesize(fu) >= d)
                            res--;
                        if (dsu.elesize(fv) >= d)
                            res--;
                        dsu.merge(fu, fv);
                        if (dsu.elesize(fu) >= d)
                            res++;
                    }
                }
            }
            j++;
        }
        ans[i] = res;
    }
    for (int i = 1; i <= x; i++)
        cout << ans[i] << "\n";
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