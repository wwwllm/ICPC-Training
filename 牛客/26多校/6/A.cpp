#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
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
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    DSU dsu(n + 1);
    int ans = 1;
    for (int i = n; i >= 1; i--)
    {
        (ans *= dsu.esize(pos[i])) %= mod;
        int f = dsu.find(pos[i]);
        dsu.siz[f]--;
        if (pos[i] != 1 && pos[i] != n && dsu.esize(dsu.find(pos[i] - 1)) > 0 && dsu.esize(dsu.find(pos[i] + 1)) > 0)
            dsu.merge(pos[i] - 1, pos[i] + 1);
    }
    cout << ans << '\n';
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