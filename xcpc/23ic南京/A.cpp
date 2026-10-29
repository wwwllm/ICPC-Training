#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<char>(m + 1));
    vector vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    vector adj(0, vector<array<int, 2>>());
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector idx(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto &&self, int x, int y, int pos) -> void
    {
        adj[pos].push_back({x, y});
        vis[x][y] = 1;
        idx[x][y] = pos;
        for (auto [dx, dy] : walk)
        {
            int xx = dx + x, yy = dy + y;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && g[xx][yy] == '.' && vis[xx][yy] == 0)
                self(self, xx, yy, pos);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && g[i][j] == '.')
            {
                adj.push_back({});
                int pos = adj.size() - 1;
                dfs(dfs, i, j, pos);
            }
        }
    }
    int ans = 0;
    vector<int> st(adj.size());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '.')
            {
                int pos = idx[i][j];
                if (st[pos] == 1)
                    continue;
                st[pos] = 1;
                vector<array<int, 2>> d;
                for (auto [x, y] : adj[pos])
                {
                    int dx = x - i, dy = y - j;
                    d.push_back({dx, dy});
                }
                bool ok = 1;
                for (int x = 1; x <= n; x++)
                {
                    for (int y = 1; y <= m; y++)
                    {
                        if (g[x][y] == '.' && array<int, 2>{x, y} != array<int, 2>{i, j})
                        {
                            bool f = 0;
                            for (auto [dx, dy] : d)
                            {
                                int xx = x + dx, yy = dy + y;
                                if ((xx < 1 || xx > n || yy < 1 || yy > m) || g[xx][yy] == 'O')
                                    f = 1;
                            }
                            if (!f)
                                ok = 0;
                        }
                    }
                }
                if (ok)
                    ans += adj[pos].size();
            }
        }
    }
    cout << ans << '\n';
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