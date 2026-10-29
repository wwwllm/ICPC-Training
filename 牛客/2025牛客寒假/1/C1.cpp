#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n);
    vector<vector<bool>> b(n, vector<bool>(n, 0));
    for (auto &it : g)
        cin >> it;
    array<int, 2> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto bfs = [&](int i, int j) -> vector<array<int, 2>>
    {
        vector<array<int, 2>> path;
        queue<array<int, 2>> q;
        vector<vector<array<int, 2>>> pre(n, vector<array<int, 2>>(n, {-1, -1}));
        vector<vector<bool>> st(n, vector<bool>(n, 0));
        q.push({i, j});
        st[i][j] = 1;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            if (g[x][y] == '1')
            {
                int xx = x, yy = y;
                while (xx != i || yy != j)
                {
                    path.push_back({xx, yy});
                    auto [dx, dy] = pre[xx][yy];
                    xx = dx, yy = dy;
                }
                path.push_back({i, j});
                break;
            }
            for (auto [dx, dy] : d)
            {
                int xx = dx + x, yy = dy + y;
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && !st[xx][yy] && !b[xx][yy])
                {
                    pre[xx][yy] = {x, y};
                    st[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
        return path;
    };
    int ans = 0;
    vector<array<int, 4>> path;
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
        {
            auto res = bfs(i, j);
            ans += res.size() - 1;
            swap(g[i][j], g[res[0][0]][res[0][1]]);
            b[i][j] = 1;
            for (int i = 0; i < res.size() - 1; i++)
            {
                path.push_back({res[i][0], res[i][1], res[i + 1][0], res[i + 1][1]});
            }
        }
    cout << ans << endl;
    for (auto [x2, y2, x1, y1] : path)
        cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}