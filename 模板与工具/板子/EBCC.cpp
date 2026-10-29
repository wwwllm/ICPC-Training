#include <bits/stdc++.h>
#define int long long
using namespace std;

struct EBCC
{
    int n;
    vector<vector<array<int, 2>>> adj;
    vector<array<int, 2>> e;
    vector<int> dfn, low, bel, siz;
    vector<int> brg;
    vector<int> stk;
    int cur, cnt;
    EBCC() {};
    EBCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.assign(n, -1);
        bel.assign(n, -1);
        e.clear();
        stk.clear();
        brg.clear();
        siz.clear();
        cur = cnt = 0;
    };
    void add(int u, int v)
    {
        adj[u].push_back({v, (int)e.size()});
        adj[v].push_back({u, (int)e.size()});
        e.push_back({u, v});
    }
    void dfs(int u, int fa)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto [v, pos] : adj[u])
        {
            if (pos == fa)
                continue;
            if (dfn[v] == -1)
            {
                dfs(v, pos);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    brg.push_back(pos);
            }
            else if (bel[v] == -1 && dfn[v] < dfn[u])
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            int sz = 0;
            do
            {
                v = stk.back();
                stk.pop_back();
                sz++;
                bel[v] = cnt;
            } while (v != u);
            siz.push_back(sz);
            cnt++;
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
    vector<array<int, 2>> compress()
    {
        vector<array<int, 2>> edges;
        for (int i = 0; i < e.size(); i++)
        {
            auto [u, v] = e[i];
            if (bel[u] != bel[v])
                edges.push_back({bel[u], bel[v]});
        }
        return edges;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    EBCC adj(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.add(u, v);
    }
    auto bel = adj.work();
    int cnt = adj.cnt;
    vector d(cnt, vector<int>{});
    cout << cnt << '\n';
    for (int i = 0; i < n; i++)
    {
        d[bel[i]].push_back(i + 1);
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << d[i].size() << ' ';
        for (auto u : d[i])
            cout << u << ' ';
        cout << '\n';
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