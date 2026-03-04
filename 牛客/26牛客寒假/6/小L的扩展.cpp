#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector dis(n + 1, vector<int>(m + 1, inf));
    vector vis(n + 1, vector<int>(m + 1));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push({0, x, y});
        dis[x][y] = 0;
    }
    for (int i = 0; i < b; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        vis[x][y] = t;
    }
    int ans = 0;
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (pq.size())
    {
        auto [t, x, y] = pq.top();
        pq.pop();
        if (t > dis[x][y])
            continue;
        ans = max(t, ans);
        for (auto [dx, dy] : walk)
        {
            int xx = x + dx, yy = y + dy;
            if (!(xx >= 1 && xx <= n && yy >= 1 && yy <= m))
                continue;
            int nt = max(vis[xx][yy], t + 1);
            if (dis[xx][yy] > nt)
            {
                dis[xx][yy] = nt;
                pq.push({nt, xx, yy});
            }
        }
    }
    cout << ans << '\n';
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