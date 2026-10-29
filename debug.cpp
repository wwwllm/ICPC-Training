#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 200, N = 1e5;
using i128 = __int128;
void solve()
{
    // int l, r;
    // cin >> l >> r;
    // for (int p : {2, 3, 5, 7, 11})
    // {
    //     int mi = (l + p - 1) / p * p;
    //     if (mi % (p - 1) != 0)
    //         continue;
    //     int mx = mi * p / (p - 1);
    //     if (mx <= r)
    //     {
    //         cout << mi << ' ' << mx << '\n';
    //         return;
    //     }
    // }
    // cout << "-1 -1\n";
    auto e = [&](int x) -> int
    {
        int cnt = 0;
        for (int i = 1; i <= x; i++)
        {
            if (gcd(x, i) == 1)
                cnt++;
        }
        return cnt;
    };
    for (int l = 2; l <= 100; l += 2)
    {
        int x = e(l);
        int cnt = 0;
        for (int r = l + 1; r <= 1000; r++)
        {
            if (e(r) == x)
            {
                cout << l << ' ' << r << ' ' << r - l << '\n';
                break;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
