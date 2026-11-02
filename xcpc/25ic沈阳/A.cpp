#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    int l = 0, r = LLONG_MAX;
   
    auto check = [&](int x) -> bool
    {
        int cnt = 0;
        for (int d = 1; d < n; d++)
        {
            int r = 2 * a + d * a + 2 * b;
            if (x / d < r)
                break;

            int c = (x / d - 2 * b - d * a) / (2 * a);
            cnt += min(n - d, c);
            if (cnt >= k)
                return true;
        }
        return cnt >= k;
    };
    while (l + 1 != r)
    {
        int mid = (r - l) / 2 + l;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    int g = gcd(r, a);
    cout << r / g << ' ' << a / g << '\n';
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