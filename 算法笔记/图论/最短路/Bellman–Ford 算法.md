---
tags:
  - 图论算法
  - 最短路算法
Time: 2025-09-10T18:30:00
---

## 功能

- Bellman–Ford 算法是一种基于松弛（relax）操作的最短路算法，可以求出有负权的图的最短路。（[[Dijkstra 算法]]也会用到松弛操作）
- Bellman–Ford 算法也可以对最短路不存在的情况进行判断。
- Bellman–Ford 算法的时间复杂度是$O(nm)$ 。（它还有一种使用对列优化的算法[[SPFA算法]]）

## 实现

先介绍算法中的松弛操作：
	对于边$(u,v)$ ,松弛操作对应着一下式子：$$dis(v)=min(dis(v),dis(u)+w(u,v))$$
Bellman–Ford 算法所做的，就是不断尝试对图上每一条边进行松弛。我们每进行一轮循环，就对图上所有的边都尝试进行一次松弛操作，当一次循环中没有成功的松弛操作时，算法停止。
每次循环的复杂度为$O(m)$ ，因为一次操作最多会使最短路变数$+1$ ,所以最多进行$n-1$次，那么总的时间复杂度就是$O(nm)$ 。

但还有一种情况，如果从$S$ 点出发，抵达一个负环时，松弛操作会无休止地进行下去。注意到前面的论证中已经说明了，对于最短路存在的图，松弛操作最多只会执行 $n-1$ 轮，因此如果第 $n$ 轮循环时仍然存在能松弛的边，说明从 ![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "S")$S$ 点出发，能够抵达一个负环。

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

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
        memcpy(back_d, d, sizeof(d));
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
```
## 例题链接


 [限制边数的最短路](https://www.acwing.com/activity/content/problem/content/922/) 