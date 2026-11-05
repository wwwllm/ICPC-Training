#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;

void solve(string role)
{
    if (role == "cat")
    {
        int n, m;
        cin >> n >> m;
        vector adj(n + 1, vector<int>());
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            adj[0].push_back(i);
        }
        vector<int> vis(n + 1);
        int cur = 0;
        vector<int> a(n + 1);
        auto dfs = [&](auto &&self, int u) -> void
        {
            if (adj[u].empty())
                return;
            for (auto v : adj[u])
            {
                if (vis[v])
                    continue;
                vis[v] = 1;
                a[v] = ++cur;
                self(self, v);
                cur++;
            }
        };
        dfs(dfs, 0);
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " \n"[i == n];
        }
    }
    else
    {
        int n;
        cin >> n;
        vector<int> pos(2 * n + 1);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            pos[x] = i;
        }
        vector<int> stk;
        vector<array<int, 2>> e;
        for (int i = 1; i <= 2 * n; i++)
        {
            if (pos[i] != 0)
            {
                if (stk.size())
                    e.push_back({stk.back(), pos[i]});
                stk.push_back(pos[i]);
            }
            else
            {
                stk.pop_back();
            }
        }
        int m = e.size();
        cout << m << '\n';
        for (auto [u, v] : e)
            cout << u << ' ' << v << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    string role;
    cin >> role;
    cin >> t;
    while (t--)
        solve(role);
    return 0;
}