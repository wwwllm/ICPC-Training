#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105139
const long double eps = 1e-6, inf = 1e18;
inline int sgn(long double x)
{
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    long double ans = inf;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                auto [x1, y1] = a[i];
                auto [x2, y2] = a[j];
                auto [x3, y3] = a[k];
                long double s = 0.5 * (long double)abs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);
                if (sgn(s) == 0)
                    continue;
                ans = min(ans, s);
            }
        }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
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