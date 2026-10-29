#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        cout << "Win\n";
    else if (c > b)
        cout << "WIN\n";
    else
        cout << "nowin\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}