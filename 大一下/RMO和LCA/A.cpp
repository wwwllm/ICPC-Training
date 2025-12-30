#include <bits/stdc++.h>
using namespace std;

// https://ac.nowcoder.com/acm/contest/27836/A
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<array<int, 21>> st(n + 1);
    vector<int> dep(n + 1);

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int U, V, q;
    cin >> U >> V >> q;

    auto dfs = [&](auto &&self, int root, int fa) -> void { // root是当前节点
        st[root][0] = fa;
        dep[root] = dep[fa] + 1;
        for (int i = 1; i <= 20; i++)
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

    auto lca = [&](int u, int v) -> int
    {
        if (dep[u] > dep[v])
            swap(u, v);
        int d = dep[v] - dep[u];
        for (int i = 0; i < 21; i++)
        {
            if ((d >> i) & 1)
                v = st[v][i];
        }
        if (u == v)
            return u;
        for (int i = 20; i >= 0 && v != u; i--)
        {
            if (st[u][i] != st[v][i])
            {
                u = st[u][i], v = st[v][i];
            }
        }
        return st[u][0];
    };
    auto dist = [&](int x, int y) -> int
    {
        int root = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[root];
    };

    dfs(dfs, 1, 0);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int res = min({dist(x, y), dist(x, U) + dist(y, V), dist(x, V) + dist(y, U)});
        cout << res << '\n';
    }
    return 0;
}