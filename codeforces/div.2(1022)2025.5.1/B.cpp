#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0)
    {
        cout << -1 << endl;
        return;
    }
    int k = x, cnt = 0;
    while (k)
    {
        k -= lowbit(k);
        cnt++;
    }
    int res = n - cnt;
    if (res <= 0)
    {
        cout << x << endl;
    }
    else
    {
        if (res & 1)
            res++;
        int p = 0, ans = x;
        while (res >= (n - ((x >> p) & 1)) / 2LL * 2LL)
        {
            ans += (1LL << p) * ((n - ((x >> p) & 1)) / 2LL * 2LL);
            res -= (n - ((x >> p) & 1)) / 2LL * 2LL;

            p++;
        }
        ans += (1LL << p) * res;
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}