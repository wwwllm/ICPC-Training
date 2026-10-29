#include <bits/stdc++.h>
using namespace std;

// 最短路---单源最短路---有负权边
// spfa算法：时间复杂度:一般O(m)，最坏O(nm)
// 广搜优化bellman_ford
const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
vector<PII> g[maxn];
int d[maxn], cnt[maxn];
bool st[maxn];
bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)//把所有点加进去，可能有不经过1的负环
    {
        q.push(i);
        st[i] = 1;
    }
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
                cnt[son] = cnt[t] + 1;
                if (!st[son])
                {
                    q.push(son);
                }
                if (cnt[son] >= n)
                    return 1;
            }
        }
    }
    return 0;
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
    cout << (spfa() ? "Yes" : "No") << endl;
    return 0;
}