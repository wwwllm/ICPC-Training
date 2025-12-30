#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int nn = min(a, n - a + 1), mm = min(b, m - b + 1);
    int c1 = 1, c2 = 1;
    while (nn != 1)
    {
        c1++;
        nn = (nn + 1) / 2;
    }
    while (mm != 1)
    {
        c2++;
        mm = (mm + 1) / 2;
    }
    int res1 = 0, res2 = 0;
    while (n != 1)
    {
        res1++;
        n = (n + 1) / 2;
    }
    while (m != 1)
    {
        res2++;
        m = (m + 1) / 2;
    }
    cout << min(c1 + res2, c2 + res1) << '\n';
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