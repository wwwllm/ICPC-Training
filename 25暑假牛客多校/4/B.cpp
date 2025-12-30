#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n + 1);
    vector<vector<int>> st(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = ' ' + g[i];
    }

    const array<int, 2> walk[3] = {{1, 0}, {-1, 0}, {0, 1}};
    auto bfs = [&](int x, int y, int op, int f) -> void
    {
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        queue<array<int, 2>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while (q.size())
        {
            auto [xx, yy] = q.front();
            q.pop();
            st[xx][yy] = op;
            for (auto [dx, dy] : walk)
            {
                int X = xx + dx, Y = yy + dy * f;
                if (X >= 1 && X <= n && Y >= 1 && Y <= m && g[X][Y] == '0' && vis[X][Y] == 0)
                    q.push({X, Y}), vis[X][Y] = 1;
            }
        }
    };
    bfs(1, 1, 1, 1);
    bfs(1, m, 0, -1);
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         cout << st[i][j] << " \n"[j == m];

    auto geth = [&](auto &&self, int x, int y) -> int
    {
        int h = 1;
        st[x][y] = 0;
        for (auto [dx, dy] : walk)
        {
            int xx = dx + x, yy = dy + y;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && st[xx][yy] == 1)
                h = max((abs(yy - y)) + self(self, xx, yy), h);
        }
        return h;
    };

    int h = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (st[j][i] == 1)
                h = max(h, geth(geth, j, i));
        }
    // cout << h << '\n';
    if (h >= k)
        cout << "Yes\n";
    else
        cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}