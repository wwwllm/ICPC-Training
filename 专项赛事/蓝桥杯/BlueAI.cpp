#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
char g[N][N];
int walk[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int dfs(int x, int y)
{
    int ans = 0;
    for (auto [dx, dy] : walk)
    {
        int xx = x + 2 * dx, yy = 2 * dy + y;
        if (xx <= n && xx >= 1 && yy <= n && yy >= 1)
        {
            if (g[xx - dx][yy - dy] == 'Q' && g[xx][yy] == '.')
            {
                g[xx - dx][yy - dy] = '.';
                ans = max(ans, dfs(xx, yy) + 1);
                g[xx - dx][yy - dy] = 'Q';
            }
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == 'L')
            {
                g[i][j] = '.';
                ans = max(ans, dfs(i, j));
                g[i][j] = 'L';
            }
    cout << ans << endl;
    return 0;
}