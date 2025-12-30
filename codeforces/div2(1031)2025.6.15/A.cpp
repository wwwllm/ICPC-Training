#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int t = k - max(a, b);
    int cnt = 0, res = 0;
    if (t >= 0)
    {
        cnt = t / min(x, y) + 1, res = 0;
        k -= cnt * min(x, y);
    }
    if (a > b)
    {
        if (k - b >= 0)
            res = (k - b) / y + 1;
    }
    else if (a < b)
    {
        if (k - a >= 0)
            res = (k - a) / x + 1;
    }
    cout << cnt + res << '\n';
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