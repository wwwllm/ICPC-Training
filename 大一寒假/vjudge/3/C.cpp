#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d, h;
    cin >> n >> d >> h;
    double s = 1.0 * d * h / 2;
    vector<int> y(n);
    double ans = s * n;
    cin >> y[0];
    for (int i = 1; i < n; i++)
    {
        cin >> y[i];
        if (y[i - 1] + h - y[i] > 0)
        {
            ans -=   1.0*d * (y[i - 1] + h - y[i]) * (y[i - 1] + h - y[i]) / (2 * h);
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
