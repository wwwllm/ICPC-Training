---
tags:
  - 图论算法
  - 最短路算法
Time: 2025-09-12T11:36:00
---

## 功能

- Dijkstra 算法是一种求解 **非负权图** 上单源最短路径的算法。
- 朴素Dijkstra 算法的时间复杂度为$O(N^2)$ ,堆优化Dijkstra 算法的时间复杂度为$O(NlogN)$ 

## 实现

将结点分成两个集合：已确定最短路长度的点集（记为 $S$ 集合）的和未确定最短路长度的点集（记为 $T$ 集合）。一开始所有的点都属于 $T$ 集合。

初始化$dis[s]=0$ ,其他点的 $dis$ 均为 $+\infty$ 

然后重复一下操作：
1. 从$T$ 集合中选取一个最短路长度最小的点，移到集合$S$ 中。
2. 在对刚刚被加入$S$ 集合的结点的所有出边执行松弛操作。
直到 $T$ 集合为空，算法结束。

在稀疏图中，$m=O(n)$ ,堆优化般的Dij具有较大优势；而在稠密图中 $m=O(n^2)$则使用朴素方法更优 
## 代码
1. 朴素Dijkstra 算法

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int d[N];
bool st[N];
int dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    for (int i = 1; i <= n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++)
            if(!st[j]&&(t==-1||d[j]<d[t]))
                t = j;
        st[t] = 1;
        for (int i = 1; i <= n;i++){
            d[i] = min(d[t] + g[t][i], d[i]);
        }
    }
    if(d[n]==INF)
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
```

2. 堆优化Dijkstra 算法
```
#include <bits/stdc++.h>
using namespace std;

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
```
## 例题链接

[朴素Dij](https://www.acwing.com/problem/content/851/)
[堆优化Dij](https://www.acwing.com/problem/content/852/)


 