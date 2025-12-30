#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int k = gcd(x, y);
    int ans = (x + y) / k;
    for (int i = 32; i >= 0; i--)
    {
        if (ans == (1LL << i))
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}