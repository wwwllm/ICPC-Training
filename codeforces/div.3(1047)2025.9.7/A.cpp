#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, x;
    cin >> k >> x;
    while (k--)
    {
        x *= 2;
    }
    cout << x << '\n';
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