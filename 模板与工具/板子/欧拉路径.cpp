#include <bits/stdc++.h>
using namespace std;

struct euler
{
    vector<vector<int>> adj;
    vector<int> ind, out;
    vector<int> cur;
    int n;
    euler(int n) : n(n), adj(n), ind(n), out(n) {}
    void add(int u, int v)
    {
        adj[u].push_back(v);
        out[u]++, ind[v]++;
    };

    vector<int> work()
    {
        vector<int> res;
        int s = -1, t = -1;
        for (int i = 0; i < n; i++)
        {
            if (out[i] == ind[i] + 1)
            {
                if (s != -1)
                    return res;
                s = i;
            }
            else if (ind[i] == out[i] + 1)
            {
                if (t != -1)
                    return res;
                t = i;
            }
            else if (out[i] != ind[i])
                return res;
        }
        if (s == -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (out[i] != 0)
                {
                    s = i;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            ranges::sort(adj[i]);
        }
        if (s == -1)
            return res;
        cur.assign(n, 0);
        auto dfs = [&](auto &&self, int u) -> void
        {
            for (int &i = cur[u]; i < adj[u].size();)
            {
                auto v = adj[u][i++];
                self(self, v);
            }
            res.push_back(u);
        };
        dfs(dfs, s);
        ranges::reverse(res);
        return res;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    euler adj(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj.add(u, v);
    }
    auto path = adj.work();
    if (path.size() == m + 1)
    {
        for (auto u : path)
            cout << u + 1 << ' ';
        cout << '\n';
    }
    else
    {
        cout << "No\n";
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