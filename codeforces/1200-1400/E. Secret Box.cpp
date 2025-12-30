#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1985/E
void solve()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        if (k % i == 0)
        {
            int res = 0, lx = x - i + 1;
            int m = k / i;
            for (int j = 1; j <= min(m, y); j++)
            {
                if (m % j == 0)
                {
                    int ly = max(0LL, y - j + 1), lz = max(0LL, z - m / j + 1);
                    res = max(res, lx * ly * lz);
                }
            }
            ans = max(ans, res);
        }
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