#include <bits/stdc++.h>
using namespace std;

// 朴素版Prim：时间复杂度O(n^2),适合稠密图
//算法流程：1.在已经选过的点以外找一个距离树最小的点。2.在更新距离
const int N = 505,INF=0x3f3f3f3f;
int n, m;
int g[N][N], d[N];
bool st[N];
int prim()
{
    int ans = 0;
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || d[j] < d[t]))
                t = j;
        }
        if (i && d[t] == INF)
            return INF;
        if (i)
            ans += d[t];
        for (int i = 1; i <= n; i++)
            d[i] = min(d[i], g[t][i]);
        st[t] = 1;
    }
    return ans;
}
signed main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int a, b, z;
        cin >> a >> b >> z;
        g[b][a] = g[a][b] = min(z, g[a][b]);
    }
    int t = prim();
    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}