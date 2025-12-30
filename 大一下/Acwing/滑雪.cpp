#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int g[N][N], dp[N][N], r, c;
int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(int x, int y)
{
    int &v = dp[x][y];
    if (v != -1)
        return v;
    v = 1;
    for (auto [dx, dy] : walk)
    {
        int xx = x + dx, yy = dy + y;
        if (xx >= 1 && xx <= r && yy >= 1 && yy <= c && g[x][y] > g[xx][yy])
        {
            v = max(v, dfs(xx, yy) + 1);
        }
    }
    return v;
}
signed main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> g[i][j];
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}