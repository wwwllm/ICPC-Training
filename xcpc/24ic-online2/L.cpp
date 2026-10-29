#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int t;
    cin >> t;
    int x = (-1 + sqrt(1 + 8 * t)) / 2;
    long double res = 1e18;
    int d = 0;
    for (int i = max(1LL, x - 5); i <= min(x + 5, t); i++)
    {
        long double tmp = (long double)((i + 1) * i + 2 * (t - i)) * 1.0 / (2 * i);
        if (tmp < res)
        {
            d = i;
            res = tmp;
        }
    }
    int p = (d + 1) * d + 2 * (t - d), q = 2 * d;
    int g = gcd(p, q);
    cout << p / g << ' ' << q / g << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}