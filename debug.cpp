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
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(m);
    for (auto &[x, y, z] : a)
        cin >> x >> y >> z;
    ranges::sort(a, [&](array<int, 3> &a, array<int, 3> &b)
                 { return a[2] > b[2]; });
    DSU dsu(2 * n + 1);
    int ans = 0;
    for (auto [x, y, z] : a)
    {
        int xx = x + n, yy = y + n;
        if (dsu.find(x) == dsu.find(y))
        {
            cout << z << '\n';
            return 0;
        }
        else
        {
            dsu.merge(y, xx), dsu.merge(x, yy);
        }
    }
    cout << ans << '\n';
}