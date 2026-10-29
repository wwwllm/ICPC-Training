#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    cout << max(x * a, max(y * b, z * c)) << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}