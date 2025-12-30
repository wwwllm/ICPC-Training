#include <bits/stdc++.h>
#define pb push_back
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> d1(n + 1), d2(n + 1);
    auto dfs=[&](auto &&self, int u, int f) -> int
    {
        d1[u] = 0, d2[u] = 0;
        int d = 0;
        for (auto v : g[u])
        {
            if (v == f)
                continue;
            d = max(d, self(self, v, u));
            int tmp = d1[v] + 1;
            if (tmp > d1[u])
                d2[u] = d1[u], d1[u] = tmp;
            else if (tmp > d2[u])
                d2[u] = tmp;
        }
        return max(d, d1[u] + d2[u]);
    };

    cout << dfs(dfs, 1, 0) << '\n';
    return 0;
}