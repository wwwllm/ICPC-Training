#include <bits/stdc++.h>
#define int long long
using namespace std;

struct frac
{
    int p, q;
    frac(int p, int q) : p(p), q(q) {};
    bool operator<(const frac &b) const
    {
        return p * b.q < b.p * q;
    }
};
struct DSU
{
    vector<int> f, siz;
    vector<int> a, b;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        a.assign(n, 0);
        b.assign(n, 0);
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
        a[x] += a[y];
        b[x] += b[y];
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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> f(n + 1);
    vector adj(n + 1, vector<int>());
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if (f[i] != 0)
        {
            adj[f[i]].push_back(i);
            ind[i]++;
        }
    }
    priority_queue<pair<frac, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] != 0)
        {
            pq.push({{a[i], b[i]}, i});
        }
    }
    DSU dsu(n + 1);
    dsu.a = a;
    dsu.b = b;
    int ans = 0;
    while (pq.size())
    {
        auto [r, u] = pq.top();
        pq.pop();
        if (r.p != dsu.a[dsu.find(u)] || r.q != dsu.b[dsu.find(u)])
            continue;
        auto [sa, sb] = r;
        int fa = f[u];
        u = dsu.find(u);
        fa = dsu.find(fa);
        ans += dsu.b[fa] * dsu.a[u];
        dsu.merge(fa, u);
        if (fa != 1)
            pq.push({{dsu.a[fa], dsu.b[fa]}, fa});
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
