#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 100;
int p[105][105], f[105][105];
void dfs(int x, int cnt)
{
    if (cnt >= ans)
        return;
    if (x > n)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int k = 1;
        while (p[i][k] && !f[x][p[i][k]])
            k++;
        if(!p[i][k]){
            p[i][k] = x;
            dfs(x + 1, cnt);
            p[i][k] = 0;
        }
    }
    p[cnt + 1][1] = x;
    dfs(x + 1, cnt + 1);
    p[cnt + 1][1] = 0;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        f[a][b] = 1;
        f[b][a] = 1;
    }
    dfs(1, 1);
    cout << ans << endl;
}
