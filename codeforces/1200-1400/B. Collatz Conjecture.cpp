#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1982/B
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    if (x % y == 0)
        x++, k--;
    while (k && x > y)
    {
        int tmp = (x + y - 1) / y * y;
        int cnt = tmp - x;
        if (cnt > k)
        {
            x += k;
            k = 0;
            break;
        }
        x = tmp;
        k -= cnt;
        while (x % y == 0)
            x /= y;
    }
    if (k == 0)
        cout << x << '\n';
    else
    {
        k %= y - 1;
        int ans = x + k;
        if (ans >= y)
            ans -= y - 1;
        cout << ans << '\n';
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