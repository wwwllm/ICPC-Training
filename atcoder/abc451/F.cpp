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
    DSU dsu(2 * n + 1);
    auto &siz = dsu.siz;
    for (int i = 1; i <= n; i++)
        siz[i + n] = 0;
    int cnt = 0;
    bool ok = 1;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int uu = u + n, vv = v + n;
        if (dsu.find(u) == dsu.find(v))
        {
            ok = 0;
        }
        else if (dsu.find(u) != dsu.find(vv))
        {
            cnt -= min(dsu.esize(u), dsu.esize(uu));
            cnt -= min(dsu.esize(v), dsu.esize(vv));
            dsu.merge(u, vv);
            dsu.merge(v, uu);
            cnt += min(dsu.esize(u), dsu.esize(uu));
        }
        if (!ok)
            cout << -1 << '\n';
        else
            cout << cnt << '\n';
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