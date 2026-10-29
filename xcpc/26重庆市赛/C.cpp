#include <bits/stdc++.h>
#define int long long
using namespace std;

struct frac
{
    int p, q;
    frac(int p, int q) : p(p), q(q) {};
    bool operator<(const frac &other) const
    {
        return p * other.q < other.p * q;
    };
    int ceil()
    {
        if (q == 0)
            return 0;
        return (p + q - 1) / q;
    }
};
void solve()
{
    int n, lp, lq, rp, rq;
    cin >> n >> lp >> lq >> rp >> rq;
    if (lp >= lq || rp <= rq)
    {
        cout << 0 << '\n';
        return;
    }
    frac l1(rq, rp - rq), l2(lp, lq - lp);
    auto r1 = max(l1.ceil(), l2.ceil());
    l1 = frac(2 * rq, rp - rq), l2 = frac(2 * lp, lq - lp);
    int r = 1 + max(l1.ceil(), l2.ceil());
    r = min(n, r);
    frac rr1(r * rq, rp), rr2(r * lp, lq);
    int r2 = min(rr1.ceil(), rr2.ceil());
    r = max(r1, r2);
    if (r1 + 1 > n)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << max(2LL, n - r + 1) << '\n';
    }
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