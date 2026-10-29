#include <bits/stdc++.h>
#define int long long
using namespace std;

struct LCA
{
    int n, l;
    int cur;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;
    vector<int> dfn;
    vector<int> out;

    LCA(int n) : n(n), l(__lg(n) + 1), d(n + 1), f(n + 1, vector<int>(l, 0)), adj(n + 1), dfn(n), cur(0) {}

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
        dfn[u] = cur++;
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
    bool check(int u, int v)
    {
        return query(u, v) == u;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    LCA g(n + 1);
    auto &adj = g.adj;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add(u, v);
    }
    g.work();
    auto &dep = g.d;
    auto &dfn = g.dfn;
    vector<int> ans(m);
    unordered_map<int, vector<array<int, 2>>> mp;
    for (int i = 0; i < m; i++)
    {
        int u, s;
        cin >> u >> s;
        mp[s + dep[u]].push_back({i, u});
    }
    for (auto &[val, a] : mp)
    {
        if (a.size() == 1)
        {
            ans[a[0][0]] = 1;
        }
        else
        {
            if (a.size() == 2)
                continue;
            vector<int> p;
            for (int i = 0; i < a.size(); i++)
            {
                p.push_back(a[i][1]);
            }
            ranges::sort(p, [&](int u, int v)
                         { return dfn[u] < dfn[v]; });
            int N = p.size();
            for (int i = 0; i < N - 1; i++)
            {
                p.push_back(g.query(p[i], p[i + 1]));
            }
            unordered_map<int, int> pos;
            ranges::sort(p, [&](int u, int v)
                         { return dfn[u] < dfn[v]; });
            p.erase(unique(p.begin(), p.end()), p.end());
            N = p.size();
            for (int i = 0; i < N; i++)
            {
                pos[p[i]] = i;
            }
            vector<int> stk;
            vector<int> fa(N, -1);
            int root = -1;
            for (int i = 0; i < N; i++)
            {
                while (stk.size() && !g.check(p[stk.back()], p[i]))
                {
                    stk.pop_back();
                }
                if (stk.size())
                {
                    fa[i] = stk.back();
                }
                else
                    root = i;
                stk.push_back(i);
            }
            vector vadj(N, vector<int>());
            for (int i = 0; i < N; i++)
            {
                if (fa[i] != -1)
                    vadj[fa[i]].push_back(i);
            }
            vector<int> dp(N);
            for (auto [idx, u] : a)
            {
                if (dp[pos[u]] == 0)
                    dp[pos[u]] = idx + 1;
                else
                    dp[pos[u]] = -1;
            }
            auto dfs = [&](auto &&self, int u) -> int
            {
                int cnt = dp[u] != 0;
                int res = dp[u];
                if (dp[u] == -1)
                    cnt = 2;
                for (auto v : vadj[u])
                {
                    int x = self(self, v);
                    if (x)
                    {
                        cnt++;
                        res = x;
                    }
                }
                if (cnt == 1)
                    dp[u] = res;
                else
                    dp[u] = 0;
                return dp[u];
            };
            int res = dfs(dfs, root);
            if (res - 1 >= 0)
                ans[res - 1] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i];
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
