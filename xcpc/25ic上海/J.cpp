#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector adj(n + 1, vector(10, vector<array<int, 2>>()));
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        adj[u][w].push_back({v, i});
    }
    vector<int> ans;
    auto dfs = [&](auto &&self, vector<int> &t, int len) -> void
    {
        if (ans.size() > k || t.empty())
            return;
        for (int w = 1; w < 9; w++)
        {
            vector<int> nt;
            for (auto idx : t)
            {
                int u = e[idx][1];
                for (auto [v, pos] : adj[u][w])
                {
                    nt.push_back(pos);
                    ans.push_back(len + 1);
                    if (ans.size() > k)
                        return;
                }
            }
            self(self, nt, len + 1);
        }
    };
    for (int w = 1; w < 9; w++)
    {
        if (ans.size() > k)
            break;
        vector<int> t;
        for (int u = 1; u <= n; u++)
        {
            for (auto [_, idx] : adj[u][w])
            {
                t.push_back(idx);
                ans.push_back(1);
            }
        }
        dfs(dfs, t, 1);
    }
    for (int i = 0; i < k; i++)
    {
        if (i >= ans.size())
            cout << "-1\n";
        else
            cout << ans[i] << '\n';
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