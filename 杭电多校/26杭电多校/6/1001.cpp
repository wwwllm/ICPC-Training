#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SCC
{
    int n;
    vector<vector<int>> adj;
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
    void add(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto v : adj[u])
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
            for (auto v : adj[u])
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
    int n;
    cin >> n;
    vector<array<int, 2>> e;
    vector p(n + 1, vector<array<int, 2>>());
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        e.push_back({x, y});
        p[x].push_back({i, 0});
        p[y].push_back({i, 1});
    }
    SCC adj(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (p[i].size() == 1)
        {
            auto [u, x] = p[i].back();
            adj.add(2 * u ^ x, 2 * u ^ (!x));
        }
        else if (p[i].size() > 1)
        {
            auto [u, x] = p[i].back();
            auto [v, y] = p[i][p[i].size() - 2];
            adj.add(2 * u ^ x, 2 * v ^ y);
            adj.add(2 * v ^ (!y), 2 * u ^ (!x));
        }
    }
    adj.work();
    auto &bel = adj.bel;
    vector<int> ans(n - 1);
    bool ok = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (bel[2 * i] == bel[2 * i ^ 1])
        {
            ok = 0;
            break;
        }
        ans[i] = bel[(2 * i) ^ 1] < bel[2 * i];
    }
    if (!ok)
    {
        cout << 2 << '\n';
        vector<int> vis(n + 1);
        vector adj(n + 1, vector<array<int, 2>>());
        for (int i = 0; i < n - 1; i++)
        {
            auto [u, v] = e[i];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        auto dfs = [&](auto &&self, int u, int f, int pos) -> void
        {
            if (pos != -1)
                ans[pos] = u;
            vis[u] = 1;
            for (auto [v, idx] : adj[u])
            {
                if (v == f)
                    continue;
                self(self, v, u, idx);
            }
        };
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(dfs, i, 0, -1);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << ans[i] << " \n"[i == n - 2];
        }
    }
    else
    {
        cout << 1 << '\n';
        for (int i = 0; i < n - 1; i++)
        {
            cout << e[i][ans[i]] << " \n"[i == n - 2];
        }
    }
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