#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1)
    {
        cout << "El Psy Kongroo\n";
        return;
    }
    vector<int> siz(n + 1), dep(n + 1), dp1(n + 1), fa(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        dep[u] = dp1[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            siz[u] += siz[v];
            dp1[u] = max(dp1[u], dp1[v]);
        }
    };
    dfs(dfs, 1, 0);
    int low = *max_element(dep.begin() + 1, dep.end());
    bool ok = 0;
    int m = adj[1].size();
    vector<int> dis(m);
    for (int i = 0; i < m; i++)
    {
        dis[i] = dp1[adj[1][i]];
    }
    vector<int> pre(m), suf(m);
    pre[0] = dis[0];
    for (int i = 1; i < m; i++)
    {
        pre[i] = max(pre[i - 1], dis[i]);
    }
    suf[m - 1] = dis[m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        suf[i] = max(suf[i + 1], dis[i]);
    }

    if (m == 1)
    {
        if (n & 1)
            cout << "El Psy Kongroo\n";
        else
            cout << "Sonna bakana\n";
        return;
    }
    vector<int> vis(n + 1), dp(n + 1);
    map<int, int> c;
    auto Low = [&](auto &&self, int u, int f) -> int
    {
        c[dep[u]]++;
        int p = u;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            int pp = self(self, v, u);
            if (dep[pp] > dep[p])
                p = pp;
        }
        return p;
    };
    auto calc = [&](int u, int dis) -> int
    {
        int cur = u;
        while (fa[cur] != 1)
        {
            int f = fa[cur];
            if (dep[cur] <= dis && c[dep[cur]] == 1)
                break;
            cur = f;
        }
        return siz[cur];
    };
    for (int i = 0; i < m; i++)
    {
        int u = adj[1][i];
        if (dp1[u] != low)
            continue;
        c.clear();
        int l = i == 0 ? 0 : pre[i - 1],
            r = i == m - 1 ? 0 : suf[i + 1];
        int dis = max(l, r);
        int sz;
        int v = Low(Low, u, 1);
        sz = calc(v, dis);
        if (sz)
            ok |= sz % 2 == 1;
    }
    if (ok)
    {
        cout << "El Psy Kongroo\n";
    }
    else
    {
        cout << "Sonna bakana\n";
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