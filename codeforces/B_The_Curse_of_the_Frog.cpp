#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a.begin(), a.end(), [&](array<int, 3> x, array<int, 3> y)
         { return x[0] * (x[1]) - x[2] > y[0] * (y[1]) - y[2]; });
    for (int i = 0; i < n; i++)
    {
        x -= a[i][0] * (a[i][1] - 1);
    }
    if (x <= 0)
    {
        cout << "0\n";
        return;
    }
    int d = a[0][0] * (a[0][1]) - a[0][2];
    if (d <= 0)
    {
        cout << -1 << '\n';
        return;
    }
    int ans = (x + d - 1) / d;
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