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
            for (auto v : adj[u])
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
    VBCC g(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add(u, v);
    }
    auto bcc = g.work();
    cout << bcc.size() << '\n';
    for (auto p : bcc)
    {
        cout << p.size() << ' ';
        for (auto u : p)
            cout << u + 1 << ' ';
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}