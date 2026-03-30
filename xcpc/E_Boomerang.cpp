#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105143
struct LCA
{
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;

    LCA(int N) : n(N), l(__lg(N) + 1), d(N + 1), f(N + 1, vector<int>(l, 0)), adj(N + 1) {}

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int rt = 1)
    {
        dfs(rt, 0);
    }

    void dfs(int u, int fa)
    {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (int v : adj[u])
        {
            if (v != fa)
                dfs(v, u);
        }
    }

    int query(int u, int v)
    {
        if (d[u] < d[v])
            swap(u, v);
        for (int i = l - 1; i >= 0; i--)
        {
            if (d[f[u][i]] >= d[v])
                u = f[u][i];
        }
        if (u == v)
            return u;
        for (int i = l - 1; i >= 0; i--)
        {
            if (f[u][i] != f[v][i])
            {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    int dist(int u, int v)
    {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }
};
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
    int s, t0;
    cin >> s >> t0;
    LCA T(n);
    T.adj = adj;
    T.work();
    vector d(2 * n + 1, vector<int>());
    auto bfs = [&]()
    {
        queue<array<int, 2>> q;
        q.push({s, 0});
        vector<int> vis(n + 1);
        vis[s] = 1;
        while (q.size())
        {
            auto [u, t] = q.front();
            q.pop();
            d[t].push_back(u);
            for (auto v : adj[u])
            {
                if (vis[v])
                    continue;
                q.push({v, t + 1});
                vis[v] = 1;
            }
        }
    };
    bfs();
    vector<int> ans(n + 1);
    int l = s, r = s;
    int len = 0;
    int p = n;
    for (int t = 1; t <= n * 2; t++)
    {
        for (auto v : d[t])
        {
            int tmp1 = T.dist(l, v), tmp0 = T.dist(r, v);
            int ma = max({tmp1, tmp0, len});
            if (ma == tmp1)
                r = v;
            else if (ma == tmp0)
                l = v;
            len = ma;
        }
        int tt = max(0LL, t - t0);
        while (p >= 1 && p * tt * 2 >= len)
            ans[p--] = t;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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