#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int k = min(x, y);
    if (k == 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << 1 << '\n';
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}