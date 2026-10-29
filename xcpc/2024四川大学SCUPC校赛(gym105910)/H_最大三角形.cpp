#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
void solve()
{
    int x0, x1, y0;
    cin >> x0 >> x1 >> y0;
    y0 = abs(y0);
    double h = 1.0 * y0 / 2;
    double ab = 1.0 * abs(x0 - x1) / 2;
    cout << fixed << setprecision(9) << ab * h / 2 << '\n';
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