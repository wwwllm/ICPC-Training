#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int k = abs(x - y);
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (k % i == 0)
            ans++;
    }
    if (k == 0)
        ans = 1;
    cout << ans << '\n';
    for (int i = 1; i <= x; i++)
        cout << 1 << ' ';
    for (int i = 1; i <= y; i++)
        cout << -1 << ' ';
    cout << '\n';
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