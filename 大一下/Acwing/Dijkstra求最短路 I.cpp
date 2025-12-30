#include <bits/stdc++.h>
using namespace std;

// 最短路---单源最短路---所有边权都是正数
//每次找一个之前没算出最短路的中的最短的点t，将t能走向的点中到1的距离重新优化，每次操作可以找到一个点的最短路
// 朴素Djikstra算法：时间复杂度O(n^2),适合稠密图
const int N = 505, M = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int d[N];
bool st[N];
int dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || d[j] < d[t]))
                t = j;
        st[t] = 1;
        for (int i = 1; i <= n; i++)
        {
            d[i] = min(d[t] + g[t][i], d[i]);
        }
    }
    if (d[n] == INF)
        return -1;
    else
        return d[n];
}
signed main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int a, b, z;
        cin >> a >> b >> z;
        g[a][b] = min(z, g[a][b]);
    }
    cout << dijkstra() << endl;
    return 0;
}