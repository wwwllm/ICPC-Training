#include <bits/stdc++.h>
using namespace std;

// 最短路---单源最短路---所有边权都是正数
// 堆优化Djikstra算法：时间复杂度O(mlogn),适合稀疏图
const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
vector<PII> g[maxn];
int d[maxn];
bool st[maxn];
int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> h;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    h.push({0,1});
    while (h.size())
    {
        auto [dpos, pos] = h.top();
        h.pop();
        if (st[pos])
            continue;
        st[pos] = 1;
        for (auto [son, dson] : g[pos])
        {
            if (d[son] > dpos + dson)
            {
                d[son] = dpos + dson;
                h.push({d[son], son});
            }
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
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    cout << dijkstra() << endl;
    return 0;
}