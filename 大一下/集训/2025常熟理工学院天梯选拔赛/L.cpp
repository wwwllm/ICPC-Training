#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e3 + 10;
int walk[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char g[N][N];
int b[N][N];
bool w[N][N];
PII s, e;
int n, m, k;
void f(int x, int y, int op, int t)
{
    auto [dx, dy] = walk[op - 1];
    int xx = x, yy = y;
    if (t)
    {
        while (xx > 0 && xx < n + 1 && yy > 0 && yy <= m)
        {
            if (g[xx][yy] != '#')
            {
                g[xx][yy] = '*';
                xx += dx, yy += dy;
            }
            else
                break;
        }
    }
    else
    {
        while (xx > 0 && xx < n + 1 && yy > 0 && yy <= m)
        {
            if (g[xx][yy] == '*')
            {
                g[xx][yy] = '.';
                xx += dx, yy += dy;
            }
            else
                break;
        }
    }
}
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'S')
                s = {i, j}, g[i][j] = '.';
            else if (g[i][j] == 'E')
                e = {i, j}, g[i][j] = '.';
        }
    for (int i = 1; i <= k; i++)
    {
        int x, y, op;
        cin >> x >> y >> op;
        b[x][y] = op;
        f(x, y, op, 1);
    }
    queue<PII> q;
    q.push(s);
    w[s.first][s.second] = 1;
    bool flag = 0;
    int ans = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if ((x == e.first) && (y == e.second))
            flag = 1;
        for (auto [dx, dy] : walk)
        {
            int xx = x + dx, yy = y + dy;
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && !w[xx][yy])
                if (g[xx][yy] == '.')
                {
                    q.push({xx, yy});
                    w[xx][yy] = 1;
                }
                else if (g[xx][yy] == '*' && b[xx][yy] != 0)
                {
                    q.push({xx, yy});
                    w[xx][yy] = 1;
                    f(xx, yy, b[xx][yy], 0);
                    ans++;
                }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << ans << endl;
    return 0;
}