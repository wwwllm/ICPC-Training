#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int p, q;
    cin >> p >> q;
    int k = p + 2 * q;
    for (int n = 1; n <= k / n; n++)
    {
        if ((k - n) % (2 * n + 1) != 0)
            continue;
        int m = (k - n) / (2 * n + 1);
        if (abs(n - m) <= p)
        {
            cout << n << ' ' << m << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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