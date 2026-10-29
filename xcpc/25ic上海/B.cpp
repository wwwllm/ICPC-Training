#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] &= 1;
        sum ^= a[i];
    }
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cycle;
    vector<int> fa(n + 1), dep(n + 1);
    array<int, 2> p{-1, -1};
    {
        vector<int> col(n + 1, -1);
        auto dfs = [&](auto &&self, int u, int f) -> bool
        {
            fa[u] = f;
            dep[u] = dep[f] + 1;
            col[u] = col[f] ^ 1;
            bool ok = 0;
            for (auto v : adj[u])
            {
                if (v == f)
                    continue;
                if (col[u] == col[v])
                {
                    p = {u, v};
                    ok = 1;
                }
                if (col[v] == -1)
                {
                    ok |= self(self, v, u);
                }
            }
            return ok;
        };
        col[0] = 1;
        dfs(dfs, s, 0);
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == -1 && a[i])
            {
                cout << "No\n";
                return;
            }
        }
        auto get_cyc = [&](int u, int v)
        {
            vector<int> l, r;
            while (dep[u] > dep[v])
            {
                l.push_back(u);
                u = fa[u];
            }
            while (dep[v] > dep[u])
            {
                r.push_back(v);
                v = fa[v];
            }
            while (u != v)
            {
                l.push_back(u);
                r.push_back(v);
                u = fa[u], v = fa[v];
            }
            l.push_back(u);
            ranges::reverse(r);
            for (auto p : r)
                l.push_back(p);
            return l;
        };
        if (p != array<int, 2>{-1, -1})
        {
            cycle = get_cyc(p[0], p[1]);
        }
    }
    if (cycle.empty() && sum)
    {
        cout << "No\n";
        return;
    }
    vector<int> ans;
    vector<int> vis(n + 1);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        if (sum && cycle[0] == u)
        {
            for (int i = 0; i < cycle.size(); i++)
            {
                int v = cycle[(i + 1) % cycle.size()];
                a[v] ^= 1;
                ans.push_back(v);
            }
        }
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            vis[v] = 1;
            ans.push_back(v);
            a[v] ^= 1;
            self(self, v, u);
            ans.push_back(u);
            a[u] ^= 1;
            if (a[v])
            {
                ans.push_back(v);
                ans.push_back(u);
                a[v] ^= 1;
                a[u] ^= 1;
            }
        }
    };
    vis[s] = 1;
    dfs(dfs, s, 0);
    if (ranges::count(a, 0) != n + 1)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    cout << ans.size() << '\n';
    for (auto u : ans)
    {
        cout << u << ' ';
    }
    cout << '\n';
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