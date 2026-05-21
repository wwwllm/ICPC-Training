#include <bits/stdc++.h>
using namespace std;

struct VBCC
{
    int n;
    vector<vector<int>> adj, bcc;
    vector<int> dfn, low;
    vector<int> stk;
    vector<int> cut;
    int cur;
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
    }
    VBCC(int n)
    {
        init(n);
    }
    void add(int u, int v)
    {
        adj[u].push_back(v), adj[v].push_back(u);
    }
    void dfs(int u, int f)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        int son = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            if (dfn[v] == -1)
            {
                son++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u])
                {
                    if (f == -1 || son > 1)
                        cut[u] = 1;
                    bcc.push_back({});
                    int y;
                    do
                    {
                        y = stk.back();
                        bcc.back().push_back(y);
                        stk.pop_back();
                    } while (y != v);
                    bcc.back().push_back(u);
                }
            }
            else
                low[u] = min(dfn[v], low[u]);
        }
        if (f == -1 && son == 0)
        {
            bcc.push_back({});
            bcc.back().push_back(u);
        }
    }
    vector<vector<int>> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                dfs(i, -1);
            }
        }
        return bcc;
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
struct LCA
{
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;

    // n 为节点总数，编号 0 ~ n-1
    LCA(int n) : n(n), l(__lg(n) + 1), d(n), f(n, vector<int>(l, -1)), adj(n) {}

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 默认从 0 号节点开始 DFS
    void work(int rt = 0)
    {
        dfs(rt, -1, 0);
    }

    void dfs(int u, int fa, int dep)
    {
        d[u] = dep;
        f[u][0] = fa;
        for (int i = 1; i < l; i++)
        {
            if (f[u][i - 1] != -1)
            {
                f[u][i] = f[f[u][i - 1]][i - 1];
            }
            else
            {
                f[u][i] = -1;
            }
        }
        for (int v : adj[u])
        {
            if (v != fa)
            {
                dfs(v, u, dep + 1);
            }
        }
    }

    int query(int u, int v)
    {
        if (d[u] < d[v])
            swap(u, v);
        // 先跳到同一深度
        for (int i = l - 1; i >= 0; i--)
        {
            if (f[u][i] != -1 && d[f[u][i]] >= d[v])
            {
                u = f[u][i];
            }
        }
        if (u == v)
            return u;
        // 共同向上跳
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
    int n, m;
    cin >> n >> m;
    VBCC adj(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.add(u, v);
    }
    adj.work();
    LCA d(n + adj.bcc.size());
    d.adj = adj.get_tree();
    int q;
    cin >> q;
    d.work();
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << d.dist(u, v) / 2 + 1 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}