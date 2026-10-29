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
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
int GCD(int a, int b, int c, int d)
{
    if (b > d)
    {
        swap(a, c);
        swap(b, d);
    }
    int k = gcd(a, c);
    if (k == 1 || b == 0 || d == 0)
        return 1;
    if (b == 1 && d == 1)
        return k % mod;
    int res = exp(k, min(b, d));
    return res * GCD(a / k, b, k, d - b) % mod;
}
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = GCD(a, b, c, d) % mod;
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