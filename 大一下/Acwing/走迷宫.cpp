#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int maxn = 105;
int g[maxn][maxn], d[maxn][maxn];
PII walk[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    queue<PII> q;
    q.push({1, 1});
    while (!q.empty())
    {
        auto [x0,y0] = q.front();
        q.pop();
        for (auto [x, y] : walk)
        {
            int xx = x0 + x, yy = y0+ y;
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!g[xx][yy]&&!d[xx][yy]){
                q.push({xx, yy});
                d[xx][yy] = d[x0][y0] + 1;
            }
        }
    }
    cout << d[n][m] << endl;
    return 0;
}