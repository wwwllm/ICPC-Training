#include <bits/stdc++.h>
using namespace std;

int line[25], col[25];
bool f[25][25];
int n, cnt = 0;
int walk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int path[500];
void dfs(int x, int y, int pos)
{
    if (x == n && y == n && pos == cnt)
    {
        for (int i = 1; i <= cnt; i++)
            cout << path[i] << ' ';
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = x + walk[i][0], dy = y + walk[i][1];
        if (dx <= n && dx >= 1 && dy <= n && dy >= 1 && line[dx] > 0 && col[dy] > 0 && !f[dx][dy])
        {
            line[dx]--, col[dy]--;
            f[dx][dy] = 1;
            path[++pos] = (dy - 1) * n + dx - 1;
            dfs(dx, dy, pos);
            line[dx]++, col[dy]++;
            f[dx][dy] = 0;
            pos--;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> line[i], cnt += line[i];
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    line[1]--, col[1]--, path[1] = 0, f[1][1] = 1;
    dfs(1, 1, 1);
    return 0;
}
