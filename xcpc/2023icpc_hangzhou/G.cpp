#include <bits/stdc++.h>
#define int long long
using namespace std;
using ull = unsigned long long;

const int inf = 1e9;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> g(n + 1, " ");
    vector<array<int, 2>> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i][0] >> a[i][1];
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        g[i] += s;
    }
    vector dis(n + 1, vector<int>(m + 1, inf));
    vector vis(n + 1, vector<int>(m + 1));
    dis[a[0][0]][a[0][1]] = 0;
    for (int i = 1; i < k; i++)
    {
        auto [x, y] = a[i];
        vis[x][y] = k - i;
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, a[0][0], a[0][1]});
    while (pq.size())
    {
        auto [d, x, y] = pq.top();
        pq.pop();
        for (auto [dx, dy] : walk)
        {
            int xx = x + dx, yy = dy + y;
            if (xx <= n && xx >= 1 && yy <= m && yy >= 1 && g[xx][yy] == '.')
            {
                int len = d + 1;
                if (vis[xx][yy] != 0)
                    len = max(vis[xx][yy], d + 1);
                if (dis[xx][yy] > len)
                {
                    dis[xx][yy] = len;
                    pq.push({len, xx, yy});
                }
            }
        }
    }
    ull ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //cerr << dis[i][j] << " \n"[j == m];
            if (dis[i][j] == inf)
                continue;
            ans += (ull)dis[i][j] * dis[i][j];
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