#include <bits/stdc++.h>
using namespace std;

// 最短路---单源最短路---有负权边
// 迭代n次，每次遍历所有边{a,b,v},更新d[b]=min(d[b],d[a]+v);
// 在进行n次之后一定有d[b]<=d[a]+v;
// 迭代k次表示经过不超过k条边走到每个点的最短距离;
// 注意：当图中存在负权回路时，最短路不存在;
// bellman-ford算法：时间复杂度O(nm)
const int N = 505, M = 1e4 + 10, INF = 0x3f3f3f3f;
struct edge
{
    int a, b, v;
} e[M];
int n, m, k;
int d[N], back_d[N];
int bellman_ford()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= k; i++)
    {
        memcpy(back_d, d, sizeof(d));//防止串联
        for (int j = 1; j <= m; j++)
        {
            int a = e[j].a, b = e[j].b, v = e[j].v;
            d[b] = min(d[b], back_d[a] + v);
        }
    }
    return d[n];
}
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].v;
    }
    int ans = bellman_ford();
    if (ans > INF / 2)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}