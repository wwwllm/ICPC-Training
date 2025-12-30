#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)
    {
        if ((n & 1) == (a & 1) && (n & 1) == (b & 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        if ((n & 1) == (b & 1))
            cout << "YES\n";
        else
            cout << "NO\n";
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