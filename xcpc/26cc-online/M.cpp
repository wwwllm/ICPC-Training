#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 4e5;
vector<int> p(N + 1), ivp(N + 1);
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
void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * i % mod;
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
int C(int n, int m)
{
    if (n < 0 || m < 0 || m > n)
        return 0;
    return p[n] * ivp[m] % mod * ivp[n - m] % mod;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }
    ranges::sort(b);
    int res1 = 0;
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == x)
            {
                (res1 += C(n - 1, n - i - 1)) %= mod;
            }
        }
    }
    auto f = [&](int x) -> int
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = ranges::lower_bound(b, x - b[i]) - b.begin();
            if (j <= i)
                j = i + 1;
            if (j >= n)
                continue;
            (res += C(n - j + i, n - j - 1)) %= mod;
        }
        return res;
    };
    int res2 = (f(2 * x) - f(2 * x + 1) + mod) % mod;
    cout << (res1 + res2) % mod << '\n';
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