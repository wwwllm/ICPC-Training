#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int eps = 1e-9;
int cmp(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
void solve()
{
    int n;
    double k;
    cin >> n >> k;
    vector<int> a(n);
    double p = k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto calc = [&]() -> double
    {
        auto sum = [&](double x) -> double
        {
            double res = 0;
            for (int i = 0; i < n; i++)
            {
                res += (double)a[i] * x / (1 + (double)a[i] * x);
            }
            return res;
        };
        double l = 0, r = 1e9;
        for (int i = 0; i < 100; i++)
        {
            double mid = (l + r) / 2;
            if (cmp(sum(mid) - k) != -1)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    auto x = calc();
    vector<double> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = (double)a[i] * x / (double)(1 + (double)a[i] * x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(12) << ans[i] << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}