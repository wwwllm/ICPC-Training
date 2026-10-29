#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<int> val;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        val.push_back(a[i]), val.push_back(b[i]), val.push_back(c[i]);
    }
    ranges::sort(val);
    val.erase(unique(val.begin(), val.end()), val.end());
    auto find = [&](int x) -> int
    {
        return ranges::lower_bound(val, x) - val.begin();
    };
    int m = val.size();
    vector adj(m, vector<array<int, 2>>());
    vector<int> ind(m), cnt(m);
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u = find(a[i]), v = find(b[i]);
        col[i] = a[i];
        cnt[u] ^= 1;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> vis(m);
    auto dfs = [&](auto &&self, int u, int f, int id) -> void
    {
        vis[u] = 1;
        for (auto [v, pos] : adj[u])
        {
            if (vis[v])
                continue;
            self(self, v, u, pos);
        }
        if (f != -1 && cnt[u])
        {
            cnt[u] ^= 1;
            cnt[f] ^= 1;
            if (col[id] == val[u])
                col[id] = val[f];
            else
                col[id] = val[u];
        }
    };
    for (int i = 0; i < m; i++)
    {
        if (!vis[i])
            dfs(dfs, i, -1, 0);
    }
    for (int i = 0; i < m; i++)
    {
        if (cnt[i])
        {
            cout << -1 << '\n';
            return;
        }
    }
    adj.assign(2 * m, {});
    for (int i = 1; i <= n; i++)
    {
        int u = find(col[i]), v = find(c[i]) + m;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vis.assign(n + 1, 0);
    vector<int> st(m * 2);
    vector<array<int, 2>> path;
    vector<int> cur(m * 2);
    auto dfs1 = [&](auto &&self, int u, int pos) -> void
    {
        for (int &i = cur[u]; i < adj[u].size();)
        {
            auto [v, id] = adj[u][i++];
            if (vis[id])
                continue;
            vis[id] = 1;
            self(self, v, id);
        }
        path.push_back({u, pos});
        st[u] = 1;
    };
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == a[i])
            cout << 0;
        else
            cout << 1;
    }
    cout << '\n';
    vector<int> res(n + 1);
    for (int i = 0; i < 2 * m; i++)
    {
        if (st[i] == 0 && adj[i].size())
        {
            path.clear();
            dfs1(dfs1, i, 0);
            for (int i = 0; i <= path.size(); i++)
            {
                auto [u, id] = path[i];
                if (id != 0)
                {
                    res[id] = i & 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i];
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