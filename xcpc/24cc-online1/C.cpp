#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
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
    int n, k;
    cin >> n >> k;
    vector<int> t(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i] %= k;
    }

    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        s.insert({t[i], i});
    }
    int ans = 0;
    DSU dsu(n);
    while (dsu.count() > 1)
    {
        vector<vector<int>> comp(n);
        for (int i = 0; i < n; i++)
        {
            comp[dsu.find(i)].push_back(i);
        }
        vector<array<int, 3>> e(n, {inf, -1, -1});
        for (int i = 0; i < n; i++)
        {
            if (comp[i].empty())
                continue;
            for (auto u : comp[i])
            {
                s.erase({t[u], u});
            }
            if (!s.empty())
            {
                for (auto u : comp[i])
                {
                    int v, w;
                    auto it = s.lower_bound({k - t[u], -1});
                    if (it != s.end())
                    {
                        v = (*it)[1];
                        w = t[u] + (*it)[0] - k;
                    }
                    else
                    {
                        it = s.begin();
                        v = (*it)[1];
                        w = t[u] + (*it)[0];
                    }
                    if (w < e[i][0])
                        e[i] = {w, u, v};
                }
            }
            for (auto u : comp[i])
            {
                s.insert({t[u], u});
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (e[i] == array<int, 3>{inf, -1, -1})
                continue;
            auto [w, u, v] = e[i];
            if (dsu.merge(u, v))
                ans += w;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}