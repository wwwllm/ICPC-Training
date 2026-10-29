#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, m, mx;
    cin >> n >> m >> mx;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++)
        cin >> s[i];
    vector<array<int, 2>> dist(n + 1, {inf, inf});
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push({0, s[i]});
            dist[s[i]][0] = 0;
        }
        while (pq.size())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u][d & 1] != d)
                continue;
            for (auto v : adj[u])
            {
                int nd = d + 1;
                if (dist[v][nd & 1] > nd)
                {
                    dist[v][nd & 1] = nd;
                    pq.push({nd, v});
                }
            }
        }
    }
    vector<int> ans;
    {
        queue<array<int, 2>> q;
        vector<array<int, 2>> vis(n + 1);
        vector<array<int, 2>> pre(n + 1);
        q.push({1, 0});
        while (q.size())
        {
            auto [u, d] = q.front();
            q.pop();
            if (u == n)
            {
                int op = d & 1;
                int cur = n;
                while (1)
                {
                    ans.push_back(cur);
                    cur = pre[cur][op];
                    op ^= 1;
                    if (cur == 1 && op == 0)
                    {
                        ans.push_back(1);
                        break;
                    }
                }
                int m = ans.size();
                cout << m - 1 << '\n';
                for (int i = m - 1; i >= 0; i--)
                {
                    cout << ans[i] << " \n"[i == 0];
                }
                return;
            }
            for (auto v : adj[u])
            {
                int nd = d + 1;
                if ((dist[v][nd & 1] > mx || dist[v][nd & 1] > nd) && vis[v][nd & 1] == 0)
                {
                    vis[v][nd & 1] = 1;
                    pre[v][nd & 1] = u;
                    q.push({v, nd});
                }
            }
        }
    }
    cout << -1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}