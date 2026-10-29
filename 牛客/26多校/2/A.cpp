#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6, mod = 998244353;
vector<int> p(N + 1), ivp(N + 1);
inline int exp(int a, int b)
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
inline int inv(int x)
{
    return exp(x, mod - 2);
}
inline void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
inline int C(int n, int m)
{
    if (n < 0 || m < 0 || m > n)
        return 0;
    return p[n] * ivp[m] % mod * ivp[n - m] % mod;
}
void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int k = min(n, m) - 1, d = abs(n - m);
    (p *= inv(q)) %= mod;
    if (n > m)
    {
        p = (1 - p + mod) % mod;
    }
    if (d == 0)
    {
        cout << 2 * (n + m - 1) % mod << '\n';
        return;
    }
    if (k == 0)
    {
        cout << (2 * (n + m - 1) % mod + p * d % mod) % mod << '\n';
        return;
    }
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < d; i++)
    {
        int res = (d - i) * C(k + i - 1, i) % mod * cur % mod;
        (ans += res) %= mod;
        (cur *= (1 - p + mod)) %= mod;
    }
    (ans *= exp(p, k + 1)) %= mod;
    cout << (ans + 2 * (n + m) - 2) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}