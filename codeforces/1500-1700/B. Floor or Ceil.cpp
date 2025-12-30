#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/2082/B
void solve()
{
    ll x, n, m;
    cin >> x >> n >> m;
    ll minx = x, mm = m, nn = n, maxx = x;
    while (mm-- && minx > 1)
    {
        minx = (minx + 1) / 2;
    }
    while (nn-- && minx)
        minx >>= 1;
    nn = n, mm = m;
    while (nn-- && maxx)
        maxx >>= 1;
    while (mm-- && maxx > 1)
        maxx = (maxx + 1) / 2;
    cout << minx << ' ' << maxx << '\n';
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