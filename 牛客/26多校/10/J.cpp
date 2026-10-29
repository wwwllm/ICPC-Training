#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct VBCC
{
    int n;
    vector<vector<array<int, 2>>> adj;
    vector<vector<int>> bcc;
    vector<int> dfn, low;
    vector<int> stk;
    vector<int> cut;
    vector<array<int, 2>> e;
    vector<int> vis;
    vector<int> bel;
    int cur, cnt;
    VBCC() {};
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, -1);
        cut.assign(n, 0);
        stk.clear();
        cur = 0;
        cnt = 0;
    }
    VBCC(int n, int m)
    {
        vis.assign(m, 0);
        bel.assign(m, 0);
        init(n);
    }
    void add(int u, int v)
    {
        adj[u].push_back({v, (int)e.size()}), adj[v].push_back({u, (int)e.size()});
        e.push_back({u, v});
    }
    void dfs(int u, int f)
    {
        dfn[u] = low[u] = cur++;
        for (auto [v, idx] : adj[u])
        {
            if (vis[idx])
                continue;
            vis[idx] = 1;
            stk.push_back(idx);
            if (dfn[v] == -1)
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                {
                    int y;
                    do
                    {
                        y = stk.back();
                        bel[y] = cnt;
                        stk.pop_back();
                    } while (y != idx);
                    cnt++;
                }
            }
            else
                low[u] = min(dfn[v], low[u]);
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                dfs(i, -1);
            }
        }
        return bel;
    }
    vector<vector<int>> get_tree()
    {
        vector t(n + bcc.size(), vector<int>());
        for (int i = 0; i < bcc.size(); i++)
        {
            int u = n + i;
            for (auto v : bcc[i])
            {
                t[v].push_back(u);
                t[u].push_back(v);
            }
        }
        return t;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    VBCC adj(n + 1, m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj.add(u, v);
    }
    auto bel = adj.work();
    auto &g = adj.adj;
    auto &e = adj.e;
    vector<int> ans(n + 1);
    map<array<int, 2>, int> mp;
    for (int i = 0; i < m; i++)
    {
        auto [u, v] = e[i];
        mp[{bel[i], u}]++;
        mp[{bel[i], v}]++;
    }
    for (auto [x, cnt] : mp)
    {
        ans[x[1]] += cnt / 2;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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
