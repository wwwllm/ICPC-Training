#include <bits/stdc++.h>
using namespace std;

void solve()
{
    double n;
    cin >> n;
    if (n >= 38.0)
        cout << 1 << endl;
    else if (n >= 37.5)
        cout << 2 << endl;
    else
        cout << 3 << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}