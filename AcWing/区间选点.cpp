#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50,inf=1e9+50;
struct qujian
{
    int l, r;
} a[maxn];
bool cmp(qujian a, qujian b)
{
    return a.r < b.r;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n, cmp);
    int ans = 0, ch = -inf;
    for (int i = 1; i <= n; i++)
    {
        if (ch >= a[i].l && ch <= a[i].r)
            continue;
        else
        {
            ans++;
            ch = a[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}