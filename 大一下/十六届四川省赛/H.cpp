#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 3 == 0)
    {
        cout << 1 << ' ';
        int ans = n / 3;
        cout << ans << endl;
    }
    else
        cout << 0 << ' ' << n / 3 + n % 3 << endl;
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