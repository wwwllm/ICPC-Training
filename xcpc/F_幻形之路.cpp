#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105941
const int inf = 1e9;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    }
    vector vis(n + 1, vector<int>(m + 1));
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto bfs = [&]()
    {
        int sx = n, sy = m;
        queue<array<int, 2>> q;
        vis[sx][sy] = 1;
        q.push({sx, sy});
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : walk)
            {
                int xx = dx + x, yy = dy + y;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == 0 && g[xx][yy] == '.')
                {
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }
    };
    bfs();
    if (vis[1][1] == 1)
    {
        cout << 0 << '\n';
        return;
    }
    vector dis(n + 1, vector<int>(m + 1, inf));
    auto bfs1 = [&]()
    {
        int sx = 1, sy = 1;
        queue<array<int, 2>> q;
        vis[sx][sy] = 2;
        dis[sx][sy] = 0;
        q.push({sx, sy});
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : walk)
            {
                int xx = dx + x, yy = dy + y;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == 0 && g[xx][yy] == '.')
                {
                    q.push({xx, yy});
                    vis[xx][yy] = 2;
                    dis[xx][yy] = 0;
                }
            }
        }
    };
    bfs1();
    queue<array<int, 2>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (dis[i][j] == 0)
                q.push({i, j});
    }
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : walk)
        {
            int xx = dx + x, yy = dy + y;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dis[xx][yy] == inf)
            {
                if (vis[xx][yy] == 1)
                {
                    cout << dis[x][y] << '\n';
                    return;
                }
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}