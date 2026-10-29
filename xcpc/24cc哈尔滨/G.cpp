#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> st(n + 1);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        st[x] = 1;
    }
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!st[u])
            adj[u].push_back(v);
        if (!st[v])
            adj[v].push_back(u);
    }
    if (k == n)
    {
        cout << "No\n";
        return;
    }
    vector<int> vis(n + 1);
    vector<vector<int>> ans;
    auto dfs = [&](auto &&self, int u) -> void
    {
        int cnt = 0;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            cnt++;
        }
        if (cnt != 0)
        {
            ans.push_back({});
            int pos = ans.size() - 1;
            ans[pos].push_back(u);
            ans[pos].push_back(cnt);
            for (auto v : adj[u])
            {
                if (vis[v])
                    continue;
                vis[v] = 1;
                ans[pos].push_back(v);
            }
            for (int i = 2; i < ans[pos].size(); i++)
            {
                self(self, ans[pos][i]);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            vis[i] = 1;
            dfs(dfs, i);
            if (ranges::count(vis, 0) > 1)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n"
                     << ans.size() << '\n';
                for (auto a : ans)
                {
                    for (auto x : a)
                        cout << x << ' ';
                    cout << '\n';
                }
            }
            break;
        }
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