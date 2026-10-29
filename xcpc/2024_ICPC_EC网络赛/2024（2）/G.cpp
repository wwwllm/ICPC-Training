#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105358
const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
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
    int a0, a1, b;
    cin >> a0 >> a1 >> b;
    int px = a0 * inv(a0 + a1) % mod, py = a1 * inv(a0 + a1) % mod;
    auto calc = [&](auto &&self, int a, int b, int pa, int pb) -> int
    {
        if (a == 0)
            return 0;
        if (b == 0)
            return 1;
        if (a <= b)
        {
            int t = b / a;
            int p = exp(pa, t) * self(self, a, b % a, pa, pb) % mod;
            return p;
        }
        else
            return (1 - self(self, b, a, pb, pa) + mod) % mod;
    };
    cout << calc(calc, x, y, px, py) << '\n';
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