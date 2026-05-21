#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e6, mod = 998244353;
vector<int> p(N + 1), ivp(N + 1);
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
void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * i % mod;
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
}
int C(int n, int m)
{
    if (m > n || n < 0 || m < 0)
        return 0;
    return p[n] * ivp[m] % mod * ivp[n - m] % mod;
}
void solve()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int ans = 0;
    for (int i = 1; i <= min(x1, x2 + 1); i++)
    {
        (ans += C(x2 + 1, i) * C(x1 - 1, i - 1) % mod * C(x3 + x2 - i, x3) % mod) %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}