#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c)
        cout << (b > d ? "Yes\n" : "No\n");
    else
        cout << (a > c ? "Yes\n" : "No\n");
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}