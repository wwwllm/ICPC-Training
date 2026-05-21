#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> siz(n + 1), vis(n + 1), has(inf + 1);
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> q(m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
        cin >> q[i];
    auto get_siz = [&](auto &&self, int u, int f) -> void
    {
        siz[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    auto get_ct = [&](auto &&self, int u, int f, int tot) -> int
    {
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            if (siz[v] > tot / 2)
                return self(self, v, u, tot);
        }
        return u;
    };
    auto get_dis = [&](auto &&self, int u, int f, int dis, vector<int> &cur) -> void
    {
        if (dis > inf)
            return;
        cur.push_back(dis);
        for (auto [v, w] : adj[u])
        {
            if (v == f || vis[v])
                continue;
            self(self, v, u, dis + w, cur);
        }
    };
    auto calc = [&](int u) -> void
    {
        vector<int> dis;
        dis.push_back(0);
        has[0] |= 1;
        for (auto [v, w] : adj[u])
        {
            if (vis[v])
                continue;
            vector<int> cur;
            get_dis(get_dis, v, u, w, cur);
            for (auto d : cur)
            {
                for (int i = 0; i < m; i++)
                {
                    if (q[i] >= d && has[q[i] - d])
                    {
                        ans[i] = 1;
                    }
                }
            }
            for (auto d : cur)
            {
                if (d < inf && !has[d])
                    has[d] = 1, dis.push_back(d);
            }
        }
        for (auto d : dis)
            has[d] = 0;
    };
    auto work = [&](auto &&self, int u) -> void
    {
        get_siz(get_siz, u, 0);
        int ct = get_ct(get_ct, u, 0, siz[u]);
        vis[ct] = 1;
        calc(ct);
        for (auto [v, w] : adj[ct])
        {
            if (vis[v])
                continue;
            self(self, v);
        }
    };
    for (int i = 0; i < m; i++)
    {
        if (q[i] == 0)
            ans[i] = 1;
    }
    work(work, 1);
    for (int i = 0; i < m; i++)
    {
        cout << (ans[i] ? "AYE" : "NAY") << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}