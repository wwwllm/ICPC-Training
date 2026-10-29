#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    double res = 0;
    int cur = n;
    int p = n * (n - 1);
    for (int i = 1; i <= k; i++)
    {
        int q = 2 * (cur + 1) * cur;
        double P = 0.5 + (double)p / q;
        cur++;
        res += P * m;
    }
    cout << fixed << setprecision(10) << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
