#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto cmp = [&](int x)
    {
        if (x == 1 || x == 0)
            return 0;
        if (x == 2)
            return 1;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
                return 0;
        }
        return 1;
    };
    int l = n / 3;
    int r = (n + 2) / 3 * 2;
    int p = 0;
    for (p = l; p <= r; p++)
    {
        if (cmp(p))
            break;
    }
    int i = p - 1, j = p + 1;
    cout << p << ' ';
    while (i >= 1 || j <= n)
    {
        if (i >= 1)
            cout << i-- << ' ';
        if (j <= n)
            cout << j++ << ' ';
    }
    cout << endl;
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