#include <bits/stdc++.h>
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
    string a, b;
    cin >> a >> b;

    vector<array<int, 2>> qu(m);
    vector<int> ans(m);
    for (auto &[l, r] : qu)
        cin >> l >> r;

    a = '0' + a + '0';
    b = '0' + b + '0';
    vector<int> c(n + 2);
    for (int i = 0; i <= n + 1; i++)
    {
        c[i] = (a[i] - '0') ^ (b[i] - '0');
    }
    for (int i = n + 1; i >= 1; i--)
    {
        c[i] = c[i] ^ c[i - 1];
    }
    EBCC adj(n + 2);
    for (int i = 0; i < m; i++)
    {
        auto [l, r] = qu[i];
        adj.add(l, r + 1);
    }
    auto bel = adj.work();
    int N = adj.cnt;
    vector<int> val(N);
    for (int i = 0; i < n + 2; i++)
    {
        val[bel[i]] ^= c[i];
    }
    auto e = adj.compress();
    vector tr(N, vector<int>());
    for (auto [u, v] : e)
    {
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    bool ok = 1;
    vector<int> fa(N, -1), vis(N, 0);
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        vis[u] = 1;
        fa[u] = f;
        for (auto v : tr[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            val[u] ^= val[v];
        }
    };
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            dfs(dfs, i, -1);
            ok &= (val[i] == 0);
        }
    }
    for (int i = 0; i < m; i++)
    {
        auto [l, r] = qu[i];
        int u = bel[l], v = bel[r + 1];
        if (u == v)
            ans[i] = ok;
        else
        {
            if (fa[u] == v)
                swap(u, v);
            ans[i] = ok & (val[v] == 0);
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}