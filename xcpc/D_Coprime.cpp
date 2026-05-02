#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105922
void solve()
{
    int x, y;
    cin >> x >> y;
    for (int i = 1; i < y - x; i++)
    {
        if (gcd(x + i, x) == 1 && gcd(y, x + i) == 1)
        {
            cout << x + i << '\n';
            return;
        }
        if (gcd(y - i, x) == 1 && gcd(y, y - i) == 1)
        {
            cout << y - i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}