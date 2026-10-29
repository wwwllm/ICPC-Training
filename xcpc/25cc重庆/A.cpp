#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector g(N + 1, vector<int>(N + 1));
vector vis(N + 1, vector<array<int, 4>>(N + 1));
void solve()
{
    int n;
    cin >> n;
    array<int, 2> res = {0, 0};
    vector<array<int, 2>> point;
    vector<array<int, 2>> walk = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = i % 2 + 1;
        point.push_back({x, y});

        for (int j = 0; j < 4; j++)
        {
            auto [dx, dy] = walk[j];
            for (int k = 0; k < 5; k++)
            {
                int stx = x - k * dx, sty = y - k * dy;
                if (stx < 1 || stx > N || sty < 1 || sty > N)
                    continue;
                int cnt = 0;
                for (int d = 0; d < 5; d++)
                {
                    int X = stx + d * dx, Y = sty + d * dy;
                    if (X >= 1 && X <= N && Y >= 1 && Y <= N)
                        cnt += g[stx][sty] == g[X][Y];
                }
                if (cnt == 5 && vis[stx][sty][j] == 0)
                {
                    vis[stx][sty][j] = 1;
                    point.push_back({stx, sty});
                    res[i % 2]++;
                }
            }
        }
        cout << res[i % 2] << " \n"[i == n - 1];
    }
    for (auto [x, y] : point)
    {
        g[x][y] = 0;
        vis[x][y] = {0, 0, 0, 0};
    }
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