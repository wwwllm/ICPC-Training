#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b)
    {
        if (a == b + 1 && a & 1)
            cout << y << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    if (y >= x)
    {
        cout << (b - a) * x << '\n';
    }
    else
    {
        int ans = 0;
        if ((a & 1) == (b & 1))
        {
            ans = (b - a) / 2 * (x + y);
        }
        else if (a & 1)
        {
            ans = (b - a) / 2 * (x + y) + x;
        }
        else if (!(a & 1))
        {
            ans = (b - a) / 2 * (x + y) + y;
        }
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
};