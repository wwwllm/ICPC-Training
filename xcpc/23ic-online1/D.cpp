#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    vector<int> fa, siz;
    int cnt;
    DSU() {};
    DSU(int n) { init(n); };
    void init(int n)
    {
        fa.resize(n);
        ranges::iota(fa, 0);
        siz.assign(n, 1);
        cnt = n;
    }
    int find(int x)
    {
        return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return 0;
        siz[fx] += siz[fy];
        cnt--;
        fa[fy] = fx;
        return 1;
    }
    int esiz(int x)
    {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i)
        {
            int tmp = dsu.esiz(i);
            res += tmp * (tmp - 1) / 2;
        }
    }
    if (res == m)
    {
        int mi1 = 1e9, mi2 = 1e9;
        for (int i = 1; i <= n; i++)
        {
            if (dsu.find(i) == i)
            {
                int cnt = dsu.esiz(i);
                if (cnt < mi1)
                {
                    mi2 = mi1;
                    mi1 = cnt;
                }
                else if (cnt < mi2)
                {
                    mi2 = cnt;
                }
            }
        }
        res += (mi1 + mi2) * (mi1 + mi2 - 1) / 2 - mi1 * (mi1 - 1) / 2 - mi2 * (mi2 - 1) / 2;
        cout << res - m << '\n';
    }
    else
    {
        cout << res - m << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}