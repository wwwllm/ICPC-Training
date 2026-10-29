#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double res1 = 0;
    for (int i = 0; i < n; i++)
    {
        res1 += 1.0 / a[i];
    }
    int c = 1;
    ranges::sort(a);
    double sum = 1.0 / a[0];
    double res2 = 1e9;
    for (int i = 1; i < n; i++)
    {
        sum += 1.0 / a[i];
        res2 = min(res2, (i + 1 - sum) / i);
    }
    double ans = (double)w / min(res1, res2);
    cout << fixed << setprecision(10) << ans << '\n';
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