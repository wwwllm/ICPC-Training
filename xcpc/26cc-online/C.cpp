#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const long double eps = 1e-12, inf = 1e18;
int sign(long double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
void solve()
{
    int w, x1, x2, y, u, v;
    cin >> w >> x1 >> x2 >> y >> u >> v;
    {
        long double t1 = (long double)y / v;
        long double xl = (long double)x1 + (long double)u * t1;
        long double xr = (long double)x2 + (long double)u * t1;
        if (sign(xl * xr) != -1)
        {
            cout << fixed << setprecision(9) << (long double)w / v << '\n';
            return;
        }
    }
    auto calc = [&](int x) -> long double
    {
        long double A = u * u - v * v, B = 2 * x * u, C = y * y + x * x;
        auto f = [&](long double A, long double B, long double C) -> long double
        {
            if (sign(A) == 0)
            {
                if (B == 0)
                    return inf;
                long double t = -C / B;
                if (sign(t) != -1)
                    return t;
                else
                    return inf;
            }
            if (sign(B * B - 4 * A * C) == -1)
                return inf;
            long double t1 = (-B + sqrt(B * B - 4 * A * C)) / (2.0 * A);
            long double t2 = (-B - sqrt(B * B - 4 * A * C)) / (2.0 * A);
            if (sign(t1) == -1 && sign(t2) == -1)
                return inf;
            else if (sign(t1) == -1)
                return t2;
            else if (sign(t2) == -1)
                return t1;
            else
                return min(t1, t2);
        };
        return f(A, B, C) + (long double)(w - y) / v;
    };

    cout << fixed << setprecision(9) << min(calc(x1), calc(x2)) << '\n';
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