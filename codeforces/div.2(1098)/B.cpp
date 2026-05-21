#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, x1, x2;
    cin >> n >> x1 >> x2 >> k;
    int len1 = abs(x1 - x2), len2 = abs(n - abs(x1 - x2));
    int ans = k + min(len1, len2);
    if (n <= 3)
    {
        cout << 1 << '\n';
        return;
    }
    cout << ans << '\n';
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