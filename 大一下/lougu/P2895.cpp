#include <bits/stdc++.h>
using namespace std;

struct dian
{
    int x, y;
};
int p[305][305], walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, w[305][305], ti[305][305];
void f(int x, int y, int t)
{
    if (p[x][y] == -1 || p[x][y] > t)
        p[x][y] = t;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + walk[i][0], yy = y + walk[i][1];
        if (xx >= 0 && yy >= 0 && (p[xx][yy] == -1 || p[xx][yy] > t))
            p[xx][yy] = t;
    }
}
bool cmp(int x,int y,int t){
    if(p[x][y]==-1)
        return x >= 0 && y >= 0 && w[x][y]==0;
    else
        return x >= 0 && y >= 0 && w[x][y]==0 && t < p[x][y];
}
signed main()
{
    int m;
    cin >> m;
    memset(p, -1, sizeof(p));
    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        f(x, y, t);
    }
    queue<dian> q;
    q.push({0, 0});
    w[0][0] = 1;
    while (!q.empty())
    {
        dian d = q.front();
        q.pop();
        if (p[d.x][d.y] == -1)
        {
            cout << ti[d.x][d.y] << endl;
            return 0;
        }
        int t = ti[d.x][d.y] + 1;
        for (int i = 0; i < 4; i++)
        {
            int x = d.x + walk[i][0], y = d.y + walk[i][1];
            if (cmp(x,y,t))
            {
                q.push({x, y});
                w[x][y] = 1;
                ti[x][y] = t;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}