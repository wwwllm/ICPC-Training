#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string x, y;
    cin >> x >> y;
    if (x == "0")
    {
        if (y == "0")
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    bitset<64> a(x), b(y);
    int ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        ans += (a[i] - b[i]) * (1LL << i);
    }
    cout << abs(ans) << '\n';
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