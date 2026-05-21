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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int op, l, r, m;
    cin >> op >> l >> r >> m;
    vector<int> s(n + 1), k(n + 1);
    int sumk = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + (a[i] == -1 ? 0 : a[i]);
        k[i] = k[i - 1] + (a[i] == -1);
    }
    sum = m - s[r] + s[l - 1];
    if (sum < 0)
    {
        cout << 0 << '\n';
        return;
    }
    sumk = k[r] - k[l - 1];
    int ans = 0;
    if (sumk == 0)
    {
        if (sum != 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                int ss = (s[i] - s[l - 1]) % mod;
                (ans += ss * ss % mod) %= mod;
            }
            cout << ans << '\n';
        }
        return;
    }
    for (int i = l; i <= r; i++)
    {
        int ss = (s[i] - s[l - 1]) % mod;
        int kk = k[i] - k[l - 1];
        int a = C(sumk + sum - 1, sumk - 1);
        int b = kk * C(sumk + sum - 1, sumk) % mod;
        int c = (kk * (kk + 1) % mod * C(sumk + sum - 1, sumk + 1) + kk * C(sumk + sum - 1, sumk) % mod) % mod;
        (ans += (a * ss % mod * ss + 2 * b % mod * ss % mod + c) % mod) %= mod;
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