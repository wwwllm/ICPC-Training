#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= 2;
    vector adj(n + 1, vector<int>{});
    vector<int> s(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        s[u] += a[v], s[v] += a[u];
        s[u] %= 2, s[v] %= 2;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector g(n + 1, vector<int>{});
    vector<int> vis(n + 1);
    function<int(int, int)> dfs = [&](int u, int f) -> int
    {
        vis[u] = 1;
        int suf = 0;
        for (auto v : adj[u])
        {
            if (v == f || !a[v])
                continue;
            int ok = dfs(v, u);
            if (ok)
                g[u].pb(v), suf++;
            else
                g[v].pb(u);
        }
        if (f)
            suf++;
        return suf % 2;
    };
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 && !vis[i])
        {
            if (dfs(i, 0))
                ok = 0;
        }
    }
    vector<int> ans;
    auto topo = [&]()
    {
        vector<int> del(n + 1);
        queue<int> q;
        vector<int> ind(n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (auto v : g[i])
                ind[v]++;
        }
        for (int i = 1; i <= n; i++)
            if (!ind[i])
                q.push(i);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            if (!a[u])
                continue;
            vector<int> pre, suf;
            for (auto v : adj[u])
            {
                if (a[v] || del[v])
                    continue;
                if (s[v] % 2)
                    pre.pb(v);
                else
                    suf.pb(v);
            }
            for (auto v : pre)
                ans.pb(v), del[v] = 1;
            ans.pb(u), del[u] = 1;
            for (auto v : suf)
                ans.pb(v), del[v] = 1;
            for (auto v : g[u])
            {
                ind[v]--;
                if (!ind[v])
                {
                    q.push(v);
                }
            }
        }
    };
    topo();
    if (ans.size() != n)
        ok = 0;
    if (ok)
    {
        cout << "YES\n";
        for (auto v : ans)
            cout << v << ' ';
        cout << '\n';
    }
    else
        cout << "NO\n";
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