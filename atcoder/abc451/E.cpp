#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int val;
            cin >> val;
            a[i][j] = a[j][i] = val;
        }
    }
    bool ans = 1;
    vector adj(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        int p = -1;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            if (a[1][j] + a[j][i] == a[1][i])
            {
                if (p == -1 || a[1][j] > a[1][p])
                    p = j;
            }
        }
        if (p != -1)
        {
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
        else
            ans = 0;
    }
    auto dfs = [&](auto &&self, int u, int f, int d, int p) -> bool
    {
        bool ok = 1;
        if (a[p][u] != d)
            ok = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            ok &= self(self, v, u, d + a[u][v], p);
        }
        return ok;
    };
    for (int i = 1; i <= n; i++)
    {
        ans &= dfs(dfs, i, 0, 0, i);
    }
    cout << (ans ? "Yes\n" : "No\n");
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