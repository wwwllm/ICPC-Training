#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector adj(2 * n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n);
        adj[v + n].push_back(u);
        adj[v].push_back(u + n);
        adj[u + n].push_back(v);
    }
    vector<int> dist(2 * n + 1, inf);
    {
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        vector<int> vis(2 * n + 1);
        vis[1] = 0;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (vis[v])
                    continue;
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> ans(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int res1 = inf, res2 = inf;
        if (dist[i + n] != inf && k & 1)
        {
            int c = (dist[i + n] + k - 1) / k;
            if ((c & 1) == 0)
                c++;
            res1 = c * k;
        }
        if (dist[i] != inf)
        {
            int c = (dist[i] + k - 1) / k;
            if ((c & 1) && (k & 1))
                c++;
            res2 = c * k;
        }
        ans[i] = min(res1, res2);
        if (ans[i] == inf)
            ans[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}