#include <bits/stdc++.h>
#define int long long
using namespace std;

// 按位贪心：从最高位开始将所有最高位为一的都不取看能否构造一棵生成树
//第k位为1：(x<<k)&1
struct edge
{
    int l, r, v;
};
const int maxn = 2e5 + 50;
edge t[maxn];
int bcj[maxn], n, m, ans=0;
int find(int x)
{
    if (bcj[x] == x)
        return x;
    return bcj[x] = find(bcj[x]);
}
void join(int a, int b)
{
    int roota = find(a), rootb = find(b);
    if (roota != rootb)
    {
        bcj[rootb] = roota;
    }
}
bool f(int k) // 将第k位为0的加到里面
{
    for (int i = 1; i <= n; i++)
        bcj[i] = i;
    for (int i = 1; i <= m; i++)
    {
        if ((t[i].v | ans) >= (ans + ((int)1<< (k + 1))))
            continue;
        if ((t[i].v >> k) & 1)
            continue;
        join(t[i].l, t[i].r);
    }
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != find(1))
            return false;
        }
    return true;
}
void solve()
{
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i].l >> t[i].r >> t[i].v;
    }
    for (int i = 35; i >= 0; i--)
    {
        if (!f(i))
            ans |= ((int)1 << i);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}