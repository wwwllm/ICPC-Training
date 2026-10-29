#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105945
const int inf = 1e18;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> t(n + 1, inf), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int ti, siz;
        cin >> ti >> siz;
        for (int j = 0; j < siz; j++)
        {
            int id;
            cin >> id;
            t[id] = min(t[id], ti);
        }
    }
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<int> ans(n + 1, inf), val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pq.push({t[i], i, inf});
        if (a[i] == 0)
        {
            pq.push({0, i, 1});
        }
    }
    while (pq.size())
    {
        auto [ti, u, c] = pq.top();
        pq.pop();
        if (ans[u] != inf)
            continue;
        val[u] += c;
        if (val[u] >= a[u])
        {
            ans[u] = ti;
            for (auto [v, w] : adj[u])
            {
                pq.push({ti + w, v, 1});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << (ans[i] >= inf / 2 ? -1 : ans[i]) << " \n"[i == n];
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