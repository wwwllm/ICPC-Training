#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int d = abs(a * a - b * b);
    if (d == 3)
        cout << 1 << '\n';
    else
    {
        int n = (d - 1) / 2;
        n += (d / 4 - 1);
        cout << n << '\n';
    }
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