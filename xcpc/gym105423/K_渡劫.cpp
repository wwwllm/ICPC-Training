#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105423
const int mod = 998244353, inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> dp(n + 1, {inf, inf});
    map<array<int, 2>, vector<array<int, 3>>> adj;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[{u, 0}].push_back({v, 0, w});
        adj[{u, 0}].push_back({v, 1, 0});
        adj[{u, 1}].push_back({v, 1, w});
        adj[{u, 0}].push_back({u, 1, 0});
        adj[{v, 0}].push_back({u, 0, w});
        adj[{v, 0}].push_back({u, 1, 0});
        adj[{v, 1}].push_back({u, 1, w});
        adj[{v, 0}].push_back({v, 1, 0});
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pq.push({a[i], i, 0}), dp[i][0] = a[i];
    while (pq.size())
    {
        auto [d, u, st] = pq.top();
        pq.pop();
        if (dp[u][st] < d)
            continue;
        for (auto [v, b, w] : adj[{u, st}])
        {
            int cost = d + w;
            if (dp[v][b] > cost)
            {
                dp[v][b] = cost;
                pq.push({cost, v, b});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, min(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}