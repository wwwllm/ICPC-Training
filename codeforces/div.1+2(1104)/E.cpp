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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dsu.merge(a[i], i);
    }
    vector<int> vis(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != -1)
            t[b[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != -1)
        {
            int cur = i;
            int f = dsu.find(b[i]);
            vis[f] |= 1;
            while (b[a[cur]] == -1)
            {
                b[a[cur]] = a[b[cur]];
                if (t[b[a[cur]]] == 1)
                {
                    cout << "NO\n";
                    return;
                }
                t[b[a[cur]]] = 1;
                cur = a[cur];
            }
            if (b[a[cur]] != a[b[cur]])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<int> mi(n + 1, 1e9);
    for (int i = 1; i <= n; i++)
    {
        int f = dsu.find(i);
        if (!vis[i])
            mi[f] = min(mi[f], i);
    }
    map<int, set<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i && !vis[i])
        {
            int f = dsu.find(i);
            int c = dsu.esize(i);
            mp[c].insert(mi[f]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == -1)
        {
            int c = dsu.esize(i);
            if (mp[c].empty())
            {
                cout << "NO\n";
                return;
            }
            int u = *mp[c].begin();
            b[i] = u;
            mp[c].erase(u);
            int cur = i;
            int f = dsu.find(i);
            vis[f] |= 1;
            while (b[a[cur]] == -1)
            {
                b[a[cur]] = a[b[cur]];
                if (t[b[a[cur]]] == 1)
                {
                    cout << "NO\n";
                    return;
                }
                t[b[a[cur]]] = 1;
                cur = a[cur];
            }
            if (b[a[cur]] != a[b[cur]])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << b[i] << " \n"[i == n];
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