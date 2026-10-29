#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int p;
    cin >> p;
    if (p == 2)
    {
        cout << "12 1 71\n";
        return;
    }
    int r = sqrt(p);
    while (r * r < p)
        r++;

    int x1 = r + 1;

    if (x1 % p == 0)
        x1++;

    int q = x1 * x1 - p;
    int x2 = x1 % p;
    cout << x1 << ' ' << x2 << ' ' << q << '\n';
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