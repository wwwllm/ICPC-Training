#include <bits/stdc++.h>
#define int long long
using namespace std;

using ST = pair<array<int, 2>, array<int, 4>>;
void solve()
{
    int n;
    cin >> n;
    vector g(n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cin >> g[i][j];
        }
    }
    vector op(n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++)
    {
        op[i][0] = 1;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            op[i][j] = op[i][j - 1] ^ 1;
        }
    }
    vector<vector<array<int, 2>>> d = {{{1, 1}, {0, 1}, {0, -1}}, {{-1, -1}, {0, -1}, {0, 1}}};
    vector<array<int, 4>> walk = {{0, 1, 2, 3}, {0, 2, 1, 3}, {0, 3, 1, 2}};
    map<ST, int> dist;
    queue<ST> q;
    ST s = {{1, 1}, {4, 2, 3, 1}};
    q.push(s);
    map<ST, int> vis;
    vis[s] = 1;
    int ans = 1e9;
    int tx, ty;
    cin >> tx >> ty;
    while (q.size())
    {
        auto [u, col] = q.front();
        q.pop();
        int x = u[0], y = u[1];
        if (x == tx && y == ty)
        {
            ans = min(ans, dist[{u, col}]);
        }
        for (int i = 0; i < 3; i++)
        {
            int nx = x + d[op[x][y]][i][0], ny = y + d[op[x][y]][i][1];
            auto ncol = col;
            for (auto j : {0, 2})
            {
                swap(ncol[walk[i][j]], ncol[walk[i][j | 1]]);
            }
            ST v = {{nx, ny}, ncol};
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= 2 * nx - 1 && vis.find(v) == vis.end() && ncol[0] == g[nx][ny])
            {
                vis[v] = 1;
                dist[v] = dist[{u, col}] + 1;
                q.push(v);
            }
        }
    }
    if (ans == 1e9)
    {
        cout << -1 << '\n';
    }
    else
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