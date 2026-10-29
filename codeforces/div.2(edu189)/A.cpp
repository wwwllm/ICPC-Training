#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int z = (y / x - 1) * x;
    if (y % z == 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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