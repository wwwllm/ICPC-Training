#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a < d - c)
    {
        cout << a << ' ' << c << endl;
        cout << a << ' ' << c + 1 << endl;
        cout << a + 1 << ' ' << d << endl;
    }
    else
    {
        cout << a << ' ' << d << endl;
        cout << a + 1 << ' ' << d << endl;
        cout << b << ' ' << d - 1 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
