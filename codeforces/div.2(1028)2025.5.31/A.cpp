#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = min(a, c), y = min(b, d);
    //cout << x << ' ' << y << '\n';
    if (x >= y)
        cout << "Gellyfish\n";
    else
        cout << "Flower\n";
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