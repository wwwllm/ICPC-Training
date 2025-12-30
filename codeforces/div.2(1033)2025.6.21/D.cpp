#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int n = k * (a - 1) + 1;
    n %= mod;
    int c = 1;
    for (int i = 1; i <= a; i++)
    {
        c = c * exp(i, mod - 2) % mod * (i + n - a) % mod;
    }
    int m = k % mod * c % mod * (b - 1) % mod + 1;
    m %= mod;
    cout << n << ' ' << m << '\n';
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