#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r, b, k;
    cin >> l >> r >> b >> k;
    int L = (l + b - 1) / b;
    cout << b * L * k << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}