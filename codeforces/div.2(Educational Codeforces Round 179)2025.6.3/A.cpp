#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x;
    cin >> x;
    ll y = x;
    int cnt = 0;
    while (y)
    {
        y >>= 1;
        cnt++;
    }
    cout << 2 * cnt + 1 << '\n';
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