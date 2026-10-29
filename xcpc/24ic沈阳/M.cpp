#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct SCC
{
    int n;
    vector<vector<array<int, 2>>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    SCC() {};
    SCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        cur = cnt = 0;
    }
    void add(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto [v, w] : adj[u])
        {
            if (dfn[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (bel[v] == -1)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            do
            {
                v = stk.back();
                stk.pop_back();
                bel[v] = cnt;
            } while (v != u);
            cnt++;
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
                dfs(i);
        }
        return bel;
    }
    vector<vector<int>> get_DAG()
    {
        vector nadj(cnt, vector<int>{});
        for (int u = 0; u < n; u++)
        {
            for (auto [v, w] : adj[u])
            {
                if (bel[u] != bel[v])
                    nadj[bel[u]].push_back(bel[v]);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ranges::sort(nadj[i]);
            nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
        }
        return nadj;
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    SCC g(n);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.add((a % n + n) % n, ((a + b) % n + n) % n, b);
    }
    auto bel = g.work();
    auto nadj = g.get_DAG();
    m = nadj.size();
    vector<int> dis(n, inf);
    vector scc(m, vector<int>());
    for (int i = 0; i < n; i++)
    {
        scc[bel[i]].push_back(i);
    }
    vector<int> vis(m);
    for (int i = 0; i < m; i++)
    {
        int s = scc[i][0];
        if (scc[i].size() == 1)
        {
            for (auto [v, w] : g.adj[s])
            {
                if (bel[v] == bel[s] && w != 0)
                {
                    vis[i] = 1;
                    break;
                }
            }
            continue;
        }
        dis[s] = 0;
        auto dfs = [&](auto &&self, int u) -> bool
        {
            bool res = 1;
            for (auto [v, w] : g.adj[u])
            {
                if (bel[u] == bel[v])
                {
                    if (dis[v] == inf)
                    {
                        dis[v] = dis[u] + w;
                        res &= self(self, v);
                    }
                    else
                        res &= (dis[v] == dis[u] + w);
                }
            }
            return res;
        };
        bool ok = dfs(dfs, s);
        vis[i] = !ok;
    }
    vector<int> fa(m, -1);
    queue<int> Q;
    vector<int> d(m);
    vector adj(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
        for (auto v : nadj[i])
        {
            adj[v].push_back(i);
        }
        d[i] = nadj[i].size();
        if (nadj[i].empty())
            Q.push(i);
    }
    while (Q.size())
    {
        auto u = Q.front();
        Q.pop();
        for (auto v : adj[u])
        {
            if (d[v] == 0)
                continue;
            d[v]--;
            vis[v] |= vis[u];
            if (d[v] == 0)
            {
                Q.push(v);
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        int u = (x % n + n) % n;
        if (vis[bel[u]])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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