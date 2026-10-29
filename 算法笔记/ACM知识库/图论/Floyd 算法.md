---
tags:
  - acm
  - graph
category: 图论
source:
  - "图论/最短路/Floyd 算法.md"
---

# Floyd 算法

## 模块名称

Floyd 算法

## 来源

- 图论/最短路/Floyd 算法.md

## 适用场景

点数较小的全源最短路、传递闭包、任意两点最短路询问多。

## 核心思想

枚举中转点 k，逐步允许路径经过更多中转点。

## 标准代码模板

### 标准版（推荐）

> 来源：图论/最短路/Floyd 算法.md

## 功能

- 是用来求任意两个结点之间的最短路的。
- 复杂度比较高（时间复杂度是 $O(N^3)$ ![](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7 "O(N^3)")，空间复杂度是 $O(N^2)$），但是常数小，容易实现（只有三个 `for`）。
- 适用于任何图，不管有向无向，边权正负，但是最短路必须存在。（==*不能有个负环*==）

## 实现

定义一个数组$f[k][x][y]$,表示只用节点$1$ 到节点 $k$ 从 $x$ 走到 $y$ 的最短路。
显然$f[n][x][y]$ 为所求的最短路，且我们可以得到它的状态转移为：
$$f[k][x][y]=min(f[k-1][x][y],f[k-1][x][k]+f[k-1][k][y])$$
此时我们可以得到当前做法的空间复杂度为$O(N^3)$ ,因为第一维对结果并没有影响，所以可以省略，于是可以改成：
$$f[x][y]=min(f[x][y],f[k][y])$$ 
## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 205, INF = 0x3f3f3f3f;
int n, m, k;
int d[N][N];
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    Floyd();
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2)
            cout << "impossible" << endl;
        else
            cout << d[a][b] << endl;
    }
    return 0;
}
```


## 例题链接

[洛谷B3647](https://www.luogu.com.cn/problem/B3647)

## 复杂度

时间 O(n^3)，空间 O(n^2)。

## 常见错误

- 三重循环顺序必须 k 在最外层。
- 重边取 min，不可达用 INF/2 判断。

## 相关联知识

[[Johnson 算法]]
[[Dijkstra 算法]]
