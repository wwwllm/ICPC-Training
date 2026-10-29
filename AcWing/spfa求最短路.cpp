#include <bits/stdc++.h>
using namespace std;

// 最短路---单源最短路---有负权边
// spfa算法：时间复杂度:一般O(m)，最坏O(nm)
// 广搜优化bellman_ford
const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
vector<PII> g[maxn];
int d[maxn];
bool st[maxn];
int spfa()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    st[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = 0;
        for (auto [son, dson] : g[t])
        {
            if (d[son] > d[t] + dson)
            {
                d[son] = d[t] + dson;
                if (!st[son])
                {
                    q.push(son);
                }
            }
        }
    }
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
    int t = spfa();
    if (t >INF/2)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}