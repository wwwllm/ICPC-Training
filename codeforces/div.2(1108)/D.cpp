#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto calc = [&](int x)
    {
        int res = 1e9;
        for (int k = 0; k < 20; k++)
        {
            int g = (1LL << k);
            int cnt = 0;
            if (x % g == 0)
            {
                cnt = 31 - __builtin_clz(x) + __builtin_popcount(x);
            }
            else
            {
                int xx = (x + g - 1) / g * g;
                cnt = xx - x + 31 - __builtin_clz(xx) + __builtin_popcount(xx);
            }
            if (cnt > res)
                continue;
            res = min(res, cnt);
        }
        return res;
    };
    int ans = 1e18;
    for (int k = 0; k < 20; k++)
    {
        int res = k;
        int g = (1LL << k);
        for (int i = 0; i < n; i++)
        {
            int aa = -1;
            if (a[i] % g == 0)
            {
                aa = a[i];
            }
            else
            {
                aa = (a[i] + g - 1) / g * g;
                res += aa - a[i];
            }
            res += calc(aa);
            res -= k;
            if (res >= ans)
                continue;
        }
        ans = min(ans, res);
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