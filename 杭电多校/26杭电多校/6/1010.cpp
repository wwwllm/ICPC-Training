#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    int n = x + y;
    int m = y + 1;
    int q = n / m;
    int r = n % m;
    cout << (n * n - r * (q + 1) * (q + 1) - (m - r) * q * q) / 2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}