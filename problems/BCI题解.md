# B.保护rcx
## 题解

对于从起点 $s(x_0,y_0)$ 到终点 $p(x_1,y_1)$ 的折现，其实就是将终点经过地图边缘对称之后的点与原点连线的线段，我们可以写出终点$p(x_1,y_1)$在经过对称之后的点 $p'$，有两种形式：
- $(2kn+x_1,2km+y_1)$
- $(2kn-x_1),2km-y_1)$
对于每一个从 $s$ 到 $p'$ 的线段我们都取其中点，可以得到中点的坐标的表达形式分别是：
- $(kn+ \frac{x_0+x_1}{2},km+ \frac{y_0+y_1}{2})$
- $(kn+ \frac{x_0-x_1}{2},km+ \frac{y_0-y_1}{2})$
最后将其翻转回原图中，发现每一个点的 $x$ 坐标只有一下 $4$ 中形式：
- $\frac{x_0+x_1}{2}$
- $2n-\frac{x_0+x_1}{2}$
- $abs(\frac{x_0-x_1}{2})$
- $2n-abs(\frac{x_0-x_1}{2})$
同理 $y$ 坐标也只有4中可能。
最后在输出的时候需要保留小数，否则会出现丢精的情况
# 代码
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    array<int, 2> s, t;
    for (int i = 0; i < 2; i++)
        cin >> s[i];
    for (int i = 0; i < 2; i++)
        cin >> t[i];

    if (s == t)
    {
        cout << -1 << '\n';
        return;
    }
    set<int> x, y;
    x.insert((s[0] + t[0]));
    x.insert(2 * n - (s[0] + t[0]));
    x.insert(abs(s[0] - t[0]));
    x.insert(2 * n - abs(s[0] - t[0]));
    y.insert(s[1] + t[1]);
    y.insert(2 * m - (s[1] + t[1]));
    y.insert(abs(s[1] - t[1]));
    y.insert(2 * m - abs(s[1] - t[1]));
    cout << x.size() * y.size() << '\n';
    for (auto xx : x)
    {
        for (auto yy : y)
            cout << fixed << setprecision(9) << (long double)xx / 2.0 << ' ' << (long double)yy / 2.0 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```
# C.集装箱堆放
## 题解

~~看到这个数据范围显然是dp~~，我们定义dp状态为 $dp[i][j]$：为在最底层放了 $i$ 个且总共消耗了 $j$ 个。
我们首先必须把这最底下的 $i$ 个集装箱铺好。接下来，我们要在它上面继续叠放一个宽度为 $v$ 的形状$(1 \le v \le i)$，此时剩下的积木数为 $j-i$ ，在上面叠放宽度为 $v$ 的摆法一共有 $i-v+1$ 种，那么我们就可以得到转移方程：$$dp[i][j] = \sum_{v=1}^{i} (dp[v][j - i] \times (i - v + 1))$$
最终答案就是 $dp[n][m]$。然后使用前缀和优化即可。

我们定义前缀和 $pre[i][j]=\sum_{v=1}^{i} (dp[v][j] \times (i - v + 1))$
那么可以得到转移方程：$$pre[i][j]=\sum_{v=1}^{i} (dp[v][j] \times (i -1- v + 1+1))$$$$\iff pre[i][j]=pre[i-1][j]+\sum_{v=1}^{i} dp[v][j]$$
显然我们在维护一个前缀和数组 $s[i][j]=\sum_{v=1}^{i} dp[v][j]$，就可以解决这个题目了。
最终答案就是 $pre[n][m-n]$。

## 代码
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector pre1(n + 1, vector<int>(m + 1));
    vector pre2(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cur = 0;
            if (i == j)
                cur = 1;
            else if (i > j)
                cur = pre1[j][i - j];

            pre2[j][i] = (pre2[j - 1][i] + cur) % mod;
            pre1[j][i] = (pre1[j - 1][i] + pre2[j][i]) % mod;
        }
    }
    if (n == m)
        cout << 1 << '\n';
    else
        cout << pre1[n][m - n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
```
# I.华尔街之狼2
## 题解

题目中求最大收益，其实就是在求一个固定长度为 $k$ 的最长路，$n$ 的范围很小，也就是说最多使用不到200种状态，用矩阵去表示图，边 $(u,v)$ 的边权为状态 $u$ 到 $v$ 状态改变的收益，直接使用矩阵快速幂去求解最长路就行了。

## 代码
```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r, int val = 0) : n(r), M(r, vector<int>(r, val)) {};
    Mat unit()
    {
        Mat res(n,-inf);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 0;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n, -inf);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] = max(res.M[i][j], M[i][k] + b.M[k][j]);
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " \n"[j == n - 1];
            }
        }
    }
};
Mat exp(Mat a, int b)
{
    Mat ans = Mat(a.n).unit();
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    Mat M(1LL << n, -inf);
    for (int i = 1; i <= m; i++)
    {
        int buy = 0, sell = 0;
        int s;
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int b;
            cin >> b;
            buy |= (1LL << (b - 1));
        }
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            int b;
            cin >> b;
            sell |= (1LL << (b - 1));
        }
        for (int u = 0; u < (1LL << n); u++)
        {
            int v = (u | buy) & (~sell);
            int w = 0;
            for (int bit = 0; bit < n; bit++)
            {
                int ub = (u >> bit) & 1, vb = (v >> bit) & 1;
                if (!ub && vb)
                    w += a[bit];
                else if (ub && !vb)
                    w -= d[bit];
            }
            M.M[u][v] = max(M.M[u][v], w);
        }
    }
    auto res = exp(M, k);
    int ans = -inf;
    for (int b = 0; b < (1LL << n); b++)
    {
        ans = max(ans, res.M[0][b]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
```

