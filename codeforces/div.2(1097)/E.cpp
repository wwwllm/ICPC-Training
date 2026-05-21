#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;

const ll inf = 1e9;
struct HLD
{
    int n, root;
    vector<int> top, son, siz, dfn, rnk, fa, idx;
    vector<ll> dep, l;
    vector<vector<int>> g;
    vector<vector<int>> f;
    int cur;
    HLD(int n, int root) : n(n), root(root)
    {
        init();
    }
    void init()
    {
        f.assign(n, {});
        g.assign(n, {});
        top.assign(n, 0);
        fa.assign(n, 0);
        son.assign(n, -1);
        rnk.assign(n, 0);
        dep.assign(n, 0);
        dfn.assign(n, 0);
        siz.assign(n, 0);
        idx.assign(n, -1);
        l.assign(n, 0);
        dep[root] = 0;
        cur = 0;
    }
    void add(int u, int v)
    {
        g[u].push_back(v);
    }
    void dfs1(int u, int f)
    {
        dep[u] = (f == -1 ? 0LL : dep[f]) + l[u], siz[u] = 1;
        for (int i = 0; i < g[u].size(); i++)
        {
            auto v = g[u][i];
            if (v == f)
                continue;
            dfs1(v, u);
            siz[u] += siz[v];
            if (son[u] == -1 || siz[v] > siz[son[u]])
            {
                son[u] = v;
                idx[u] = i;
            }
        }
    }
    void dfs2(int u, int ftop)
    {
        dfn[u] = cur, rnk[cur] = u, top[u] = ftop;
        cur++;
        f[ftop].push_back(u);
        if (son[u] != -1)
            dfs2(son[u], ftop);
        for (auto v : g[u])
        {
            if (v == son[u] || v == fa[u])
                continue;
            dfs2(v, v);
        }
    }
    void work()
    {
        dfs1(root, -1);
        dfs2(root, root);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    HLD adj(n + 1, 1);
    auto &fa = adj.fa;
    auto &l = adj.l;
    for (int i = 2; i <= n; i++)
        cin >> fa[i];
    for (int i = 2; i <= n; i++)
        cin >> l[i];
    for (int i = 2; i <= n; i++)
        adj.add(fa[i], i);
    adj.work();
    auto &g = adj.g;
    auto &f = adj.f;
    vector t(n + 1, vector<array<int, 2>>{});
    vector<vector<array<int, 4>>> jp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (adj.f[i].empty())
            continue;
        vector<int> tmp;
        for (int j = 0; j < f[i].size(); j++)
        {
            int u = f[i][j];
            int d = g[u].size();
            if (d <= 1)
                continue;
            int val = ((adj.idx[u] - adj.dep[u]) % d + d) % d;
            if (t[d].empty())
            {
                tmp.push_back(d);
            }
            t[d].push_back({j, val});
        }
        for (auto d : tmp)
        {
            auto [u, val] = t[d][0];
            int v = inf;
            for (int j = 0; j < t[d].size(); j++)
            {
                if (t[d][j][1] != val)
                {
                    v = t[d][j][0];
                    break;
                }
            }
            jp[i].push_back({d, val, u, v});
            t[d].clear();
        }
    }
    while (q--)
    {
        ll ti;
        cin >> ti;
        int p = 1;
        while (1)
        {
            if (g[p].empty())
                break;
            int top = adj.top[p];
            int cur = f[top].size() - 1;
            for (const auto &[d, val, u, v] : jp[top])
            {
                if (u >= cur)
                    break;
                int w = ti % d;
                int pos = w == val ? v : u;
                cur = min(cur, pos);
            }
            if (cur == f[top].size() - 1)
            {
                p = f[top].back();
                break;
            }
            else
            {
                top = f[top][cur];
                int d = g[top].size();
                int pos = (ti + adj.dep[top]) % d;
                p = g[top][pos];
            }
        }
        cout << p << ' ';
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}