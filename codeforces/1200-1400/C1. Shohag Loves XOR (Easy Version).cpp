#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2039/C1
void solve()
{
    int x, m;
    cin >> x >> m;
    int ans = 0;
    for (int y = 1; y <= min(2 * x, m); y++)
    {
        if (y == x)
            continue;
        int u = x ^ y;
        if (x % u == 0 || y % u == 0)
            ans++;
    }
    cout << ans << '\n';
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