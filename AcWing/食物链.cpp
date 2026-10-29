#include <bits/stdc++.h>
using namespace std;

// 并查集模板
const int N = 5e4 + 10, M = 1e5 + 10;
int n, bcj[N], k, d[N];
void init()
{
    for (int i = 1; i <= n; i++)
        bcj[i] = i;
}
int find(int x)
{
    if (bcj[x] != x)
    {
        int r = find(bcj[x]);
        d[x] = (d[bcj[x]] + d[x]) % 3;
        return bcj[x] = r;
    }
    return x;
}
void join(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra != rb)
        bcj[rb] = ra;
}
signed main()
{
    cin >> n >> k;
    init();
    int m1 = 0, m2 = 0, ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int D, x, y;
        cin >> D >> x >> y;
        if (x > n || y > n)
            ans++;
        else
        {
            if (x == y && D == 2)
            {
                ans++;
                continue;
            }
            D--;
            int rx = find(x), ry = find(y);
            if (rx == ry)
            {
                if (((d[x] - d[y]) % 3 + 3) % 3 != D)
                    ans++;
            }
            else
            { // 则一定真合并
                bcj[rx] = ry;
                d[rx] = d[y] - d[x] + D;
            }
        }
    }
    cout << ans << endl;
    return 0;
}