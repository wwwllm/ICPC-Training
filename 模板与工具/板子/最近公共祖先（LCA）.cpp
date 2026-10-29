#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P3379
signed main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    vector<array<int, 31>> st(n + 1);
    vector<int> dep(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int root, int fa) -> void { // root是当前节点
        st[root][0] = fa;
        dep[root] = dep[fa] + 1;
        for (int i = 1; i <= 30; i++)
        {
            st[root][i] = st[st[root][i - 1]][i - 1];
        }
        for (auto v : g[root])
        {
            if (v == fa)
                continue;
            self(self, v, root);
        }
    };
    auto lca = [&](int u, int v)
    {
        if (dep[u] > dep[v])
            swap(v, u);
        int d = dep[v] - dep[u];
        for (int i = 0; i < 31; i++)
        {
            if ((d >> i) & 1)
                v = st[v][i];
        }
        if (u == v)
            return v;
        for (int i = 30; i >= 0 && v != u; i--)
        {
            if (st[u][i] != st[v][i])
            {
                u = st[u][i];
                v = st[v][i];
            }
        }
        return st[u][0];
    };
    dfs(dfs, s, 0);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}