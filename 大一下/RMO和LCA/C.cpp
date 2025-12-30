#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27836/C
// 一个树中每一个子树在dfs序中一定是连续的
int lowbit(int x)
{
    return x & -x;
}
signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> r(n + 1), l(n + 1);
    int idx = 0;
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        l[u] = ++idx;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
        }
        r[u] = idx;
    };
    dfs(dfs, k, 0);

    vector<int> tr(n + 1);
    auto add = [&](int idx, int v)
    {
        for (int i = idx; i <= n; i += lowbit(i))
            tr[i] += v;
    };
    auto query = [&](int pos)
    {
        int ans = 0;
        for (int i = pos; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    };
    for (int i = 1; i <= n; i++)
        add(l[i], a[i]);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int pos, v;
            cin >> pos >> v;
            add(l[pos], v);
        }
        else
        {
            int pos;
            cin >> pos;
            int res = query(r[pos]) - query(l[pos] - 1);
            cout << res << '\n';
        }
    }
    return 0;
}