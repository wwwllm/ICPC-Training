#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int inf = 1e18;
void solve()
{
    array<int, 5> c;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> c[i];
        sum += c[i];
    }
    int op = sum & 1;
    int l = 5, r = 2e9;
    auto check = [&](int x) -> bool
    {
        int c2 = (sum - 3 * x) / 2;
        if (c2 < 0)
            return 0;
        if ((sum - 3 * x) & 1)
            return 0;
        auto a = c;
        int mx = 0, mi = 0;
        for (int i = 0; i < 5; i++)
        {
            if (a[i] > x)
            {
                int cnt = (a[i] - x + 1) / 2;
                mi += cnt;
            }
            mx += a[i] / 2;
        }
        return c2 >= mi && c2 <= mx;
    };
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid << 1 | op))
            l = mid;
        else
            r = mid;
    }
    int ans = -1;
    if (check(l << 1 | op))
    {
        ans = l << 1 | op;
    }
    for (int i = 0; i <= 10; i++)
    {
        if (check(i))
            ans = max(ans, i);
    }
    if (ans == -1)
    {
        cout << ans << '\n';
    }
    else
    {
        ans = ((sum - ans * 3) >> 1) + ans;
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
