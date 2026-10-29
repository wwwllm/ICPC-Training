#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int cur = 1500;
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cur += x;
        if (cur >= 4000)
        {
            ans = min(ans, i);
        }
    }
    if (ans == 1e9)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}