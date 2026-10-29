#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int x, y;
    cin >> x >> y;
    int a1, a2, b;
    cin >> a1 >> a2 >> b;
    int p1 = a1 * inv((a1 + a2) % mod) % mod, p2 = a2 * (inv((a1 + a2) % mod)) % mod;
    auto f = [&](auto &&self, int x, int p1, int y, int p2) -> int
    {
        if (y == 0)
            return 1;
        if (x == y)
        {
            return p1;
        }
        if (x > y)
        {
            int k = x / y, r = x % y;
            int p = exp(p2, k);
            int res = p * self(self, r, p1, y, p2) % mod + (1 - p + mod) % mod;
            return (res % mod + mod) % mod;
        }
        else
        {
            return (1 - self(self, y, p2, x, p1) + mod) % mod;
        }
    };
    cout << f(f, x, p1, y, p2) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}