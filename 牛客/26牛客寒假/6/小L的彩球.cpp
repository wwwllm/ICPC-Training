#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 998244353, N = 1e6;
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
void solve()
{
    int n, x, t;
    cin >> n >> x >> t;
    if (t == 0)
    {
        if (x == 0 || x == n)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }
    auto C = [&](int n, int m) -> int
    {
        if (m < 0 || m > n)
            return 0;
        return p[n] * ivp[m] % mod * ivp[n - m] % mod;
    };
    int ans = 0;
    if (t & 1)
    {
        int k = (t + 1) / 2;
        ans = 2 * C(x - 1, k - 1) % mod * C(n - x - 1, k - 1) % mod;
    }
    else
    {
        int k = (t + 1) / 2;
        ans = C(x - 1, k) * C(n - 1 - x, (k - 1)) % mod + C(x - 1, k - 1) * C(n - x - 1, k) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}