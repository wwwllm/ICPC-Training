#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

using i128 = __int128;
int exgcd(int a, int b, i128 &x, i128 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
i128 ceil(i128 a, i128 b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    return (a >= 0) ? (a + b - 1) / b : a / b;
}
i128 floor(i128 a, i128 b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    return (a >= 0) ? a / b : (a - b + 1) / b;
}
i128 mmax(i128 x, i128 y)
{
    if (x > y)
        return x;
    else
        return y;
}
void solve()
{
    int N, A, S;
    cin >> N >> A >> S;
    i128 n, a, s;
    n = N, a = A, s = S;
    i128 x, y;
    int g = exgcd(A, S, x, y);
    if (n % g != 0)
    {
        cout << "No\n";
        return;
    }
    i128 b = n / g;
    i128 kx = s / g, ky = a / g;
    i128 bx = b * x, by = b * y;
    i128 l = ceil(-bx, kx), r = floor(by, ky);
    if (l > r)
    {
        cout << "No\n";
        return;
    }
    i128 d = by - bx, k = kx + ky;
    i128 p = floor(d, k);
    i128 c1 = -1, c2 = -1;
    i128 ma = -1;
    auto check = [&](i128 k)
    {
        if (k < l || k > r)
            return;
        i128 cc1 = bx + kx * k, cc2 = by - ky * k;
        i128 maxc = mmax(cc1, cc2);
        if (ma == -1 || maxc < ma)
        {
            ma = maxc;
            c1 = cc1, c2 = cc2;
        }
    };
    check(l);
    check(r);
    check(p + 1);
    check(p - 1);
    check(p);
    cout << "Yes\n";
    cout << (int)c1 << ' ' << (int)c2 << '\n';
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