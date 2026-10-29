#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
    int m, r, c;
    cin >> m >> r >> c;
    int k = c / (r + m);
    int x = c % (r + m);
    int T, cnt;
    double res1, res2;
    if (x > m)
    {
        T = k * (r + m) + x;
        cnt = k * m + m;
        res1 = (double)cnt / T;
        T = (k + 1) * (r + m) + m;
        cnt = (k + 2) * m;
        res2 = (double)cnt / T;
    }
    else
    {
        T = k * (r + m) + m;
        cnt = k * m + m;
        res1 = (double)cnt / T;
        T = (k + 1) * (r + m) + m;
        cnt = (k + 2) * m;
        res2 = (double)cnt / T;
    }
    cout << fixed << setprecision(12) << max(res1, res2) << '\n';
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
