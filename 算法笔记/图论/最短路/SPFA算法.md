---
tags:
  - 图论算法
  - 最短路算法
Time: 2025-09-12T14:35:00
---

## 功能

- 同样的SPFA算法也可以判断负环，只需记录最短路经过了多少条边，当经过了至少 $n$ 条边时,说明存在一个负环。
- 大多时候SPFA算法跑得很快，但其最坏情况的时间复杂度可以到达 $O(nm)$ ，==在没有负权边的时候最好还是使用 [[Dijkstra 算法]]==  。

## 实现

[[Bellman–Ford 算法]]中很多时候我们并不需要很多松弛操作，很显然，只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作。因此我们可以用队列维护那些点可能*会引起松弛操作* 就可以只访问必要的边了。
 
## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

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
```
## 例题链接

[spfa求最短路](https://www.acwing.com/problem/content/853/)


 