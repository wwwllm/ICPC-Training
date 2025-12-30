#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    int ans = 0;
    while (n--)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if (dx == dy && x == y)
            ans++;
        else if (x + y == s)
            ans++;
    }
    cout << ans << '\n';
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