#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    int ans = 0;
    for (auto &[l, r] : a)
        cin >> l >> r, ans += r + r - l;
    sort(a.begin(), a.end(), [&](array<int, 2> a, array<int, 2> b)
         { return a[0] + a[1] < b[0] + b[1]; });
    if (!(n & 1))
    {
        for (int i = 0; i < n / 2; i++)
            ans -= a[i][0] + a[i][1];
        cout << ans << '\n';
    }
    else
    {
        int res = 0;
        for (int i = 0; i <= n / 2; i++)
            ans -= a[i][0] + a[i][1];
        // cout << ans << '\n';
        for (int i = 0; i < n; i++)
        {
            if (i <= n / 2)
            {
                int tmp = ans + a[i][0];
                res = max(tmp, res);
            }
            else
            {
                int tmp = ans + a[n / 2][1] + a[n / 2][0] - a[i][1];
                res = max(tmp, res);
            }
        }
        cout << res << '\n';
    }
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