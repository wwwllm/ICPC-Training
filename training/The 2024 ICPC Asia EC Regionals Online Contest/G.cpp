#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = (a * ans) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void calc(int n, int m, int a, int b, int &x, int &y)
{
    if (!m)
    {
        x = 1;
        y = 0;
        return;
    }
    int u, v;
    calc(m, n % m, b, a, u, v);
    int t = exp(b, n / m);
    y =  t * u % mod;
    x = (mod + 1 - t +  t * v) % mod;
}
void solve()
{
    int x, y;
    cin >> x >> y;
    int a, b, c;
    cin >> a >> b >> c;
    int p = 1;
    int p0 = a * exp(a + b, mod - 2) % mod, p1 = b * (exp(a + b, mod - 2)) % mod;
    int ans, tmp;
    calc(x, y, p0, p1, ans, tmp);
    cout << ans << '\n';
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